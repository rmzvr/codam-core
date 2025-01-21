/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.100.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:54:51 by rmzvr             #+#    #+#             */
/*   Updated: 2025/01/21 17:17:48 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

void	get_pid(int signal_number, siginfo_t *info, void *context)
{
	(void) context;
	handle_sig(signal_number);
	usleep(100);
	kill(info->si_pid, SIGUSR1);
}

// ! DELETE
void close_(int signum){
	(void)signum;
	exit(0);
}

int	main(void)
{
	pid_t		process_id;
	sigset_t	signal_set;
	t_action	signal_action;

	// ! DELETE
	signal(SIGINT, &close_);
	ft_bzero(&signal_action, sizeof(signal_action));
	signal_action.sa_flags = SA_SIGINFO;
	signal_action.sa_sigaction = get_pid;
	sigemptyset(&signal_set);
	sigaction(SIGUSR1, &signal_action, NULL);
	sigaction(SIGUSR2, &signal_action, NULL);
	process_id = getpid();
	ft_printf("The server ID is %d\n", process_id);
	while (1)
		pause();
	return (0);
}
