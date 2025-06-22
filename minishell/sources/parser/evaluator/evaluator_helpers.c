/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluator_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:12:06 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/21 23:43:33 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/evaluator.h"
#include "parser/char_helpers.h"
#include "builtins/env/env_utils.h"

char	*get_expanded_variable(
	t_token **current_token,
	t_data *data
)
{
	t_token	*token;
	char	*buffer;
	char	*variable_name;
	char	*expanded_value;

	buffer = NULL;
	token = *current_token;
	variable_name = token->content + 1;
	expanded_value = ft_strdup("");
	if (expanded_value == NULL)
	{
		free(token->content);
		return (print_merror_and_return_null());
	}
	if (is_null_terminator(*variable_name))
		return (free_and_return_value(&token->content, expanded_value));
	buffer = ft_getenv(data->envp, variable_name);
	if (buffer == NULL)
		return (free_and_return_value(&token->content, expanded_value));
	protected_free(&expanded_value);
	expanded_value = ft_strdup(buffer);
	if (expanded_value == NULL)
		return (free(token->content), print_merror_and_return_null());
	return (free_and_return_value(&token->content, expanded_value));
}

char	*get_exit_code(
	t_token **current_token,
	t_data *data
)
{
	t_token	*token;
	char	*exit_code;

	token = *current_token;
	exit_code = ft_itoa(data->last_exit_code);
	if (exit_code == NULL)
		return (NULL);
	protected_free(&token->content);
	return (exit_code);
}
