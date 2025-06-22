/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_evaluator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:53:37 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/17 10:09:15 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser/token.h"
#include <unistd.h>
#include "parser/heredoc.h"
#include "parser/evaluator.h"

static char	*concatenate_expandable_tokens(
	t_token *token,
	int tokens_count,
	t_data *data
)
{
	int		i;
	char	*buffer;

	i = 0;
	buffer = ft_strdup("");
	if (buffer == NULL)
		return (NULL);
	token = token->next;
	while (i < tokens_count)
	{
		if (append_quoted_token_to_buffer(token, &buffer, data) == NULL)
		{
			return (NULL);
		}
		i++;
		token = token->next;
	}
	return (buffer);
}

char	*concatenate_non_expandable_tokens(
	t_token *token,
	int tokens_count,
	t_data *data
)
{
	int		i;
	char	*buffer;

	i = 0;
	(void) data;
	buffer = ft_strdup("");
	if (buffer == NULL)
	{
		return (NULL);
	}
	token = token->next;
	while (i < tokens_count)
	{
		buffer = protect_strjoin(buffer, token->content);
		if (buffer == NULL)
		{
			return (NULL);
		}
		i++;
		token = token->next;
	}
	return (buffer);
}

int	process_quotes(
	t_token *token,
	int is_next,
	t_data *data
)
{
	char	*buffer;
	int		res_code;
	t_token	*token_to_process;
	char	*(*concatenator)(t_token *token, int tokens_count, t_data *data);

	if (is_next)
		token_to_process = token->next;
	else
		token_to_process = token;
	if (token_to_process->type == SINGLE_QUOTE)
		concatenator = &concatenate_non_expandable_tokens;
	else
		concatenator = &concatenate_expandable_tokens;
	res_code = handle_quoted_tokens
		(&token_to_process, concatenator, &buffer, data);
	if (res_code == EMALLOC || res_code == FAIL)
		return (res_code);
	token->content = protect_strjoin(token->content, buffer);
	if (token->content == NULL)
	{
		protected_free(&buffer);
		return (print_merror_and_return_code(EMALLOC));
	}
	protected_free(&buffer);
	return (OK);
}

int	check_tokens_count(
	t_token *token,
	char **buffer,
	int tokens_count
)
{
	if (tokens_count == 0)
	{
		(*buffer) = handle_empty_quotes(token);
		if ((*buffer) == NULL)
			return (EMALLOC);
		return (OK);
	}
	else if (tokens_count < 0)
		return (FAIL);
	return (CONTINUE);
}

int	handle_unclosed_quotes_heredoc(
	char **buffer,
	t_token *token
)
{
	(*buffer) = NULL;
	protected_free(&token->content);
	ft_putendl_fd("minishell: unclosed quotation mark", STDERR_FILENO);
	return (FAIL);
}
