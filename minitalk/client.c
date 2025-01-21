/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:54:53 by rmzvr             #+#    #+#             */
/*   Updated: 2025/01/21 17:17:53 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static volatile int	g_signal_pid = 1;

void	get_pid(int signal_number)
{
	(void) signal_number;
	g_signal_pid = 0;
	ft_putnbr_fd(g_signal_pid, 1);
	// write(1, "0", 1);
	return ;
}

int	main(void)
{
	int			i;
	int			mask;
	char		*message;
	char		character;
	char		iteration;
	sigset_t	signal_set;
	t_action	signal_action;

	signal_action.sa_flags = 0;
	signal_action.sa_handler = get_pid;
	sigaddset(&signal_set, SIGUSR1);
	sigaddset(&signal_set, SIGUSR2);
	sigaction(SIGUSR1, &signal_action, NULL);
	i = 0;
	mask = 128;
	message = ft_strdup("Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.");
	// ft_printf("The client ID is %d\n", process_id);
	kill(140033, SIGUSR1);
	while (g_signal_pid)
		usleep(42);
	usleep(42);
	g_signal_pid = 0;
	// ft_printf("Server's ID on client side: %d\n", g_signal_pid);
	while (message[i] != '\0')
	{
		iteration = 0;
		character = message[i];
		while (iteration < 8)
		{
			if (character & mask)
			{
				kill(140033, SIGUSR2);
			}
			else
				kill(140033, SIGUSR1);
			iteration++;
			character <<= 1;
			g_signal_pid = 1;
			while (g_signal_pid)
				usleep(42);
			usleep(42);
			g_signal_pid = 0;
			write(1, "1", 1);
			// ft_printf("Server's ID on client side: %d\n", g_signal_pid);
		}
		iteration = 0;
		i++;
	}
	free(message);
	message = NULL;
	return (0);
}
