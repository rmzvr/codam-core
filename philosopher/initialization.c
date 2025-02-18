/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:19:52 by rmzvr             #+#    #+#             */
/*   Updated: 2025/02/18 12:40:46 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_forks(t_philosopher *philosopher,
	pthread_mutex_t *forks, size_t seat, size_t number_of_philosophers)
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

static void	set_number_of_meals(t_table *table, char **argv)
{
	if (argv[5] == NULL)
		table->number_of_meals = -1;
	else
		table->number_of_meals = ft_atoi(argv[5]);
}

int	initialize_philosopher(t_philosopher *philosopher,
	size_t seat, char **argv, t_table *table)
{
	philosopher->seat = seat;
	philosopher->time_to_die = ft_atol(argv[2]);
	philosopher->time_to_eat = ft_atol(argv[3]);
	philosopher->time_to_sleep = ft_atol(argv[4]);
	philosopher->meal_mutex = &table->meal_mutex;
	philosopher->start_mutex = &table->start_mutex;
	philosopher->death_mutex = &table->death_mutex;
	philosopher->print_mutex = &table->print_mutex;
	philosopher->is_someone_dead = &table->is_someone_dead;
	philosopher->dinner_start_time = &table->dinner_start_time;
	philosopher->last_meal_time = get_current_time_in_milliseconds();
	if (argv[5] == NULL)
		philosopher->number_of_meals = -1;
	else
		philosopher->number_of_meals = ft_atoi(argv[5]);
	if (handle_thread(
			&philosopher->thread, philosopher_routine, philosopher, CREATE))
		return (1);
	return (0);
}

int	initialize_philosophers(t_table *table, char **argv)
{
	size_t			i;
	size_t			number_of_philosophers;
	t_philosopher	*philosopher;

	i = 0;
	number_of_philosophers = table->number_of_philosophers;
	if (handle_mutex(&table->start_mutex, LOCK))
		return (1);
	while (i < number_of_philosophers)
	{
		philosopher = table->philosophers + i;
		initialize_philosopher(philosopher, i + 1, argv, table);
		get_forks(philosopher, table->forks, i, number_of_philosophers);
		i++;
	}
	table->dinner_start_time = get_current_time_in_milliseconds();
	if (handle_mutex(&table->start_mutex, UNLOCK))
		return (1);
	return (0);
}

int	initialize_table(t_table *table, char **argv)
{
	size_t	i;
	size_t	number_of_philosophers;

	i = 0;
	table->is_someone_dead = 0;
	set_number_of_meals(table, argv);
	table->dinner_start_time = -1;
	number_of_philosophers = ft_atoi(argv[1]);
	table->number_of_philosophers = number_of_philosophers;
	table->philosophers = malloc(
			(number_of_philosophers) * sizeof(t_philosopher));
	if (table->philosophers == NULL)
		return (show_malloc_error(1));
	table->forks = malloc((number_of_philosophers) * sizeof(pthread_mutex_t));
	if (table->forks == NULL)
		return (show_malloc_error(1));
	while (i < number_of_philosophers)
	{
		if (handle_mutex(&table->forks[i], INIT))
			return (1);
		i++;
	}
	if (handle_mutex(&table->meal_mutex, INIT))
		return (1);
	if (handle_mutex(&table->start_mutex, INIT))
		return (1);
	if (handle_mutex(&table->death_mutex, INIT))
		return (1);
	if (handle_mutex(&table->print_mutex, INIT))
		return (1);
	return (0);
}
