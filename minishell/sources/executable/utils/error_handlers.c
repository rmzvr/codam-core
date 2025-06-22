/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:09:41 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/25 14:01:09 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "exec_cmd/exec_cmd.h"

int	show_executable_error_msg_notty(t_data *data)
{
	int	return_code;

	return_code = 0;
	if (errno == ENOENT)
	{
		if (ft_strchr(data->argv[0], '/') != NULL)
			ft_dprintf(STDERR_FILENO, "minishell: line %d: %s: %s\n",
				data->argv[0], data->count_lines, strerror(errno));
		else
			ft_dprintf(STDERR_FILENO,
				"minishell: line %d: %s: command not found\n",
				data->count_lines, data->argv[0]);
		return_code = 127;
	}
	else if (errno != 0)
	{
		ft_dprintf(STDERR_FILENO,
			"minishell: line %d: %s: %s\n", data->count_lines,
			data->argv[0], strerror(errno));
		return_code = 126;
	}
	return (return_code);
}

int	show_executable_error_msg(t_data *data)
{
	int	return_code;

	return_code = 0;
	if (data->isatty == FALSE)
		show_executable_error_msg_notty(data);
	if (errno == ENOENT)
	{
		if (ft_strchr(data->argv[0], '/') != NULL)
			ft_dprintf(STDERR_FILENO,
				"minishell: %s: %s\n", data->argv[0], strerror(errno));
		else
			ft_dprintf(STDERR_FILENO,
				"%s: command not found\n", data->argv[0]);
		return_code = 127;
	}
	else if (errno != 0)
	{
		ft_dprintf(STDERR_FILENO,
			"minishell: %s: %s\n", data->argv[0], strerror(errno));
		return_code = 126;
	}
	return (return_code);
}

void	exit_handle_error_file(char *str, char *error_msg)
{
	ft_dprintf(STDERR_FILENO, "minishell: exit: %s: %s\n", str, error_msg);
}

void	exit_handle_error(char *error_msg)
{
	ft_dprintf(STDERR_FILENO, "minishell: exit: %s\n", error_msg);
}

void	handle_error_file(const char *filename)
{
	char	*str;

	str = strerror(errno);
	ft_dprintf(STDERR_FILENO, "minishell: %s: %s\n", filename, str);
}
