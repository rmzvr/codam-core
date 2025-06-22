/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:41:09 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/22 15:11:37 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/token.h"
#include "utils.h"
#include "parser/buffer_utils.h"
#include "parser/evaluator.h"
#include "parser/tokenizer.h"
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
		if (handle_heredoc_intermediate_state(&tokenizer.state,
				&tokenizer.buffer, &tokenizer.i, input) == EMALLOC)
			return (EMALLOC);
		if (is_heredoc_accept_state(tokenizer.state))
		{
			if (handle_accept_state(
					&tokenizer.state, &tokenizer.buffer, tokens) == EMALLOC)
				return (EMALLOC);
		}
	}
	protected_free(&tokenizer.buffer);
	return (OK);
}

static int	process_next_expandable_tokens(
	t_token *token,
	t_data *data
)
{
	char	*buffer;

	buffer = NULL;
	if (is_variable_token(token->next))
	{
		buffer = get_expanded_variable(&token->next, data);
		if (buffer == NULL)
			return (EMALLOC);
		token->content = protect_strjoin(token->content, buffer);
		if (token->content == NULL)
			return (protected_free(&buffer), ft_putendl_fd(MEMERR, 2), EMALLOC);
		protected_free(&buffer);
	}
	else if (is_exit_status_token(token->next))
	{
		buffer = get_exit_code(&token->next, data);
		if (buffer == NULL)
			return (print_merror_and_return_code(EMALLOC));
		token->content = protect_strjoin(token->content, buffer);
		if (token->content == NULL)
			return (protected_free(&buffer), ft_putendl_fd(MEMERR, 2), EMALLOC);
		protected_free(&buffer);
	}
	return (OK);
}

static int	concatenate_next_heredoc_tokens(
	t_token **tokens,
	t_data *data
)
{
	t_token	*token;

	token = *tokens;
	while (token->next != NULL)
	{
		if (is_variable_token(token->next)
			|| is_exit_status_token(token->next))
		{
			if (process_next_expandable_tokens(token, data) == EMALLOC)
				return (EMALLOC);
		}
		else
		{
			token->content = protect_strjoin(
					token->content, token->next->content);
			if (token->content == NULL)
				return (print_merror_and_return_code(EMALLOC));
		}
		token->type = STRING;
		delete_next_token(token);
	}
	return (OK);
}

static int	concatenate_heredoc_tokens(t_token **tokens, t_data *data)
{
	t_token	*token;

	token = *tokens;
	while (token != NULL)
	{
		if (is_variable_token(token))
		{
			token->content = get_expanded_variable(&token, data);
			if (token->content == NULL)
				return (free_tokens(&token), EMALLOC);
		}
		else if (is_exit_status_token(token))
		{
			token->content = get_exit_code(&token, data);
			if (token->content == NULL)
				return (print_merror_and_return_code(EMALLOC));
		}
		token->type = STRING;
		if (concatenate_next_heredoc_tokens(&token, data) == EMALLOC)
			return (free_tokens(&token), EMALLOC);
		token = token->next;
	}
	return (OK);
}

char	*handle_expansion(char *input, t_data *data)
{
	char	*buffer;
	t_token	*tokens;

	buffer = NULL;
	tokens = NULL;
	if (tokenize_expanded_variable(&tokens, input) == EMALLOC)
	{
		protected_free(&input);
		return (NULL);
	}
	if (concatenate_heredoc_tokens(&tokens, data) == EMALLOC)
	{
		protected_free(&input);
		return (NULL);
	}
	buffer = ft_strdup(tokens->content);
	if (buffer == NULL)
	{
		protected_free(&input);
		return (print_merror_and_return_null());
	}
	free_tokens(&tokens);
	protected_free(&input);
	return (buffer);
}
