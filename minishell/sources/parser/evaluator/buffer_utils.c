/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:33:10 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/21 23:40:41 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser/token.h"
#include "parser/evaluator.h"

char	*append_exit_code_to_buffer(
	t_token *token,
	char **buffer,
	t_data *data
)
{
	char	*exit_code;

	exit_code = get_exit_code(&token->next, data);
	if (exit_code == NULL)
		return (print_merror_and_return_null());
	*buffer = protect_strjoin(*buffer, exit_code);
	protected_free(&exit_code);
	if (token->content == NULL)
		return (print_merror_and_return_null());
	return (*buffer);
}

char	*append_variable_to_buffer(
	t_token *token,
	char **buffer,
	t_data *data
)
{
	char	*expanded_value;

	expanded_value = NULL;
	if (ft_strlen(token->content) == 1 && token->next->type == DOUBLE_QUOTE)
	{
		*buffer = protect_strjoin(*buffer, token->content);
		if (*buffer == NULL)
			return (NULL);
	}
	else
	{
		expanded_value = get_expanded_variable(&token, data);
		if (expanded_value == NULL)
			return (print_merror_and_return_null());
		*buffer = protect_strjoin(*buffer, expanded_value);
		if (*buffer == NULL)
		{
			protected_free(&expanded_value);
			return (NULL);
		}
		protected_free(&expanded_value);
	}
	return (*buffer);
}

char	*append_quoted_token_to_buffer(
	t_token *token,
	char **buffer,
	t_data *data
)
{
	if (is_variable_token(token))
	{
		if (append_variable_to_buffer(token, buffer, data) == NULL)
			return (NULL);
	}
	else if (is_exit_status_token(token))
	{
		if (append_exit_code_to_buffer(token, buffer, data) == NULL)
			return (NULL);
	}
	else
	{
		*buffer = protect_strjoin(*buffer, token->content);
		if (*buffer == NULL)
			return (NULL);
	}
	return ("");
}
