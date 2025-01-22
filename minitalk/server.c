/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:54:51 by rmzvr             #+#    #+#             */
/*   Updated: 2025/01/22 12:10:12 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

static void	decode_bits(int signal_number)
{
	static int	character;
	static int	current_bit;

	if (!character)
		character = 0;
	if (!current_bit)
		current_bit = 1;
	if (signal_number == 10)
		character ^= 0;
	else if (signal_number == 12)
		character ^= 1;
	if (current_bit == 8)
	{
		ft_putchar_fd(character, 1);
		current_bit = 1;
		character = 0;
		return ;
	}
	current_bit++;
	character <<= 1;
}

static void	handle_signal(int signal_number, siginfo_t *info, void *context)
{
	(void) context;
	decode_bits(signal_number);
	kill(info->si_pid, SIGUSR1);
}

static void	set_signal_action(void)
{
	sigset_t			signal_set;
	struct sigaction	signal_action;

	ft_bzero(&signal_action, sizeof(signal_action));
	signal_action.sa_sigaction = handle_signal;
	signal_action.sa_flags = SA_SIGINFO;
	sigemptyset(&signal_set);
	sigaction(SIGUSR1, &signal_action, NULL);
	sigaction(SIGUSR2, &signal_action, NULL);
}

int	main(void)
{
	pid_t	server_pid;

	set_signal_action();
	server_pid = getpid();
	ft_printf("The server ID is %d\n", server_pid);
	while (1)
		pause();
	return (0);
}
