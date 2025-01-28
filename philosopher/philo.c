/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:19:15 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/28 18:20:32 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	mutex;

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
	t_philosopher		*philosopher;
	long				milliseconds;
	int					is_time_to_eat;
	unsigned long long	time_since_last_eat;

	philosopher = (t_philosopher *)arguments;

	// milliseconds = get_current_time_in_milliseconds();
	// printf("%ld %d was born!!!\n", milliseconds, philosopher->philosopher_number);
	unsigned long long init_curr_time;
	init_curr_time = get_current_time_in_milliseconds();
	time_since_last_eat = init_curr_time;
	while (time_since_last_eat - init_curr_time <= philosopher->time_to_die)
	{
		time_since_last_eat = get_current_time_in_milliseconds();
		if (time_since_last_eat - init_curr_time >= philosopher->time_to_die)
			break ;

		is_time_to_eat = philosopher->left_fork->taken == 0 && philosopher->right_fork->taken == 0;
		while (!is_time_to_eat)
		{
			usleep(1);
			is_time_to_eat = philosopher->left_fork->taken == 0 && philosopher->right_fork->taken == 0;
			time_since_last_eat = get_current_time_in_milliseconds();
			if (time_since_last_eat - init_curr_time >= philosopher->time_to_die)
				break ;
		}
		
		time_since_last_eat = get_current_time_in_milliseconds();
		if (time_since_last_eat - init_curr_time >= philosopher->time_to_die)
			break ;

		if (philosopher->left_fork->taken == 0 && philosopher->right_fork->taken == 0)
		{
			pthread_mutex_lock(&philosopher->left_fork->mutex);
			pthread_mutex_lock(&philosopher->right_fork->mutex);
			philosopher->left_fork->taken = 1;
			philosopher->right_fork->taken = 1;
			milliseconds = get_current_time_in_milliseconds();
			printf("%ld %d has taken a fork\n", milliseconds, philosopher->philosopher_number);
			milliseconds = get_current_time_in_milliseconds();
			printf("%ld %d has taken a fork\n", milliseconds, philosopher->philosopher_number);
			milliseconds = get_current_time_in_milliseconds();
			printf("%ld %d is eating\n", milliseconds, philosopher->philosopher_number);
			// time_since_last_eat = get_current_time_in_milliseconds();
			init_curr_time = get_current_time_in_milliseconds();
			time_since_last_eat = get_current_time_in_milliseconds();
			usleep(philosopher->time_to_eat * 1000);
			time_since_last_eat = get_current_time_in_milliseconds();
			if (time_since_last_eat - init_curr_time >= philosopher->time_to_die)
			{
				break ;
				philosopher->left_fork->taken = 0;
				philosopher->right_fork->taken = 0;
				pthread_mutex_unlock(&philosopher->left_fork->mutex);
				pthread_mutex_unlock(&philosopher->right_fork->mutex);
			}
			philosopher->left_fork->taken = 0;
			philosopher->right_fork->taken = 0;
			pthread_mutex_unlock(&philosopher->left_fork->mutex);
			pthread_mutex_unlock(&philosopher->right_fork->mutex);
		}
		// printf("%lld\n", time_since_last_eat - init_curr_time);

		time_since_last_eat = get_current_time_in_milliseconds();
		if (time_since_last_eat - init_curr_time >= philosopher->time_to_die)
			break ;
		milliseconds = get_current_time_in_milliseconds();
		printf("%ld %d is sleeping\n", milliseconds, philosopher->philosopher_number);
		usleep(philosopher->time_to_sleep * 1000);

		time_since_last_eat = get_current_time_in_milliseconds();
		if (time_since_last_eat - init_curr_time >= philosopher->time_to_die)
			break ;

		milliseconds = get_current_time_in_milliseconds();
		printf("%ld %d is thinking\n", milliseconds, philosopher->philosopher_number);
		time_since_last_eat = get_current_time_in_milliseconds();
		if (time_since_last_eat - init_curr_time >= philosopher->time_to_die)
			break ;
		// curr_time = get_current_time_in_milliseconds();
		// diff = curr_time - init_curr_time;
	}
	milliseconds = get_current_time_in_milliseconds();
	printf("%ld %d died\n", milliseconds, philosopher->philosopher_number);
	return (NULL);
}

t_philosopher	*initialize_philosopher(unsigned int philosopher_number, char **argv, t_fork *left_fork, t_fork *right_fork)
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
	philosopher->left_fork = left_fork;
	philosopher->right_fork = right_fork;
	if (pthread_create(&philosopher->thread, NULL, philosopher_routine, philosopher))
	{
		//! HANDLE ERROR
		printf("ERROR THREAD CREATION\n");
		return (NULL);
	}
	return (philosopher);
}

t_fork	*initialize_fork(unsigned int fork_position, unsigned int number_pf_philosophers)
{
	t_fork			*fork;

	fork = malloc(sizeof(t_fork));
	if (fork == NULL)
		return (NULL);
	fork->taken = 0;
	if (fork_position == number_pf_philosophers)
		fork->philosopher_number_right = 1;
	else
		fork->philosopher_number_right = fork_position + 1;
	fork->philosopher_number_left = fork_position;
	return (fork);
}

int	initialize_monitor(t_monitor *monitor, char **argv)
{
	unsigned int	i;
	unsigned int	number_of_philosophers;

	i = 0;
	number_of_philosophers = ft_atoui(argv[1]);
	monitor->philosophers = malloc((number_of_philosophers + 1) * sizeof(t_philosopher *));
	if (monitor->philosophers == NULL)
	{
		//! HANDLE ERROR
		return (1);
	}
	monitor->forks = malloc((number_of_philosophers + 1) * sizeof(t_fork *));
	if (monitor->forks == NULL)
	{
		//! HANDLE ERROR
		return (1);
	}
	return (0);
}

int	initialize_philosophers(t_monitor *monitor, char **argv)
{
	unsigned int	i;
	unsigned int	number_of_philosophers;
	t_fork			*left_fork;
	t_fork			*right_fork;

	i = 0;
	number_of_philosophers = ft_atoui(argv[1]);
	while (i < number_of_philosophers)
	{
		left_fork = monitor->forks[i];
		if (i + 1 == number_of_philosophers)
			right_fork = monitor->forks[0];
		else
			right_fork = monitor->forks[i + 1];
		monitor->philosophers[i] = initialize_philosopher(i + 1, argv, left_fork, right_fork);
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

int	initialize_forks(t_monitor *monitor, char **argv)
{
	unsigned int	i;
	unsigned int	number_of_philosophers;

	i = 0;
	number_of_philosophers = ft_atoui(argv[1]);
	while (i < number_of_philosophers)
	{
		monitor->forks[i] = initialize_fork(i + 1, number_of_philosophers);
		if (monitor->forks[i] == NULL)
		{
			//! HANDLE ERROR AND FREE ALL PREVIOUSLY CREATED PHILOSOPHERS
			return (1);
		}
		pthread_mutex_init(&monitor->forks[i]->mutex, NULL);
		i++;
	}
	monitor->forks[i] = NULL;
	return (0);
}

int	deinitialize_forks(t_monitor *monitor)
{
	int	i;

	i = 0;
	while (monitor->forks[i] != NULL)
	{
		//! HANDLE RETURN ERROR
		pthread_mutex_destroy(&monitor->forks[i]->mutex);
		i++;
	}
	return (0);
}

int	wait_for_philosophers_done(t_monitor *monitor)
{
	int	i;

	i = 0;
	while (monitor->philosophers[i] != NULL)
	{
		if (pthread_join(monitor->philosophers[i]->thread, NULL))
		{
			printf("ERROR THREAD TERMINATION\n");
			return (3);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	t_monitor	monitor;

	i = 0;
	if (validate_arguments(argc, argv))
		return (1);
	if (initialize_monitor(&monitor, argv))
		return (2);
	if (initialize_forks(&monitor, argv))
		return (3);
	if (initialize_philosophers(&monitor, argv))
		return (4);
	// while (monitor.forks[i] != NULL)
	// {
	// 	printf("philosopher_number_left: %d\n", monitor.forks[i]->philosopher_number_left);
	// 	printf("philosopher_number_right: %d\n", monitor.forks[i]->philosopher_number_right);
	// 	i++;
	// }
	if (wait_for_philosophers_done(&monitor))
		return (5);
	if (deinitialize_forks(&monitor))
		return (6);
	return (0);
}
