/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiter_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:10:47 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 23:38:54 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser/heredoc.h"
#include "parser/evaluator.h"

static int	process_heredoc_delimiter_quotes(
	t_token *token,
	int is_next
)
{
	int		res_code;
	char	*buffer;
	t_token	*token_to_process;

	if (is_next)
		token_to_process = token->next;
	else
		token_to_process = token;
	res_code = handle_quoted_tokens(&token_to_process,
			&concatenate_non_expandable_tokens, &buffer, NULL);
	if (res_code == EMALLOC || res_code == FAIL)
		return (res_code);
	token->content = protect_strjoin(token->content, buffer);
	if (token->content == NULL)
	{
		protected_free(&buffer);
		return (print_merror_and_return_code(EMALLOC));
	}
	token->type = NON_EXPANDABLE_HEREDOC_DELIMITER;
	protected_free(&buffer);
	return (OK);
}

static int	concatenate_next_tokens_to_heredoc_delimiter(
	t_token **tokens
)
{
	t_token	*token;
	int		return_code;

	token = *tokens;
	while (token->next != NULL && !is_delimiter_token(token->next))
	{
		if (is_unexpected_token(token->next))
			return (OK);
		if (is_quote_token(token->next))
		{
			return_code = process_heredoc_delimiter_quotes(token, NEXT_TOKEN);
			if (return_code == EMALLOC || return_code == FAIL)
				return (return_code);
		}
		else
		{
			token->content = protect_strjoin(
					token->content, token->next->content);
			if (token->content == NULL)
				return (print_merror_and_return_code(EMALLOC));
		}
		delete_next_token(token);
	}
	return (OK);
}

static int	handle_concatenatable_tokens(
	t_token *token
)
{
	int	return_code;

	return_code = 0;
	if (is_quote_token(token))
	{
		return_code = process_heredoc_delimiter_quotes(
				token, CURRENT_TOKEN);
		if (return_code == EMALLOC || return_code == FAIL)
			return (return_code);
	}
	else
		token->type = EXPANDABLE_HEREDOC_DELIMITER;
	return_code = concatenate_next_tokens_to_heredoc_delimiter(&token);
	if (return_code == EMALLOC || return_code == FAIL)
		return (return_code);
	return (OK);
}

int	concatenate_tokens_to_heredoc_delimiter(
	t_token **tokens
)
{
	t_token	*token;
	int		return_code;

	token = *tokens;
	while (token != NULL)
	{
		if (is_concatenable_token(token))
		{
			return_code = handle_concatenatable_tokens(token);
			if (return_code == EMALLOC || return_code == FAIL)
			{
				return (return_code);
			}
		}
		else
			return (OK);
		token = token->next;
	}
	return (OK);
}
