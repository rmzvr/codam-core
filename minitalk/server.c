/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:54:51 by rmzvr             #+#    #+#             */
/*   Updated: 2025/01/20 23:40:37 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>

volatile sig_atomic_t g_sigusr = 0;

typedef struct s_sig
{
	int	character;
	int	bits;
}	t_sig;

void	handle_sigusr(int signum)
{
	static t_sig	sig;

	if (!sig.character)
		sig.character = 0;
	if (!sig.bits)
		sig.bits = 1;
	if (signum == 10)
		sig.character ^= 0;
	else if (signum == 12)
		sig.character ^= 1;
	if (sig.bits == 8)
	{
		// ft_putnbr_fd(sig.bits, 1);
		write(1, &sig.character, 1);
		sig.bits = 1;
		sig.character = 0;
		return ;
	}
	// if (sig.bits > 8)
	// {
	// 	ft_putnbr_fd(sig.bits, 1);

	// }
	sig.bits++;
	sig.character <<= 1;
}

typedef struct sigaction action_t;

int	main(void)
{
	pid_t		pid;
	sigset_t	signal_set;
	action_t	SIGUSR_action;

	SIGUSR_action.sa_handler = handle_sigusr;
	sigemptyset(&signal_set);
	SIGUSR_action.sa_flags = 0;

	sigaction(SIGUSR1, &SIGUSR_action, NULL);
	sigaction(SIGUSR2, &SIGUSR_action, NULL);

	pid = getpid();
	ft_printf("The server ID is %d\n", pid);
	while (1)
		pause();
	return (0);
}
