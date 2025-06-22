/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:47:16 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/25 11:55:15 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <sys/wait.h>

static unsigned char	custom_wifexited(
	int exit_status
)
{
	return (((exit_status) & 0x7f) == 0);
}

static unsigned char	custom_wexitstatus(
	int exit_status
)
{
	return (((exit_status) & 0xff00) >> 8);
}

static unsigned char	custom_wifsignaled(
	int exit_status
)
{
	return (((signed char)(((exit_status) & 0x7f) + 1) >> 1) > 0);
}

static unsigned char	custom_wtermsig(
	int exit_status
)
{
	return ((exit_status) & 0x7f);
}

int	wait_for_child(
	int last_pid
)
{
	int		pid;
	int		exit_status;
	int		exit_code;

	exit_code = last_pid;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	pid = waitpid(-1, &exit_status, 0);
	while (pid > 0 && errno != ECHILD)
	{
		if (custom_wifexited(exit_status))
		{
			if (pid == last_pid)
				exit_code = custom_wexitstatus(exit_status);
		}
		if (custom_wifsignaled(exit_status) && pid == last_pid)
		{
			if (custom_wtermsig(exit_status) == SIGQUIT)
				ft_dprintf(STDOUT_FILENO, "Quit\n");
			exit_code = 128 + custom_wtermsig(exit_status);
			return (exit_code);
		}
		pid = waitpid(-1, &exit_status, 0);
	}
	return (exit_code);
}
