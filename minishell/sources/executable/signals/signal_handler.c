/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:40:03 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/25 13:33:27 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals/signal_handler.h"
#include "colors.h"

extern sig_atomic_t	g_is_interactive_mode_switch;

static void	handle_sigint_signal(
	int signum
)
{
	g_is_interactive_mode_switch = SIGINT;
	ft_dprintf(STDOUT_FILENO, "\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	(void)signum;
}

void	handle_sigint_signal_no_nl(
	int signum
)
{
	g_is_interactive_mode_switch = SIGINT;
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	(void)signum;
}

void	handle_sigusr_signals(
	int signum,
	siginfo_t *info,
	void *content
)
{
	(void)content;
	if ((signum == SIGUSR1 || signum == SIGUSR2)
		&& info->si_pid == getpid())
	{
		g_is_interactive_mode_switch = signum;
	}
}

void	handle_signals(
	t_bool set_default
)
{
	struct sigaction	action;

	if (set_default)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		signal(SIGPIPE, SIG_DFL);
		signal(SIGUSR1, SIG_DFL);
		signal(SIGUSR2, SIG_DFL);
	}
	else
	{
		signal(SIGINT, handle_sigint_signal);
		signal(SIGPIPE, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGTSTP, SIG_IGN);
		action.sa_sigaction = handle_sigusr_signals;
		action.sa_flags = SA_SIGINFO;
		sigemptyset(&action.sa_mask);
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
	}
}
