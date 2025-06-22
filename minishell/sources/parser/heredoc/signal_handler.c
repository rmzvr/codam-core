/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:55:06 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/25 13:36:43 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <parser/heredoc.h>
#include "signals/signal_handler.h"

extern sig_atomic_t	g_is_interactive_mode_switch;

void	signal_handler_heredoc(int sig)
{
	save_and_reset_dup(FALSE);
	g_is_interactive_mode_switch = sig;
	ft_dprintf(STDOUT_FILENO, "\n");
	close(STDIN_FILENO);
}

int	heredoc_handle_signal(
	t_executor_data *executor_data
)
{
	if (g_is_interactive_mode_switch == SIGINT)
	{
		signal(SIGINT, handle_sigint_signal_no_nl);
		free_heredoc_data(executor_data, FALSE);
		save_and_reset_dup(TRUE);
		return (FAIL);
	}
	if (executor_data->input == NULL)
	{
		show_heredoc_warning(executor_data->starting_line,
			executor_data->delimiter);
		free_heredoc_data(executor_data, FALSE);
		kill(getpid(), SIGUSR2);
		return (FAIL);
	}
	return (OK);
}
