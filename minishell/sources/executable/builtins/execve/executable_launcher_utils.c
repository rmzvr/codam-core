/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executable_launcher_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:43:24 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/24 20:33:17 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd/exec_cmd.h"

static int	configure_pipes(
	t_pipe *pipes
)
{
	if (pipes && pipes->pipe_fds != NULL)
	{
		if (pipes->current_pipe_index != pipes->count_pipes)
		{
			if (dup2(pipes->pipe_fds[pipes->current_pipe_index][1],
				STDOUT_FILENO) == -1)
			{
				ft_close_fds(pipes->count_pipes, pipes->pipe_fds);
				return (1);
			}
		}
		if (pipes->current_pipe_index != 0)
		{
			if (dup2(pipes->pipe_fds[pipes->current_pipe_index - 1][0],
				STDIN_FILENO) == -1)
			{
				ft_close_fds(pipes->count_pipes, pipes->pipe_fds);
				return (1);
			}
		}
		ft_close_fds(pipes->count_pipes, pipes->pipe_fds);
	}
	return (0);
}

static void	terminate_with_cleanup(
	t_pipe *pipes,
	char *pathname,
	t_data *data
)
{
	save_and_reset_dup(TRUE);
	if (pipes && pipes->pipe_fds)
	{
		ft_free_double_int_pointer(&pipes->pipe_fds, pipes->count_pipes);
	}
	ft_free_double_char_pointer(&data->argv);
	data->argv = NULL;
	protected_free(&pathname);
	ft_exit(data, FALSE);
}

void	exec_cmd_in_child(
	t_command *command,
	t_pipe *pipes,
	char *pathname,
	t_data *data
)
{
	if (configure_pipes(pipes) || redirect(command->redirections, TRUE))
	{
		data->last_exit_code = 1;
		terminate_with_cleanup(pipes, pathname, data);
	}
	if (data->argv && ft_get_builtin_num(data->argv[0]) != NO_BUILTIN)
	{
		data->last_exit_code = ft_handle_builtin(data, pipes, FALSE);
		terminate_with_cleanup(pipes, pathname, data);
	}
	if (increase_shlvl(&data->envp, pathname) != 0)
	{
		data->last_exit_code = 2;
		terminate_with_cleanup(pipes, pathname, data);
	}
	handle_signals(TRUE);
	if (pathname && execve(pathname, data->argv, data->envp) == -1)
	{
		data->last_exit_code = show_executable_error_msg(data);
	}
	terminate_with_cleanup(pipes, pathname, data);
}

static t_bool	is_possible_to_exec_in_parent(
	t_command *command,
	t_data *data,
	t_pipe *pipes
)
{
	return ((command->arguments == NULL
			&& command->redirections != NULL) || (data->argv
			&& ft_get_builtin_num(data->argv[0]) != NO_BUILTIN
			&& pipes == NULL));
}

int	try_exec_in_parent(
	t_command *command,
	t_data *data,
	t_pipe *pipes
)
{
	int	exit_code;

	exit_code = -42;
	if (is_possible_to_exec_in_parent(command, data, pipes))
	{
		exit_code = 0;
		if (data->argv != NULL)
		{
			exit_code = ft_handle_builtin(data, pipes, TRUE);
			ft_free_double_char_pointer(&data->argv);
			data->argv = NULL;
		}
		return (exit_code);
	}
	return (exit_code);
}
