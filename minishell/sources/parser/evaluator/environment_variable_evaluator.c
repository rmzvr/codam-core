/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_variable_evaluator.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:47:23 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/21 23:43:33 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser/token.h"
#include "parser/tokenizer.h"
#include "parser/evaluator.h"
#include "parser/char_helpers.h"

static int	tokenize_expanded_variable(
	t_token **tokens,
	char *input
)
{
	size_t			str_len;
	t_state_data	tokenizer;

	str_len = ft_strlen(input);
	initialize_tokenizer(&tokenizer);
	if (str_len > 0)
	{
		tokenizer.buffer = ft_strdup("");
		if (tokenizer.buffer == NULL)
			return (print_merror_and_return_code(EMALLOC));
	}
	while (tokenizer.i < str_len)
	{
		if (handle_evaluator_intermediate_state(&tokenizer.state,
				&tokenizer.buffer, &tokenizer.i, input) == EMALLOC)
			return (EMALLOC);
		if (is_evaluator_accept_state(tokenizer.state))
		{
			if (handle_accept_state(
					&tokenizer.state, &tokenizer.buffer, tokens) == EMALLOC)
				return (EMALLOC);
		}
	}
	protected_free(&tokenizer.buffer);
	return (OK);
}

static int	handle_empty_expanded_variable(
	t_token *token
)
{
	protected_free(&token->content);
	token->content = ft_strdup("");
	if (token->content == NULL)
	{
		return (print_merror_and_return_code(EMALLOC));
	}
	token->type = NONE;
	return (CONTINUE);
}

static void	append_expanded_tokens_to_list(
	t_token *token,
	t_token *expanded_tokens
)
{
	while (expanded_tokens != NULL)
	{
		append_next_token(token, expanded_tokens);
		expanded_tokens = expanded_tokens->next;
		token = token->next;
	}
}

static int	process_tokenized_variable(
	t_token *token,
	char *buffer,
	int is_next
)
{
	t_token	*expanded_tokens;

	expanded_tokens = NULL;
	if (tokenize_expanded_variable(&expanded_tokens, buffer) == EMALLOC)
		return (protected_free(&buffer), EMALLOC);
	if (is_next && is_delimiter_token(expanded_tokens))
	{
		append_expanded_tokens_to_list(token, expanded_tokens);
		free_tokens_and_return_code(&expanded_tokens, BREAK);
	}
	if (!is_next)
		protected_free(&token->content);
	token->content = protect_strjoin(token->content, expanded_tokens->content);
	if (token->content == NULL)
	{
		free_tokens(&expanded_tokens);
		return (protected_free(&buffer), print_merror_and_return_code(EMALLOC));
	}
	if (is_next)
		delete_next_token(token);
	else
		token->type = expanded_tokens->type;
	append_expanded_tokens_to_list(token, expanded_tokens->next);
	free_tokens(&expanded_tokens);
	return (free_and_return_code(&buffer, CONTINUE));
}

int	process_environment_variable(
	t_token *token,
	int is_next,
	t_data *data
)
{
	char	*buffer;
	t_token	*token_to_process;

	if (is_next)
		token_to_process = token->next;
	else
		token_to_process = token;
	buffer = get_expanded_variable(&token_to_process, data);
	if (buffer == NULL)
		return (EMALLOC);
	else if (is_null_terminator(buffer[0]))
	{
		if (handle_empty_expanded_variable(token_to_process) == EMALLOC)
			return (free_and_return_code(&buffer, EMALLOC));
		else
			return (free_and_return_code(&buffer, CONTINUE));
	}
	return (process_tokenized_variable(token, buffer, is_next));
}
