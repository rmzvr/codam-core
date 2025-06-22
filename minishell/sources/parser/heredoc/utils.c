/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:19:06 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/25 11:56:17 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "parser/heredoc.h"
#include "ft_boolean.h"
#include "parser/char_helpers.h"

int	is_contain_dollar_symbol(char *input)
{
	int	i;

	i = 0;
	while (!is_null_terminator(input[i]))
	{
		if (input[i] == '$')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	free_heredoc_data(
	t_executor_data *executor_data,
	t_bool print_error_msg
)
{
	if (executor_data->input != NULL)
	{
		protected_free(&executor_data->input);
	}
	if (executor_data->buffer != NULL)
	{
		protected_free(&executor_data->buffer);
	}
	if (executor_data->delimiter != NULL)
	{
		protected_free(&executor_data->delimiter);
	}
	if (executor_data->filepath != NULL)
	{
		protected_free(&executor_data->filepath);
	}
	if (executor_data->token->content != NULL)
	{
		protected_free(&executor_data->token->content);
	}
	if (print_error_msg)
	{
		return (print_merror_and_return_code(EMALLOC));
	}
	return (OK);
}

void	initialize_executor_data(
	t_executor_data *executor_data,
	t_data *data
)
{
	executor_data->read_fd = -1;
	executor_data->write_fd = -1;
	executor_data->input = NULL;
	executor_data->buffer = NULL;
	executor_data->filepath = NULL;
	executor_data->delimiter = NULL;
	executor_data->token = data->tokens;
	executor_data->starting_line = data->count_lines;
}

void	show_heredoc_warning(size_t line, char *delimiter)
{
	ft_dprintf(STDOUT_FILENO, "minishell: warning: here-document at "
		"line %d delimited by end-of-file "
		"(wanted `%s')\n", line, delimiter);
}
