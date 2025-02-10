/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:19:15 by rzvir             #+#    #+#             */
/*   Updated: 2025/02/08 19:05:50 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

	pthread_mutex_lock(philosopher->mealMutex);
	pthread_mutex_lock(philosopher->deathMutex);
	current_time = get_current_time_in_milliseconds();
	if (current_time - philosopher->last_meal_time >= philosopher->time_to_die)
	{
		pthread_mutex_unlock(philosopher->mealMutex);
		pthread_mutex_unlock(philosopher->deathMutex);
		return (1);
	}
	pthread_mutex_unlock(philosopher->mealMutex);
	pthread_mutex_unlock(philosopher->deathMutex);
	return (0);
}

void	wait(uint64_t time_to_wait)
{
	uint64_t	time_to_work;

	time_to_work = get_current_time_in_milliseconds() + time_to_wait;
	while (get_current_time_in_milliseconds() < time_to_work)
		usleep(500);
}

void	action(t_action action, uint64_t dinner_start, t_philosopher *philosopher)
{
	uint64_t	milliseconds;

	pthread_mutex_lock(philosopher->printMutex);
	milliseconds = get_current_time_in_milliseconds();
	if (action == TAKE)
		printf("%ld %d has taken a fork\n", milliseconds - dinner_start, philosopher->philosopher_number);
	else if (action == EAT)
		printf("%ld %d is eating\n", milliseconds - dinner_start, philosopher->philosopher_number);
	else if (action == SLEEP)
		printf("%ld %d is sleeping\n", milliseconds - dinner_start, philosopher->philosopher_number);
	else if (action == THINK)
		printf("%ld %d is thinking\n", milliseconds - dinner_start, philosopher->philosopher_number);
	else if (action == DIE)
		printf("%ld %d died\n", milliseconds - dinner_start, philosopher->philosopher_number);
	pthread_mutex_unlock(philosopher->printMutex);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *) arg;
	pthread_mutex_lock(philosopher->startMutex);
	pthread_mutex_unlock(philosopher->startMutex);
	while (1)
	{
		if (philosopher->right_fork == NULL)
			wait(philosopher->time_to_die);

		pthread_mutex_lock(philosopher->deathMutex);
		if (*philosopher->is_someone_dead)
		{
			pthread_mutex_unlock(philosopher->deathMutex);
			return (NULL);
		}
		pthread_mutex_unlock(philosopher->deathMutex);

		if (philosopher->philosopher_number % 2 == 0)
			usleep(1000);

		pthread_mutex_lock(philosopher->left_fork);
		pthread_mutex_lock(philosopher->right_fork);

		pthread_mutex_lock(philosopher->deathMutex);
		if (*philosopher->is_someone_dead)
		{
			pthread_mutex_unlock(philosopher->deathMutex);
			return (NULL);
		}
		pthread_mutex_unlock(philosopher->deathMutex);

		action(TAKE, *philosopher->dinner_start_time, philosopher);
		action(TAKE, *philosopher->dinner_start_time, philosopher);

		pthread_mutex_lock(philosopher->deathMutex);
		if (*philosopher->is_someone_dead)
		{
			pthread_mutex_unlock(philosopher->left_fork);
			pthread_mutex_unlock(philosopher->right_fork);
			pthread_mutex_unlock(philosopher->deathMutex);
			return (NULL);
		}
		pthread_mutex_unlock(philosopher->deathMutex);

		pthread_mutex_lock(philosopher->mealMutex);
		philosopher->last_meal_time = get_current_time_in_milliseconds();
		philosopher->number_of_meals -= 1;
		pthread_mutex_unlock(philosopher->mealMutex);

		pthread_mutex_lock(philosopher->deathMutex);
		if (*philosopher->is_someone_dead)
		{
			pthread_mutex_unlock(philosopher->left_fork);
			pthread_mutex_unlock(philosopher->right_fork);
			pthread_mutex_unlock(philosopher->deathMutex);
			return (NULL);
		}
		pthread_mutex_unlock(philosopher->deathMutex);

		action(EAT, *philosopher->dinner_start_time, philosopher);
		wait(philosopher->time_to_eat);
		
		pthread_mutex_unlock(philosopher->left_fork);
		pthread_mutex_unlock(philosopher->right_fork);

		pthread_mutex_lock(philosopher->deathMutex);
		if (*philosopher->is_someone_dead)
		{
			pthread_mutex_unlock(philosopher->deathMutex);
			return (NULL);
		}
		pthread_mutex_unlock(philosopher->deathMutex);

		action(SLEEP, *philosopher->dinner_start_time, philosopher);
		wait(philosopher->time_to_sleep);

		pthread_mutex_lock(philosopher->deathMutex);
		if (*philosopher->is_someone_dead)
		{
			pthread_mutex_unlock(philosopher->deathMutex);
			return (NULL);
		}
		pthread_mutex_unlock(philosopher->deathMutex);

		action(THINK, *philosopher->dinner_start_time, philosopher);
	}
	return (NULL);
}

int	initialize_table(t_table *table, char **argv)
{
	uint32_t	number_of_philosophers;

	table->dinner_start_time = -1;
	table->is_someone_dead = 0;
	number_of_philosophers = ft_atoui(argv[1]);
	table->philosophers = malloc((number_of_philosophers + 1) * sizeof(t_philosopher *));
	if (table->philosophers == NULL)
	{
		//! HANDLE ERROR
		return (1);
	}
	table->forks = malloc((number_of_philosophers + 1) * sizeof(pthread_mutex_t *));
	if (table->forks == NULL)
	{
		//! HANDLE ERROR
		return (1);
	}
	pthread_mutex_init(&table->startMutex, NULL);
	pthread_mutex_init(&table->deathMutex, NULL);
	pthread_mutex_init(&table->mealMutex, NULL);
	pthread_mutex_init(&table->printMutex, NULL);
	return (0);
}

int	deinitialize_table(t_table *table)
{
	pthread_mutex_destroy(&table->startMutex);
	pthread_mutex_destroy(&table->deathMutex);
	pthread_mutex_destroy(&table->mealMutex);
	pthread_mutex_destroy(&table->printMutex);
	return (0);
}

t_philosopher	*initialize_philosopher(uint32_t philosopher_number, char **argv, pthread_mutex_t *left_fork, pthread_mutex_t *right_fork, t_table *table)
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
	philosopher->is_someone_dead = &table->is_someone_dead;
	philosopher->time_to_die = ft_atoul(argv[2]);
	philosopher->time_to_eat = ft_atoul(argv[3]);
	philosopher->time_to_sleep = ft_atoul(argv[4]);
	philosopher->startMutex = &table->startMutex;
	philosopher->deathMutex = &table->deathMutex;
	philosopher->printMutex = &table->printMutex;
	philosopher->mealMutex = &table->mealMutex;
	philosopher->dinner_start_time = &table->dinner_start_time;
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

int	initialize_philosophers(t_table *table, char **argv)
{
	uint32_t	i;
	uint32_t	number_of_philosophers;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	i = 0;
	left_fork = malloc(sizeof(pthread_mutex_t));
	right_fork = malloc(sizeof(pthread_mutex_t));
	number_of_philosophers = ft_atoui(argv[1]);
	pthread_mutex_lock(&table->startMutex);
	while (i < number_of_philosophers)
	{
		left_fork = table->forks[i];
		if (number_of_philosophers == 1)
			right_fork = NULL;
		else if (i + 1 == number_of_philosophers)
			right_fork = table->forks[0];
		else
			right_fork = table->forks[i + 1];
		table->philosophers[i] = initialize_philosopher(i + 1, argv, left_fork, right_fork, table);
		if (table->philosophers[i] == NULL)
		{
			//! HANDLE ERROR AND FREE ALL PREVIOUSLY CREATED PHILOSOPHERS
			return (1);
		}
		i++;
	}
	table->dinner_start_time = get_current_time_in_milliseconds();
	pthread_mutex_unlock(&table->startMutex);
	table->philosophers[i] = NULL;
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

int	initialize_forks(t_table *table, char **argv)
{
	uint32_t	i;
	uint32_t	number_of_philosophers;

	i = 0;
	number_of_philosophers = ft_atoui(argv[1]);
	while (i < number_of_philosophers)
	{
		table->forks[i] = initialize_fork();
		if (table->forks[i] == NULL)
		{
			//! HANDLE ERROR AND FREE ALL PREVIOUSLY CREATED PHILOSOPHERS
			return (1);
		}
		pthread_mutex_init(table->forks[i], NULL);
		i++;
	}
	table->forks[i] = NULL;
	return (0);
}

int	deinitialize_forks(t_table *table)
{
	int	i;

	i = 0;
	while (table->forks[i] != NULL)
	{
		//! HANDLE RETURN ERROR
		pthread_mutex_destroy(table->forks[i]);
		i++;
	}
	return (0);
}

int	deinitialize_philosophers(t_table *table)
{
	int	i;

	i = 0;
	while (table->philosophers[i] != NULL)
	{
		if (pthread_join(table->philosophers[i]->thread, NULL))
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
		{
			pthread_mutex_lock(philosophers[i]->deathMutex);
			action(DIE, *philosophers[i]->dinner_start_time, philosophers[i]);
			pthread_mutex_unlock(philosophers[i]->deathMutex);
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_all_philosophers_full(t_philosopher **philosophers)
{
	int	i;

	i = 0;
	while (philosophers[i] != NULL)
	{
		pthread_mutex_lock(philosophers[i]->mealMutex);
		if (philosophers[i]->number_of_meals != 0)
		{
			pthread_mutex_unlock(philosophers[i]->mealMutex);
			return (0);
		}
		pthread_mutex_unlock(philosophers[i]->mealMutex);
		i++;
	}
	return (1);
}

void	*waiter_routine(t_table *table)
{
	while (1)
	{
		if (!is_all_philosophers_alive(table->philosophers))
		{
			printf("DIED\n");
			break ;
		}
		if (is_all_philosophers_full(table->philosophers))
			break ;
	}
	pthread_mutex_lock(&table->deathMutex);
	table->is_someone_dead = 1;
	pthread_mutex_unlock(&table->deathMutex);

	return (NULL);
}

// int	initialize_waiter(pthread_t	*waiter, t_table *table)
// {
// 	if (pthread_create(waiter, NULL, waiter_routine, table) != 0)
// 	{
// 		//! HANDLE ERROR
// 		printf("ERROR WAITER CREATION\n");
// 		return (1);
// 	}
// 	return (0);
// }

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
	// pthread_t	waiter;
	t_table	table;

	if (validate_arguments(argc, argv))
		return (1);
	if (initialize_table(&table, argv))
		return (2);
	if (initialize_forks(&table, argv))
		return (3);
	// if (initialize_waiter(&waiter, &table))
	// 	return (4);
	if (initialize_philosophers(&table, argv))
		return (5);

	waiter_routine(&table);
	// if (deinitialize_waiter(waiter))
	// 	return (6);
	if (deinitialize_philosophers(&table))
		return (7);
	if (deinitialize_forks(&table))
		return (9);
	if (deinitialize_table(&table))
		return (10);
	return (0);
}
