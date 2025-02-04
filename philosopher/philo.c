/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:19:15 by rzvir             #+#    #+#             */
/*   Updated: 2025/02/03 21:56:05 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t mutex;

long	get_current_time_in_milliseconds()
{
	struct timeval	current_time;
	long			milliseconds;

	gettimeofday(&current_time, NULL);
	milliseconds = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (milliseconds);
}

int	wait_to_eat(t_philosopher *philosopher, unsigned long long current_time, unsigned long long time_since_last_eat)
{
	int	is_time_to_eat;

	is_time_to_eat = philosopher->forks.left_fork->taken == 0 && philosopher->forks.right_fork->taken == 0;
	while (!is_time_to_eat)
	{
		usleep(1);
		is_time_to_eat = philosopher->forks.left_fork->taken == 0 && philosopher->forks.right_fork->taken == 0;
		current_time = get_current_time_in_milliseconds();
		if (current_time - time_since_last_eat >= philosopher->time_to_die)
			return (1);
	}
	return (0);
}

void	*philosopher_routine(void *arg)
{
	t_philo_info		*info;
	t_philosopher		*philosopher;
	long				milliseconds;
	// unsigned long long	current_time;
	// unsigned long long	time_since_last_eat;

	info = (t_philo_info *)arg;
	philosopher = info->philo;

	// while (philosopher->forks.left_fork->taken != 0 && philosopher->forks.right_fork->taken != 0)
	// 	usleep(1000);

	while (1)
	{
		// if ()
		pthread_mutex_lock(&mutex);
		milliseconds = get_current_time_in_milliseconds();
		printf("%ld %d is eating\n", milliseconds, philosopher->philosopher_number);
		sleep(1);
		pthread_mutex_unlock(&mutex);

		milliseconds = get_current_time_in_milliseconds();
		printf("%ld %d is sleeping\n", milliseconds, philosopher->philosopher_number);
		usleep(philosopher->time_to_sleep * 1000);

		milliseconds = get_current_time_in_milliseconds();
		printf("%ld %d is thinking\n", milliseconds, philosopher->philosopher_number);
	}
	// pthread_mutex_lock(&mutex);

	// pthread_mutex_lock(&philosopher->forks.left_fork->mutex);
	// pthread_mutex_lock(&philosopher->forks.right_fork->mutex);
	// philosopher->forks.left_fork->taken = 1;
	// philosopher->forks.right_fork->taken = 1;

	// milliseconds = get_current_time_in_milliseconds();
	// printf("%ld %d has taken a fork\n", milliseconds, philosopher->philosopher_number);

	// milliseconds = get_current_time_in_milliseconds();
	// printf("%ld %d has taken a fork\n", milliseconds, philosopher->philosopher_number);

	// milliseconds = get_current_time_in_milliseconds();
	// printf("%ld %d is eating\n", milliseconds, philosopher->philosopher_number);
	// time_since_last_eat = get_current_time_in_milliseconds();
	// current_time = get_current_time_in_milliseconds();
	// usleep(philosopher->time_to_eat * 1000);
	// sleep(1);

	// philosopher->forks.left_fork->taken = 0;
	// philosopher->forks.right_fork->taken = 0;
	// pthread_mutex_unlock(&philosopher->forks.left_fork->mutex);
	// pthread_mutex_unlock(&philosopher->forks.right_fork->mutex);

	// pthread_mutex_unlock(&mutex);
	// time_since_last_eat = get_current_time_in_milliseconds();
	// current_time = time_since_last_eat;
	// while (current_time - time_since_last_eat <= philosopher->time_to_die)
	// {
	// 	if (philosopher->number_of_meals == 0)
	// 		break ;

	// 	if (philosopher->forks.left_fork == NULL || philosopher->forks.right_fork == NULL)
	// 		break ;

	// 	current_time = get_current_time_in_milliseconds();
	// 	if (current_time - time_since_last_eat >= philosopher->time_to_die)
	// 		break ;
	// 	if (*info->is_someone_dead > 0)
	// 		return (info->is_someone_dead);

	// 	if (wait_to_eat(philosopher, current_time, time_since_last_eat))
	// 		break ;

		
	// 	current_time = get_current_time_in_milliseconds();
	// 	if (current_time - time_since_last_eat >= philosopher->time_to_die)
	// 		break ;
	// 	if (*info->is_someone_dead > 0)
	// 		return (info->is_someone_dead);

	// 	if ((philosopher->forks.left_fork->taken == 0 && philosopher->forks.right_fork->taken == 0))
	// 	{
	// 		pthread_mutex_lock(&philosopher->forks.left_fork->mutex);
	// 		pthread_mutex_lock(&philosopher->forks.right_fork->mutex);
	// 		philosopher->forks.left_fork->taken = 1;
	// 		philosopher->forks.right_fork->taken = 1;

	// 		milliseconds = get_current_time_in_milliseconds();
	// 		printf("%ld %d has taken a fork\n", milliseconds, philosopher->philosopher_number);

	// 		milliseconds = get_current_time_in_milliseconds();
	// 		printf("%ld %d has taken a fork\n", milliseconds, philosopher->philosopher_number);

	// 		if (*info->is_someone_dead > 0)
	// 			return (NULL);

	// 		milliseconds = get_current_time_in_milliseconds();
	// 		printf("%ld %d is eating\n", milliseconds, philosopher->philosopher_number);
	// 		time_since_last_eat = get_current_time_in_milliseconds();
	// 		current_time = get_current_time_in_milliseconds();
	// 		usleep(philosopher->time_to_eat * 1000);

	// 		if (philosopher->number_of_meals > 0)
	// 			philosopher->number_of_meals -= 1;

	// 		current_time = get_current_time_in_milliseconds();
	// 		if (current_time - time_since_last_eat >= philosopher->time_to_die)
	// 		{
	// 			philosopher->forks.left_fork->taken = 0;
	// 			philosopher->forks.right_fork->taken = 0;
	// 			pthread_mutex_unlock(&philosopher->forks.left_fork->mutex);
	// 			pthread_mutex_unlock(&philosopher->forks.right_fork->mutex);
	// 			break ;
	// 		}
	// 		if (*info->is_someone_dead > 0)
	// 		{
	// 			philosopher->forks.left_fork->taken = 0;
	// 			philosopher->forks.right_fork->taken = 0;
	// 			pthread_mutex_unlock(&philosopher->forks.left_fork->mutex);
	// 			pthread_mutex_unlock(&philosopher->forks.right_fork->mutex);
	// 			return (NULL);
	// 		}

	// 		philosopher->forks.left_fork->taken = 0;
	// 		philosopher->forks.right_fork->taken = 0;
	// 		pthread_mutex_unlock(&philosopher->forks.left_fork->mutex);
	// 		pthread_mutex_unlock(&philosopher->forks.right_fork->mutex);
	// 	}

	// 	current_time = get_current_time_in_milliseconds();
	// 	if (current_time - time_since_last_eat >= philosopher->time_to_die)
	// 		break ;
	// 	if (*info->is_someone_dead > 0)
	// 		return (info->is_someone_dead);

	// 	milliseconds = get_current_time_in_milliseconds();
	// 	printf("%ld %d is sleeping\n", milliseconds, philosopher->philosopher_number);
	// 	usleep(philosopher->time_to_sleep * 1000);

	// 	current_time = get_current_time_in_milliseconds();
	// 	if (current_time - time_since_last_eat >= philosopher->time_to_die)
	// 		break ;
	// 	if (*info->is_someone_dead > 0)
	// 		return (info->is_someone_dead);

	// 	milliseconds = get_current_time_in_milliseconds();
	// 	printf("%ld %d is thinking\n", milliseconds, philosopher->philosopher_number);

	// 	current_time = get_current_time_in_milliseconds();
	// 	if (current_time - time_since_last_eat >= philosopher->time_to_die)
	// 		break ;

	// 	if (*info->is_someone_dead > 0)
	// 		return (info->is_someone_dead);
	// }
	// if (philosopher->number_of_meals != 0 && *info->is_someone_dead == 0)
	// {
	// 	*info->is_someone_dead = philosopher->philosopher_number;
	// 	milliseconds = get_current_time_in_milliseconds();
	// 	printf("%ld %d died\n", milliseconds, philosopher->philosopher_number);
	// 	return (info->is_someone_dead);
	// }
	return (NULL);
}

int	initialize_monitor(t_monitor *monitor, char **argv)
{
	// unsigned int	i;
	unsigned int	number_of_philosophers;

	// i = 0;
	monitor->is_someone_dead = 0;
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

t_philosopher	*initialize_philosopher(unsigned int philosopher_number, char **argv, t_philosopher_forks *forks, t_monitor *monitor)
{
	t_philosopher	*philosopher;
	t_philo_info	*philo_info;

	philo_info = malloc(sizeof(t_philo_info));
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
	if (argv[5] == NULL)
		philosopher->number_of_meals = -1;
	else
		philosopher->number_of_meals = ft_atoui(argv[5]);
	philosopher->forks.left_fork = forks->left_fork;
	philosopher->forks.right_fork = forks->right_fork;
	philo_info->philo = philosopher;
	philo_info->is_someone_dead = &monitor->is_someone_dead;
	if (pthread_create(&philosopher->thread, NULL, philosopher_routine, philo_info))
	{
		//! HANDLE ERROR
		printf("ERROR THREAD CREATION\n");
		return (NULL);
	}
	return (philosopher);
}

int	initialize_philosophers(t_monitor *monitor, char **argv)
{
	unsigned int		i;
	unsigned int		number_of_philosophers;
	t_philosopher_forks	*forks;

	i = 0;
	forks = malloc(sizeof(t_philosopher_forks *));
	number_of_philosophers = ft_atoui(argv[1]);
	while (i < number_of_philosophers)
	{
		forks->left_fork = monitor->forks[i];
		if (number_of_philosophers == 1)
			forks->right_fork = NULL;
		else if (i + 1 == number_of_philosophers)
			forks->right_fork = monitor->forks[0];
		else
			forks->right_fork = monitor->forks[i + 1];
		monitor->philosophers[i] = initialize_philosopher(i + 1, argv, forks, monitor);
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

pthread_mutex_t	mutex;

t_fork	*initialize_fork()
{
	t_fork	*fork;

	fork = malloc(sizeof(t_fork));
	if (fork == NULL)
		return (NULL);
	fork->taken = 0;
	return (fork);
}

int	initialize_forks(t_monitor *monitor, char **argv)
{
	unsigned int	i;
	unsigned int	number_of_philosophers;

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
	int	*res;

	i = 0;
	while (monitor->philosophers[i] != NULL)
	{
		if (pthread_join(monitor->philosophers[i]->thread, (void **)&res))
		{
			printf("ERROR THREAD TERMINATION\n");
			return (1);
		}
		else
		{
			if (res != NULL)
				return (0);
		}
		i++;
	}
	return (0);
}

void	*waiter_routine(void *)
{
	while (1)
	{
		printf("WAITER WORK\n");
		sleep(1);
	}
	return (NULL);
}

void	*philo_routine(void *arg)
{
	while (1)
	{
		pthread_mutex_lock(&mutex);
		printf("PHILO %d WORK\n", *(int *)arg);
		// sleep(1);
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

void	initialize_waiter(pthread_t	*waiter)
{
	if (pthread_create(waiter, NULL, waiter_routine, NULL) != 0)
	{
		//! HANDLE ERROR
		printf("ERROR THREAD CREATION\n");
		// return (NULL);
	}
}

void	deinitialize_waiter(pthread_t	waiter)
{
	if (pthread_join(waiter, NULL) != 0)
	{
		//! HANDLE ERROR
		printf("ERROR THREAD TERMINATION\n");
		// return (NULL);
	}
}

void	initialize_philo(pthread_t	*philo)
{
	if (pthread_create(philo, NULL, philo_routine, NULL) != 0)
	{
		//! HANDLE ERROR
		printf("ERROR THREAD CREATION\n");
		// return (NULL);
	}
}

void	deinitialize_philo(pthread_t	philo)
{
	if (pthread_join(philo, NULL) != 0)
	{
		//! HANDLE ERROR
		printf("ERROR THREAD TERMINATION\n");
		// return (NULL);
	}
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	// int			i;
	pthread_t	waiter;
	// pthread_t	philos[5];
	// int			i;
	t_monitor	monitor;

	pthread_mutex_init(&mutex, NULL);

	// i = 0;
	// while (i < 5)
	// {
	// 	int	*a = malloc(sizeof(int));
	// 	*a = i;
	// 	pthread_create(&philos[i], NULL, philo_routine, a);
	// 	i++;
	// }

	// i = 0;
	// while (i < 5)
	// {
	// 	pthread_join(philos[i], NULL);
	// }

	if (validate_arguments(argc, argv))
		return (1);
	if (initialize_monitor(&monitor, argv))
		return (2);
	if (initialize_forks(&monitor, argv))
		return (3);
	initialize_waiter(&waiter);
	if (initialize_philosophers(&monitor, argv))
		return (4);
	deinitialize_waiter(waiter);
	if (wait_for_philosophers_done(&monitor))
		return (5);
	if (deinitialize_forks(&monitor))
		return (6);
	pthread_mutex_destroy(&mutex);
	return (0);
}
