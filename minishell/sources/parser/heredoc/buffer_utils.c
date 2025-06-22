/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:46:28 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 23:43:33 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/heredoc.h"
#include "parser/char_helpers.h"
#include "ft_boolean.h"

static int	add_str_to_buffer_free_helper(
	char **buffer,
	char **str,
	char **temp_str,
	t_bool print_error_msg
)
{
	if (buffer != NULL)
	{
		protected_free(buffer);
	}
	if (str != NULL)
	{
		protected_free(str);
	}
	if (temp_str != NULL)
	{
		protected_free(temp_str);
	}
	if (print_error_msg)
	{
		return (print_merror_and_return_code(EMALLOC));
	}
	return (OK);
}

static int	add_str_to_buffer(char **buffer, char *str)
{
	char	*temp_str;
	char	*temp_buffer;

	temp_str = NULL;
	if (str == NULL)
		return (add_str_to_buffer_free_helper(buffer, &str, &temp_str, TRUE));
	temp_str = ft_strjoin(str, "\n");
	if (temp_str == NULL)
		return (add_str_to_buffer_free_helper(buffer, &str, &temp_str, TRUE));
	temp_buffer = ft_strjoin(*buffer, temp_str);
	if (temp_buffer == NULL)
	{
		protected_free(&temp_str);
		return (add_str_to_buffer_free_helper(buffer, &str, &temp_str, TRUE));
	}
	add_str_to_buffer_free_helper(buffer, &str, &temp_str, FALSE);
	*buffer = ft_strdup(temp_buffer);
	if (*buffer == NULL)
	{
		protected_free(&temp_buffer);
		return (print_merror_and_return_code(EMALLOC));
	}
	protected_free(&temp_buffer);
	return (OK);
}

static int	null_buffers_and_return_code(
	t_executor_data *executor_data,
	int code
)
{
	executor_data->input = NULL;
	executor_data->buffer = NULL;
	return (code);
}

int	update_buffer(
	t_executor_data *executor_data,
	t_data *data
)
{
	if (ft_strcmp(executor_data->input, executor_data->delimiter) == 0)
		return (protected_free(&executor_data->input), BREAK);
	if (is_null_terminator(executor_data->input[0]))
	{
		if (add_str_to_buffer(&executor_data->buffer, ft_strdup("")) == EMALLOC)
		{
			protected_free(&executor_data->input);
			return (print_merror_and_return_code(EMALLOC));
		}
		return (free_and_return_code(&executor_data->input, CONTINUE));
	}
	if (executor_data->token->type == EXPANDABLE_HEREDOC)
	{
		if (is_contain_dollar_symbol(executor_data->input))
		{
			executor_data->input = handle_expansion(executor_data->input, data);
			if (executor_data->input == NULL)
				return (EMALLOC);
		}
	}
	if (add_str_to_buffer(
			&executor_data->buffer, executor_data->input) == EMALLOC)
		return (null_buffers_and_return_code(executor_data, EMALLOC));
	return (OK);
}
