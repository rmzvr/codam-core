/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_concatenator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:35:27 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/02 11:35:52 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser/heredoc.h"
#include "parser/tokenizer.h"
#include "parser/evaluator.h"
#include "parser/char_helpers.h"

static int	process_next_concatenable_tokens(
	t_token *token,
	t_data *data
)
{
	if (is_string_token(token->next))
	{
		token->content = protect_strjoin(
				token->content, token->next->content);
		if (token->content == NULL)
			return (print_merror_and_return_code(EMALLOC));
	}
	else if (is_variable_token(token->next))
	{
		return (process_environment_variable(token, NEXT_TOKEN, data));
	}
	else if (is_exit_status_token(token->next))
	{
		return (process_exit_code(token, NEXT_TOKEN, data));
	}
	else if (is_quote_token(token->next))
	{
		return (process_quotes(token, NEXT_TOKEN, data));
	}
	return (OK);
}

static int	concatenate_next_tokens(
	t_token *token,
	t_data *data
)
{
	int		return_code;

	return_code = 0;
	while (token->next != NULL && !is_delimiter_token(token->next))
	{
		if (is_unexpected_token(token->next))
			return (OK);
		return_code = process_next_concatenable_tokens(token, data);
		if (return_code == BREAK)
			break ;
		else if (return_code == CONTINUE)
			continue ;
		else if (return_code == EMALLOC || return_code == FAIL)
			return (return_code);
		token->type = STRING;
		delete_next_token(token);
	}
	return (OK);
}

static int	process_concatenable_tokens(
	t_token *token,
	t_data *data
)
{
	if (is_variable_token(token))
	{
		return (process_environment_variable(token, CURRENT_TOKEN, data));
	}
	else if (is_exit_status_token(token))
	{
		return (process_exit_code(token, CURRENT_TOKEN, data));
	}
	else if (is_quote_token(token))
	{
		return (process_quotes(token, CURRENT_TOKEN, data));
	}
	return (OK);
}

int	concatenate_tokens(
	t_data *data
)
{
	t_token	*token;
	int		return_code;

	return_code = OK;
	token = data->tokens;
	while (token != NULL)
	{
		if (is_concatenable_token(token))
		{
			return_code = process_concatenable_tokens(token, data);
			if (return_code == CONTINUE)
				continue ;
			else if (return_code == EMALLOC || return_code == FAIL)
				return (return_code);
			token->type = STRING;
			return_code = concatenate_next_tokens(token, data);
			if (return_code == EMALLOC || return_code == FAIL)
				return (return_code);
		}
		token = token->next;
	}
	return (OK);
}
