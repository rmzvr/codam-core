/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:16:33 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/30 11:45:33 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	show_error(int code)
{
	char	*message1;
	char	*message2;
	char	*message3;
	char	*message4;
	char	*message5;

	message1 = "Wrong amount of arguments\n";
	message2 = "One of arguments is invalid\n";
	message3 = "Number of philosophers should be at least 1\n";
	message4 = "All arguments must be positive numbers\n";
	message5 = "Number of meals should be at least 1\n";
	if (code == 1)
		write(STDERR_FILENO, message1, ft_strlen(message1));
	else if (code == 2)
		write(STDERR_FILENO, message2, ft_strlen(message2));
	else if (code == 3)
		write(STDERR_FILENO, message3, ft_strlen(message3));
	else if (code == 4)
		write(STDERR_FILENO, message4, ft_strlen(message4));
	else if (code == 5)
		write(STDERR_FILENO, message5, ft_strlen(message5));
	return (code);
}

int	show_help(void)
{
	char	*message;

	message = "Usage: ./philo number_of_philosophers time_to_die "
		"time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n\n"
		"Arguments:\n"
		"  number_of_philosophers    Number of philosophers (and forks), >1.\n"
		"  time_to_die               Time (ms) a philosopher lives without eating.\n"
		"  time_to_eat               Time (ms) it takes for a philosopher to eat.\n"
		"  time_to_sleep             Time (ms) a philosopher sleeps after eating.\n"
		"  [number_of_times_each_philosopher_must_eat] (optional)\n"
		"                                 Number of meals before simulation ends.\n\n"
		"Notes:\n"
		"  - All arguments must be positive numbers.\n"
		"  - Missing or invalid arguments terminate the program.\n\n"
		"Example:\n"
		"  ./philo 5 800 200 200 7\n";
	write(STDOUT_FILENO, message, ft_strlen(message));
	return (1);
}
