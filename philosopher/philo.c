/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:19:15 by rzvir             #+#    #+#             */
/*   Updated: 2025/02/16 23:14:36 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_mutex(pthread_mutex_t *mutex, t_mutex_action action)
{
	int	return_code;

	return_code = 0;
	if (action == INIT)
		return_code = handle_mutex_error(pthread_mutex_init(mutex, NULL), INIT);
	else if (action == DESTROY)
		return_code = handle_mutex_error(pthread_mutex_destroy(mutex), DESTROY);
	else if (action == LOCK)
		return_code = handle_mutex_error(pthread_mutex_lock(mutex), LOCK);
	else if (action == UNLOCK)
		return_code = handle_mutex_error(pthread_mutex_unlock(mutex), UNLOCK);
	return (return_code);
}

int	handle_thread(pthread_t *thread, void *(*routine)(void *), void *arg)
{
	int	return_code;

	return_code = 0;
	if (action == CREATE)
		return_code = handle_thread_error(pthread_create(thread, NULL, routine, arg), CREATE);
	else if (action == JOIN)
		return_code = handle_thread_error(pthread_join(*thread, NULL), JOIN);
	return (return_code);
}

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
	current_time = get_current_time_in_milliseconds();
	if (current_time - philosopher->last_meal_time >= philosopher->time_to_die)
	{
		pthread_mutex_unlock(philosopher->mealMutex);
		return (1);
	}
	pthread_mutex_unlock(philosopher->mealMutex);
	return (0);
}

void	wait(uint64_t time_to_wait)
{
	uint64_t	time_to_work;

	time_to_work = get_current_time_in_milliseconds() + time_to_wait;
	while (get_current_time_in_milliseconds() <= time_to_work)
		usleep(500);
}

void	action(t_action action, uint64_t dinner_start, t_philosopher *philosopher)
{
	uint64_t	milliseconds;

	pthread_mutex_lock(philosopher->printMutex);
	milliseconds = get_current_time_in_milliseconds();
	if (action == TAKE)
		printf("%ld %d has taken a fork\n", milliseconds - dinner_start, philosopher->seat);
	else if (action == EAT)
		printf("%ld %d is eating\n", milliseconds - dinner_start, philosopher->seat);
	else if (action == SLEEP)
		printf("%ld %d is sleeping\n", milliseconds - dinner_start, philosopher->seat);
	else if (action == THINK)
		printf("%ld %d is thinking\n", milliseconds - dinner_start, philosopher->seat);
	else if (action == DIE)
		printf("%ld %d died\n", milliseconds - dinner_start, philosopher->seat);
	pthread_mutex_unlock(philosopher->printMutex);
}

int	check_death(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->deathMutex);
	if (*philosopher->is_someone_dead)
	{
		pthread_mutex_unlock(philosopher->deathMutex);
		return (1);
	}
	pthread_mutex_unlock(philosopher->deathMutex);
	return (0);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *) arg;
	pthread_mutex_lock(philosopher->startMutex);
	pthread_mutex_unlock(philosopher->startMutex);
	if (philosopher->seat % 2)
		wait(philosopher->time_to_eat / 2);
	while (1)
	{
		if (philosopher->right_fork == NULL)
			wait(philosopher->time_to_die);

		if (check_death(philosopher))
			return (NULL);

		pthread_mutex_lock(philosopher->left_fork);

		pthread_mutex_lock(philosopher->right_fork);

		if (check_death(philosopher))
		{
			pthread_mutex_unlock(philosopher->left_fork);
			pthread_mutex_unlock(philosopher->right_fork);
			return (NULL);
		}

		action(TAKE, *philosopher->dinner_start_time, philosopher);
		action(TAKE, *philosopher->dinner_start_time, philosopher);

		pthread_mutex_lock(philosopher->mealMutex);
		philosopher->last_meal_time = get_current_time_in_milliseconds();
		philosopher->number_of_meals -= 1;
		pthread_mutex_unlock(philosopher->mealMutex);

		action(EAT, *philosopher->dinner_start_time, philosopher);
		wait(philosopher->time_to_eat);

		if (check_death(philosopher))
		{
			pthread_mutex_unlock(philosopher->left_fork);
			pthread_mutex_unlock(philosopher->right_fork);
			return (NULL);
		}

		pthread_mutex_unlock(philosopher->left_fork);
		pthread_mutex_unlock(philosopher->right_fork);

		if (check_death(philosopher))
			return (NULL);

		action(SLEEP, *philosopher->dinner_start_time, philosopher);
		wait(philosopher->time_to_sleep);

		if (check_death(philosopher))
			return (NULL);

		action(THINK, *philosopher->dinner_start_time, philosopher);
	}
	return (NULL);
}

int	initialize_table(t_table *table, char **argv)
{
	size_t	i;
	size_t	number_of_philosophers;

	i = 0;
	table->is_someone_dead = 0;
	table->dinner_start_time = -1;
	number_of_philosophers = ft_atoui(argv[1]);
	table->number_of_philosophers = number_of_philosophers;
	table->philosophers = malloc((number_of_philosophers) * sizeof(t_philosopher));
	if (table->philosophers == NULL)
	{
		//! HANDLE ERROR
		return (1);
	}
	table->forks = malloc((number_of_philosophers) * sizeof(pthread_mutex_t));
	if (table->forks == NULL)
	{
		//! HANDLE ERROR
		return (1);
	}
	while (i < number_of_philosophers)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->mealMutex, NULL);
	pthread_mutex_init(&table->startMutex, NULL);
	pthread_mutex_init(&table->deathMutex, NULL);
	pthread_mutex_init(&table->printMutex, NULL);
	return (0);
}

int	deinitialize_table(t_table *table)
{
	pthread_mutex_destroy(&table->startMutex);
	pthread_mutex_destroy(&table->mealMutex);
	pthread_mutex_destroy(&table->deathMutex);
	pthread_mutex_destroy(&table->printMutex);
	return (0);
}

void	get_forks(t_philosopher *philosopher, pthread_mutex_t *forks, size_t seat, size_t number_of_philosophers)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	left_fork = &forks[seat];
	if (number_of_philosophers == 1)
		right_fork = NULL;
	else if (seat + 1 == number_of_philosophers)
		right_fork = &forks[0];
	else
		right_fork = &forks[seat + 1];
	philosopher->left_fork = left_fork;
	philosopher->right_fork = right_fork;
}

void	initialize_philosopher(t_philosopher *philosopher, size_t seat, char **argv, t_table *table)
{
	philosopher->seat = seat;
	philosopher->time_to_die = ft_atoul(argv[2]);
	philosopher->time_to_eat = ft_atoul(argv[3]);
	philosopher->time_to_sleep = ft_atoul(argv[4]);
	philosopher->startMutex = &table->startMutex;
	philosopher->deathMutex = &table->deathMutex;
	philosopher->printMutex = &table->printMutex;
	philosopher->mealMutex = &table->mealMutex;
	philosopher->is_someone_dead = &table->is_someone_dead;
	philosopher->dinner_start_time = &table->dinner_start_time;
	philosopher->last_meal_time = get_current_time_in_milliseconds();
	if (argv[5] == NULL)
		philosopher->number_of_meals = -1;
	else
		philosopher->number_of_meals = ft_atoui(argv[5]);

	if (pthread_create(&philosopher->thread, NULL, philosopher_routine, philosopher))
	{
		//! HANDLE ERROR
		printf("ERROR THREAD CREATION\n");
		// return (NULL);
	}
}

int	initialize_philosophers(t_table *table, char **argv)
{
	size_t			i;
	size_t			number_of_philosophers;
	t_philosopher	*philosopher;

	i = 0;
	number_of_philosophers = table->number_of_philosophers;
	if (handle_mutex(&table->startMutex, LOCK))
	return (1);
	while (i < number_of_philosophers)
	{
		philosopher = table->philosophers + i;
		initialize_philosopher(philosopher, i + 1, argv, table);
		get_forks(philosopher, table->forks, i, number_of_philosophers);
		i++;
	}
	table->dinner_start_time = get_current_time_in_milliseconds();
	if (handle_mutex(&table->startMutex, UNLOCK))
		return (1);
	return (0);
}

int	deinitialize_philosophers(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (pthread_join(table->philosophers[i].thread, NULL))
		{
			printf("Error occurred while join philosopher %ld\n", i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_someone_dead(t_philosopher *philosophers, size_t number_of_philosophers)
{
	size_t	i;
	t_philosopher	*philosopher;
	pthread_mutex_t	*death_mutex;
	uint64_t		dinner_start_time;

	i = 0;
	while (i < number_of_philosophers)
	{
		philosopher = philosophers + i;
		death_mutex = (philosophers + i)->deathMutex;
		dinner_start_time = *(philosophers + i)->dinner_start_time;
		if (is_philosopher_dead(philosopher))
		{
			if (handle_mutex(death_mutex, LOCK))
				return (-1);
			action(DIE, dinner_start_time, philosopher);
			if (handle_mutex(death_mutex, UNLOCK))
				return (-1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_all_philosophers_full(t_philosopher *philosophers, size_t number_of_philosophers)
{
	size_t			i;
	pthread_mutex_t	*meal_mutex;
	int				number_of_meals;

	i = 0;
	while (i < number_of_philosophers)
	{
		meal_mutex = (philosophers + i)->mealMutex;
		number_of_meals = (philosophers + i)->number_of_meals;
		if (handle_mutex(meal_mutex, LOCK))
			return (-1);
		if (number_of_meals > 0)
		{
			if (handle_mutex(meal_mutex, UNLOCK))
				return (-1);
			return (0);
		}
		if (handle_mutex(meal_mutex, UNLOCK))
			return (-1);
		i++;
	}
	return (1);
}

void	*waiter_routine(t_table *table)
{
	int	is_all_full;
	int	is_one_dead;

	while (1)
	{
		is_one_dead = is_someone_dead(table->philosophers, table->number_of_philosophers);
		if (is_one_dead == -1)
			return (NULL);
		if (is_someone_dead(table->philosophers, table->number_of_philosophers))
			break ;
		is_all_full = is_all_philosophers_full(table->philosophers, table->number_of_philosophers);
		if (is_all_full == -1)
			return (NULL);
		if (table->philosophers[0].number_of_meals >= 0 && is_all_full)
			break ;
		usleep(1000);
	}
	if (handle_mutex(&table->deathMutex, LOCK))
		return (NULL);
	table->is_someone_dead = 1;
	if (handle_mutex(&table->deathMutex, UNLOCK))
		return (NULL);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (validate_arguments(argc, argv))
		return (1);
	if (initialize_table(&table, argv))
		return (1);
	if (initialize_philosophers(&table, argv))
		return (1);
	waiter_routine(&table);
	if (deinitialize_philosophers(&table))
		return (1);
	if (deinitialize_table(&table))
		return (1);
	return (0);
}
