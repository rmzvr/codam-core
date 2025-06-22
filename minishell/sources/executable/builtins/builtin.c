/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:28:09 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/22 16:44:57 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "builtins/builtins.h"

int	ft_get_builtin_num(
	char *cmd
)
{
	if (cmd == NULL)
		return (NO_BUILTIN);
	if (ft_strcmp(cmd, "echo") == 0)
		return (ECHO);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (CD);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (PWD);
	else if (ft_strcmp(cmd, "export") == 0)
		return (EXPORT);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (UNSET);
	else if (ft_strcmp(cmd, "env") == 0)
		return (ENV);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (EXIT);
	return (NO_BUILTIN);
}

int	ft_handle_builtin(
	t_data *data,
	t_pipe *pipes,
	t_bool print_exit
)
{
	int		exit_code;
	int		builtin_num;

	exit_code = 0;
	builtin_num = ft_get_builtin_num(data->argv[0]);
	if (builtin_num == ECHO)
		exit_code = ft_echo(data->argv);
	else if (builtin_num == CD)
		exit_code = ft_cd(&data->envp, data->argv);
	else if (builtin_num == PWD)
		exit_code = ft_pwd(&data->envp);
	else if (builtin_num == EXPORT)
		exit_code = ft_export(&data->envp, data->argv);
	else if (builtin_num == UNSET)
		exit_code = ft_unset(&data->envp, data->argv);
	else if (builtin_num == ENV)
		exit_code = ft_env(data->envp);
	else if (builtin_num == EXIT)
	{
		save_and_reset_dup(TRUE);
		if (pipes && pipes->pipe_fds)
			ft_free_double_int_pointer(&pipes->pipe_fds, pipes->count_pipes);
		exit_code = ft_exit(data, print_exit);
	}
	return (exit_code);
}
