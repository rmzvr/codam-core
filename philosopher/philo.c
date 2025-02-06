/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:19:15 by rzvir             #+#    #+#             */
/*   Updated: 2025/02/06 15:18:38 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t mutexPrint;
long	simulation_start_time;

uint64_t	get_current_time_in_milliseconds()
{
	struct timeval	current_time;
	long			milliseconds;

	gettimeofday(&current_time, NULL);
	milliseconds = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (milliseconds);
}

int	is_philosopher_dead(t_philosopher *philosopher)
{
	uint64_t	current_time;

	current_time = get_current_time_in_milliseconds();
	if (current_time - philosopher->last_meal_time >= philosopher->time_to_die)
		return (1);
	return (0);
}

void	wait(uint64_t time_to_wait)
{
	uint64_t	time_to_work;

	time_to_work = get_current_time_in_milliseconds() + time_to_wait;
	while (get_current_time_in_milliseconds() < time_to_work)
		usleep(100);
}

void	action(t_action action, int philosopher_number)
{
	uint64_t	milliseconds;

	pthread_mutex_lock(&mutexPrint);
	milliseconds = get_current_time_in_milliseconds();
	if (action == TAKE)
		printf("%ld %d has taken a fork\n", milliseconds - simulation_start_time, philosopher_number);
	else if (action == EAT)
		printf("%ld %d is eating\n", milliseconds - simulation_start_time, philosopher_number);
	else if (action == SLEEP)
		printf("%ld %d is sleeping\n", milliseconds - simulation_start_time, philosopher_number);
	else if (action == THINK)
		printf("%ld %d is thinking\n", milliseconds - simulation_start_time, philosopher_number);
	else if (action == DIE)
		printf("%ld %d died\n", milliseconds - simulation_start_time, philosopher_number);
	pthread_mutex_unlock(&mutexPrint);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *) arg;
	while (philosopher->number_of_meals > 0)
	{
		if (is_philosopher_dead(philosopher))
		{
			action(DIE, philosopher->philosopher_number);
			return (NULL);
		}
		else if (philosopher->is_someone_dead == 1)
			return (NULL);

		// if (philosopher->number_of_meals == 0)
		// 	return (NULL);

		if (philosopher->right_fork == NULL)
		{
			wait(philosopher->time_to_die);
			action(DIE, philosopher->philosopher_number);
			return (NULL);
		}

		pthread_mutex_lock(philosopher->left_fork);
		pthread_mutex_lock(philosopher->right_fork);

		action(TAKE, philosopher->philosopher_number);
		action(TAKE, philosopher->philosopher_number);
		action(EAT, philosopher->philosopher_number);
		philosopher->last_meal_time = get_current_time_in_milliseconds();
		wait(philosopher->time_to_eat);

		if (is_philosopher_dead(philosopher))
		{
			action(DIE, philosopher->philosopher_number);
			pthread_mutex_unlock(philosopher->left_fork);
			pthread_mutex_unlock(philosopher->right_fork);
			return (NULL);
		}
		else if (philosopher->is_someone_dead == 1)
		{
			pthread_mutex_unlock(philosopher->left_fork);
			pthread_mutex_unlock(philosopher->right_fork);
			return (NULL);
		}

		if (philosopher->number_of_meals > 0)
			philosopher->number_of_meals -= 1;

		pthread_mutex_unlock(philosopher->left_fork);
		pthread_mutex_unlock(philosopher->right_fork);

		if (is_philosopher_dead(philosopher))
		{
			action(DIE, philosopher->philosopher_number);
			return (NULL);
		}
		else if (philosopher->is_someone_dead == 1)
			return (NULL);

		action(SLEEP, philosopher->philosopher_number);
		wait(philosopher->time_to_sleep);

		if (is_philosopher_dead(philosopher))
		{
			action(DIE, philosopher->philosopher_number);
			return (NULL);
		}
		else if (philosopher->is_someone_dead == 1)
			return (NULL);

		action(THINK, philosopher->philosopher_number);

		if (is_philosopher_dead(philosopher))
		{
			action(DIE, philosopher->philosopher_number);
			return (NULL);
		}
		else if (philosopher->is_someone_dead == 1)
			return (NULL);
	}
	return (NULL);
}

int	initialize_monitor(t_monitor *monitor, char **argv)
{
	uint32_t	number_of_philosophers;

	number_of_philosophers = ft_atoui(argv[1]);
	monitor->philosophers = malloc((number_of_philosophers + 1) * sizeof(t_philosopher *));
	if (monitor->philosophers == NULL)
	{
		//! HANDLE ERROR
		return (1);
	}
	monitor->forks = malloc((number_of_philosophers + 1) * sizeof(pthread_mutex_t *));
	if (monitor->forks == NULL)
	{
		//! HANDLE ERROR
		return (1);
	}
	return (0);
}

t_philosopher	*initialize_philosopher(uint32_t philosopher_number, char **argv, pthread_mutex_t *left_fork, pthread_mutex_t *right_fork)
{
	t_philosopher	*philosopher;

	philosopher = malloc(sizeof(t_philosopher));
	if (philosopher == NULL)
	{
		//! HANDLE ERROR
		return (NULL);
	}
	philosopher->philosopher_number = philosopher_number;
	philosopher->last_meal_time = get_current_time_in_milliseconds();
	philosopher->is_someone_dead = 0;
	philosopher->time_to_die = ft_atoull(argv[2]);
	philosopher->time_to_eat = ft_atoull(argv[3]);
	philosopher->time_to_sleep = ft_atoull(argv[4]);
	if (argv[5] == NULL)
		philosopher->number_of_meals = -1;
	else
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

int	initialize_philosophers(t_monitor *monitor, char **argv)
{
	uint32_t	i;
	uint32_t	number_of_philosophers;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	i = 0;
	left_fork = malloc(sizeof(pthread_mutex_t *));
	right_fork = malloc(sizeof(pthread_mutex_t *));
	number_of_philosophers = ft_atoui(argv[1]);
	while (i < number_of_philosophers)
	{
		left_fork = monitor->forks[i];
		if (number_of_philosophers == 1)
			right_fork = NULL;
		else if (i + 1 == number_of_philosophers)
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

pthread_mutex_t	*initialize_fork()
{
	pthread_mutex_t *fork;

	fork = malloc(sizeof(pthread_mutex_t));
	if (fork == NULL)
		return (NULL);
	return (fork);
}

int	initialize_forks(t_monitor *monitor, char **argv)
{
	uint32_t	i;
	uint32_t	number_of_philosophers;

	i = 0;
	number_of_philosophers = ft_atoui(argv[1]);
	while (i < number_of_philosophers)
	{
		monitor->forks[i] = initialize_fork();
		if (monitor->forks[i] == NULL)
		{
			//! HANDLE ERROR AND FREE ALL PREVIOUSLY CREATED PHILOSOPHERS
			return (1);
		}
		pthread_mutex_init(monitor->forks[i], NULL);
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
		pthread_mutex_destroy(monitor->forks[i]);
		i++;
	}
	return (0);
}

int	deinitialize_philosophers(t_monitor *monitor)
{
	int	i;

	i = 0;
	while (monitor->philosophers[i] != NULL)
	{
		if (pthread_join(monitor->philosophers[i]->thread, NULL))
		{
			printf("ERROR PHILOSOPHER %d TERMINATION\n", i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_all_philosophers_alive(t_philosopher **philosophers)
{
	int	i;

	i = 0;
	while (philosophers[i] != NULL)
	{
		if (is_philosopher_dead(philosophers[i]))
			return (0);
		i++;
	}
	return (1);
}

void	*waiter_routine(void *arg)
{
	int			i;
	int			res;
	t_monitor	*monitor;

	i = 0;
	monitor = (t_monitor *) arg;
	res = is_all_philosophers_alive(monitor->philosophers);
	while (res)
	{
		usleep(100);
		res = is_all_philosophers_alive(monitor->philosophers);
	}
	while (monitor->philosophers[i] != NULL)
	{
		monitor->philosophers[i]->is_someone_dead = 1;
		i++;
	}
	return (NULL);
}

int	initialize_waiter(pthread_t	*waiter, t_monitor *monitor)
{
	if (pthread_create(waiter, NULL, waiter_routine, monitor) != 0)
	{
		//! HANDLE ERROR
		printf("ERROR WAITER CREATION\n");
		return (1);
	}
	return (0);
}

int	deinitialize_waiter(pthread_t	waiter)
{
	if (pthread_join(waiter, NULL) != 0)
	{
		//! HANDLE ERROR
		printf("ERROR WAITER TERMINATION\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pthread_t	waiter;
	t_monitor	monitor;
	simulation_start_time = get_current_time_in_milliseconds();

	pthread_mutex_init(&mutexPrint, NULL);

	if (validate_arguments(argc, argv))
		return (1);
	if (initialize_monitor(&monitor, argv))
		return (2);
	if (initialize_forks(&monitor, argv))
		return (3);
	if (initialize_waiter(&waiter, &monitor))
		return (4);
	if (initialize_philosophers(&monitor, argv))
		return (5);
	if (deinitialize_waiter(waiter))
		return (6);
	if (deinitialize_philosophers(&monitor))
		return (7);
	if (deinitialize_forks(&monitor))
		return (9);

	pthread_mutex_destroy(&mutexPrint);
	return (0);
}
