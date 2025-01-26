/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:19:15 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/26 17:15:00 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	*routine()
{
	printf("TEST\n");
	return (NULL);
}

int	show_error(int code)
{
	char	*message1;
	char	*message2;

	message1 = "Wrong amount of arguments\n";
	message2 = "One of arguments is invalid\n";
	if (code == 1)
	{
		write(STDERR_FILENO, message1, ft_strlen(message1));
		return (1);
	}
	else if (code == 2)
	{
		write(STDERR_FILENO, message2, ft_strlen(message2));
		return (2);
	}
	return (0);
}

void	show_help()
{
	char	*message;

	message = "Usage: ./program philosophers time_to_die time_to_eat time_to_slee [meals_each]\n\n"
		"Args:\n"
		"  philosophers   Number of philosophers (>1).\n"
		"  time_to_die    Time (ms) a philosopher can live without eating.\n"
		"  time_to_eat    Time (ms) it takes to eat.\n"
		"  time_to_sleep  Time (ms) spent sleeping after eating.\n"
		"  [meals_each]   (Optional) Times each philosopher eats before ending.\n\n"
		"Example:\n"
		"  ./program 5 800 200 200 7\n";
	write(STDOUT_FILENO, message, ft_strlen(message));
}

int	is_valid_argument(char *argument)
{
	unsigned long long	number;
	size_t				number_length;

	number = ft_atoll(argument);
	number_length = ft_nbrlen(number);
	if (number == 0 && (argument[0] != '0' && ft_strlen(argument) != 1))
		return (0);
	if (number < 1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int			i;
	pthread_t	threads[4];
	(void) argv;

	//! 5 + 1 optional
	if (argc != 6)
	{
		show_help();
		return (1);
	}
	else
	{
		if (!is_valid_argument(argv[1]))
			return (show_error(2));
	}

	i = 0;
	while (i < 4)
	{
		if (pthread_create(threads + i, NULL, &routine, NULL) != 0)
		{
			printf("ERROR THREAD CREATION\n");
			return (1);
		};
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (pthread_join(threads[i], NULL) != 0)
		{
			printf("ERROR THREAD TERMINATION\n");
			return (2);
		};
		i++;
	}
	return (0);
}