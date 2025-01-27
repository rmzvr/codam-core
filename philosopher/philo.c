/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:19:15 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/27 18:48:31 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time_in_milliseconds()
{
	struct timeval	current_time;
	long			milliseconds;

	gettimeofday(&current_time, NULL);
	milliseconds = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (milliseconds);
}

void	*philosopher_routine(void *arguments)
{
	t_philosopher	*philosopher;
	long			milliseconds;

	philosopher = (t_philosopher *)arguments;

	milliseconds = get_current_time_in_milliseconds();
	printf("%ld %d has taken a fork\n", milliseconds, philosopher->philosopher_number);

	milliseconds = get_current_time_in_milliseconds();
	printf("%ld %d is eating\n", milliseconds, philosopher->philosopher_number);
	usleep(philosopher->time_to_eat * 1000);

	milliseconds = get_current_time_in_milliseconds();
	printf("%ld %d is sleeping\n", milliseconds, philosopher->philosopher_number);
	usleep(philosopher->time_to_sleep * 1000);

	milliseconds = get_current_time_in_milliseconds();
	printf("%ld %d is thinking\n", milliseconds, philosopher->philosopher_number);

	return (NULL);
}

t_philosopher	*initialize_philosopher(unsigned int philosopher_number, char **argv)
{
	t_philosopher	*philosopher;

	philosopher = malloc(sizeof(t_philosopher));
	if (philosopher == NULL)
	{
		//! HANDLE ERROR
		return (NULL);
	}
	philosopher->philosopher_number = philosopher_number;
	philosopher->time_to_die = ft_atoull(argv[2]);
	philosopher->time_to_eat = ft_atoull(argv[3]);
	philosopher->time_to_sleep = ft_atoull(argv[4]);
	philosopher->number_of_meals = ft_atoui(argv[5]);
	if (pthread_create(&philosopher->thread, NULL, philosopher_routine, philosopher))
	{
		//! HANDLE ERROR
		printf("ERROR THREAD CREATION\n");
		return (NULL);
	}
	// struct timeval	current_time;
	// gettimeofday(&current_time, NULL);
	// long milliseconds = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	// printf("Philosopher %d created in %ld milliseconds.\n", philosopher_number, milliseconds);
	// printf("Philosopher %d created thread\n", index);
	return (philosopher);
}

int	initialize_monitor(t_monitor *monitor, char **argv)
{
	unsigned int	i;
	unsigned int	number_of_philosophers;

	i = 0;
	number_of_philosophers = ft_atoui(argv[1]);
	monitor->philosophers = malloc((number_of_philosophers + 1) * sizeof(t_philosopher));
	if (monitor->philosophers == NULL)
	{
		//! HANDLE ERROR
		return (1);
	}
	while (i < number_of_philosophers)
	{
		monitor->philosophers[i] = initialize_philosopher(i + 1, argv);
		if (monitor->philosophers[i] == NULL)
		{
			//! HANDLE ERROR AND FREE ALL PREVIOUSLY CREATED PHILOSOPHERS
			return (1);
		}
		i++;
	}
	monitor->philosophers[i] = NULL;
	return (0);
}

int	main(int argc, char **argv)
{
	int				i;
	t_monitor		monitor;
	if (validate_arguments(argc, argv))
		return (1);
	if (initialize_monitor(&monitor, argv))
		return (2);
	i = 1;
	while (monitor.philosophers[i] != NULL)
	{
		if (pthread_join(monitor.philosophers[i]->thread, NULL))
		{
			printf("ERROR THREAD TERMINATION\n");
			return (3);
		}
	// struct timeval	current_time;
	// gettimeofday(&current_time, NULL);
	// long milliseconds = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	// printf("Philosopher %d terminated in %ld milliseconds.\n", i, milliseconds);
		i++;
	}
	return (0);
}
