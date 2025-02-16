/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:16:33 by rzvir             #+#    #+#             */
/*   Updated: 2025/02/16 18:59:05 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	show_malloc_error(int code)
{
	char	*message1;
	message1 = "Error occurred while allocating memory\n";
	if (code == 1)
		write(STDERR_FILENO, message1, ft_strlen(message1));
	return (code);
}

int	handle_thread_error(int code, t_thread_action action)
{
	char	*message1;
	char	*message2;

	message1 = "Error occurred while create thread\n";
	message2 = "Error occurred while join thread\n";
	if (code == 0)
		return (0);
	else if (action == CREATE)
		write(STDERR_FILENO, message1, ft_strlen(message1));
	else if (action == JOIN)
		write(STDERR_FILENO, message2, ft_strlen(message2));
	return (1);
}

int	handle_mutex_error(int code, t_mutex_action action)
{
	char	*message1;
	char	*message2;
	char	*message3;
	char	*message4;

	message1 = "Error occurred while initialize mutex\n";
	message2 = "Error occurred while destroy mutex\n";
	message3 = "Error occurred while lock mutex\n";
	message4 = "Error occurred while unlock mutex\n";
	if (code == 0)
		return (0);
	else if (action == INIT)
		write(STDERR_FILENO, message1, ft_strlen(message1));
	else if (action == DESTROY)
		write(STDERR_FILENO, message2, ft_strlen(message2));
	else if (action == LOCK)
		write(STDERR_FILENO, message3, ft_strlen(message3));
	else if (action == UNLOCK)
		write(STDERR_FILENO, message4, ft_strlen(message4));
	return (1);
}

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
