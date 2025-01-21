/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:54:51 by rmzvr             #+#    #+#             */
/*   Updated: 2025/01/21 17:17:48 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static volatile sig_atomic_t	g_signal = -1;
static volatile int	g_pause = 1;

void	get_pid(int signal_number, siginfo_t *info, void *context)
{
	(void) context;
	if (g_signal == -1)
		g_signal = info->si_pid;
	else
		g_signal = signal_number;

	g_pause = 0;
	// ft_putnbr_fd(g_pause, 1);
	// ft_putnbr_fd(g_pause, 1);
	// write(1, "0", 1);
}

void	handle_sig(int signal_number)
{
	static t_sig	sig;

	if (!sig.character)
		sig.character = 0;
	if (!sig.bits)
		sig.bits = 1;
	if (signal_number == 10)
		sig.character ^= 0;
	else if (signal_number == 12)
		sig.character ^= 1;
	if (sig.bits == 8)
	{
		write(1, &sig.character, 1);
		sig.bits = 1;
		sig.character = 0;
		return ;
	}
	sig.bits++;
	sig.character <<= 1;
}

int	main(void)
{
	pid_t		process_id;
	sigset_t	signal_set;
	t_action	signal_action;
	int			sender_process_id;

	ft_bzero(&signal_action, sizeof(signal_action));
	signal_action.sa_flags = SA_SIGINFO;
	signal_action.sa_sigaction = get_pid;
	sigemptyset(&signal_set);
	sigaction(SIGUSR1, &signal_action, NULL);
	sigaction(SIGUSR2, &signal_action, NULL);
	process_id = getpid();
	ft_printf("The server ID is %d\n", process_id);
	while (1)
	{
		g_pause = 1;
		while (g_pause)
			usleep(42);
		usleep(42);
		g_pause = 0;
		// write(1, "1", 1);
		if (g_signal > 31)
		{
			sender_process_id = g_signal;
			// ft_printf("Client's ID on server side: %d\n", g_signal);
		}
		else
			handle_sig(g_signal);
		g_signal = -2;
		kill(sender_process_id, SIGUSR1);
	}
	return (0);
}
