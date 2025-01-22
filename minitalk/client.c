/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:54:53 by rmzvr             #+#    #+#             */
/*   Updated: 2025/01/22 12:32:16 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

static volatile sig_atomic_t	g_pause = 1;

static void	handle_signal(int signal_number)
{
	(void) signal_number;
	g_pause = 0;
}

void	set_signal_action(void)
{
	sigset_t			signal_set;
	struct sigaction	signal_action;

	ft_bzero(&signal_action, sizeof(signal_action));
	signal_action.sa_handler = handle_signal;
	signal_action.sa_flags = 0;
	sigemptyset(&signal_set);
	sigaction(SIGUSR1, &signal_action, NULL);
}

static void	send_message(int server_pid, char *message)
{
	char	character;
	char	iteration;
	int		kill_success;

	while (*message != '\0')
	{
		iteration = 0;
		character = *message++;
		while (iteration < 8)
		{
			if (character & 0b10000000)
				kill_success = kill(server_pid, SIGUSR2);
			else
				kill_success = kill(server_pid, SIGUSR1);
			if (kill_success == -1)
				exit(EXIT_FAILURE);
			iteration++;
			character <<= 1;
			while (g_pause)
				usleep(50);
			g_pause = 1;
		}
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	int		server_pid;

	if (argc != 3)
		return (1);
	message = argv[2];
	server_pid = ft_atoi(argv[1]);
	set_signal_action();
	send_message(server_pid, message);
	return (0);
}
