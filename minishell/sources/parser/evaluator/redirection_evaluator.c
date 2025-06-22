/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_evaluator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:18:12 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/21 23:40:41 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/token.h"
#include "utils.h"
#include "parser/evaluator.h"

static void	set_heredoc_token_type(t_token *token)
{
	if (token->next->type == NON_EXPANDABLE_HEREDOC_DELIMITER)
	{
		token->type = NON_EXPANDABLE_HEREDOC;
	}
	else if (token->next->type == EXPANDABLE_HEREDOC_DELIMITER)
	{
		token->type = EXPANDABLE_HEREDOC;
	}
}

static void	delete_next_delimiter_token(t_token *token)
{
	if (is_delimiter_token(token->next))
	{
		delete_next_token(token);
	}
}

int	evaluate_redirection_tokens(t_token *token)
{
	while (token != NULL)
	{
		if (is_redirection_token(token))
		{
			if (token->next == NULL)
				return (print_serror_and_return_code("newline", FAIL));
			delete_next_delimiter_token(token);
			if (is_redirection_parameter(token->next))
			{
				protected_free(&token->content);
				token->content = ft_strdup(token->next->content);
				if (token->content == NULL)
					return (print_merror_and_return_code(EMALLOC));
				if (token->type == DLESS)
					set_heredoc_token_type(token);
				delete_next_token(token);
			}
			else if (is_unexpected_token(token->next))
				return (print_serror_and_return_code(
						token->next->content, FAIL));
		}
		token = token->next;
	}
	return (OK);
}
