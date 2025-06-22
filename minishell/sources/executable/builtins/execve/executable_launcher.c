/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executable_launcher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:41:16 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/25 14:00:19 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd/exec_cmd.h"

static int	try_redirect(
	t_command *command
)
{
	if (command->redirections && redirect(command->redirections, FALSE))
	{
		save_and_reset_dup(TRUE);
		return (1);
	}
	return (0);
}

static int	fork_process(
	t_command *command,
	t_data *data,
	t_pipe *pipes,
	char *pathname
)
{
	int		return_code;

	return_code = fork();
	if (return_code == 0)
	{
		exec_cmd_in_child(command, pipes, pathname, data);
	}
	else if (return_code == -1)
	{
		return_code = 2;
		ft_dprintf(STDOUT_FILENO,
			"minishell: Cannot fork: %s\n", strerror(errno));
	}
	return (return_code);
}

int	exec_cmd(
	t_command *command,
	t_pipe *pipes,
	t_data *data
)
{
	char	*pathname;
	int		return_code;
	int		builtin_num;

	builtin_num = NO_BUILTIN;
	pathname = NULL;
	return_code = 0;
	save_and_reset_dup(FALSE);
	if (try_redirect(command) == 1)
		return (1);
	return_code = handle_command_arguments(command->arguments,
			data, &builtin_num, &pathname);
	if (return_code != 0)
		return (save_and_reset_dup(TRUE), return_code);
	return_code = try_exec_in_parent(command, data, pipes);
	if (return_code != -42)
		return (save_and_reset_dup(TRUE), return_code);
	return_code = fork_process(command, data, pipes, pathname);
	free_after_get_executable_pathname(&data->argv, &pathname);
	save_and_reset_dup(TRUE);
	return (data->argv = NULL, return_code);
}
