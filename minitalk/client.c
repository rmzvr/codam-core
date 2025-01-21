/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.1000.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:54:53 by rmzvr             #+#    #+#             */
/*   Updated: 2025/01/21 18:05:01 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	get_sig(int signal_number)
{
	(void) signal_number;
}

int	main(int argc, char **argv)
{
	(void)		argc;
	int			i;
	int			mask;
	char		*message;
	char		character;
	char		iteration;
	sigset_t	signal_set;
	t_action	signal_action;

	ft_printf("__PID: %d\n", getpid());
	signal_action.sa_flags = 0;
	signal_action.sa_handler = get_sig;
	sigemptyset(&signal_set);
	sigaction(SIGUSR1, &signal_action, NULL);
	i = 0;
	mask = 0b10000000;
	message = ft_strdup(argv[2]);
	while (message[i] != '\0')
	{
		iteration = 0;
		character = message[i];
		while (iteration < 8)
		{
			if (character & mask)
				kill(ft_atoi(argv[1]), SIGUSR2);
			else
				kill(ft_atoi(argv[1]), SIGUSR1);
			pause();
			iteration++;
			character <<= 1;
		}
		iteration = 0;
		i++;
	}
	free(message);
	message = NULL;
	return (0);
}
