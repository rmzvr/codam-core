/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_evaluator_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:08:04 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 23:40:41 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/token.h"
#include "utils.h"
#include "parser/evaluator.h"

static int	is_quote_tokens_unclosed(
	t_token *token,
	t_token_type quote_type
)
{
	while (token->next != NULL)
	{
		if (token->next->type == quote_type)
		{
			return (0);
		}
		token = token->next;
	}
	return (1);
}

static int	get_quoted_tokens_count(
	t_token *token,
	t_token_type quote_type
)
{
	int	tokens_count;

	tokens_count = -1;
	while (token->next != NULL)
	{
		tokens_count++;
		if (token->next->type == quote_type)
		{
			break ;
		}
		token = token->next;
	}
	return (tokens_count);
}

char	*handle_empty_quotes(t_token *token)
{
	char	*buffer;

	buffer = ft_strdup("");
	if (buffer == NULL)
		return (print_merror_and_return_null());
	protected_free(&token->content);
	delete_next_token(token);
	return (buffer);
}

static char	*concatenate_tokens_to_buffer(
	t_token *token,
	int tokens_count,
	char *(*concatenator)(
		t_token *token,
		int tokens_count,
		t_data *data
	),
	t_data *data
)
{
	int		i;
	char	*buffer;

	i = 0;
	protected_free(&token->content);
	buffer = concatenator(token, tokens_count, data);
	if (buffer == NULL)
		return (print_merror_and_return_null());
	while (i <= tokens_count)
	{
		delete_next_token(token);
		i++;
	}
	return (buffer);
}

int	handle_quoted_tokens(
	t_token **tokens,
	char *(*concatenator)(
		t_token *token,
		int tokens_count,
		t_data *data
	),
	char **buffer,
	t_data *data
)
{
	t_token			*token;
	t_token_type	quote_type;
	int				tokens_count;
	int				return_code;

	token = *tokens;
	quote_type = token->type;
	if (is_quote_tokens_unclosed(token, quote_type))
		return (handle_unclosed_quotes_heredoc(buffer, token));
	tokens_count = get_quoted_tokens_count(token, quote_type);
	return_code = check_tokens_count(token, buffer, tokens_count);
	if (return_code != CONTINUE)
		return (return_code);
	(*buffer) = concatenate_tokens_to_buffer(
			token, tokens_count, concatenator, data);
	if ((*buffer) == NULL)
		return (EMALLOC);
	return (OK);
}
