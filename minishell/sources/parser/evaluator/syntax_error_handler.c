/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:01:27 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/23 11:07:33 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser/token.h"

static int	is_pipe_last(t_token *token)
{
	if (token->next == NULL && is_pipe_token(token))
	{
		return (1);
	}
	return (0);
}

static int	is_pipe_next_to_pipe(t_token *token)
{
	if (is_pipe_token(token))
	{
		if (is_pipe_token(token->next))
			return (1);
		else if (is_delimiter_token(token->next))
		{
			if (is_pipe_token(token->next->next))
				return (1);
		}
	}
	return (0);
}

int	validate_syntax(t_token *token)
{
	if (token == NULL)
	{
		return (OK);
	}
	if (is_pipe_token(token))
	{
		protected_free(&token->content);
		return (print_serror_and_return_code("|", FAIL));
	}
	while (token != NULL)
	{
		if (is_pipe_last(token))
		{
			protected_free(&token->content);
			return (print_serror_and_return_code("|", FAIL));
		}
		if (is_pipe_next_to_pipe(token))
		{
			protected_free(&token->content);
			return (print_serror_and_return_code("|", FAIL));
		}
		token = token->next;
	}
	return (OK);
}
