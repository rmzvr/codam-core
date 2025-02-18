/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:24:06 by rmzvr             #+#    #+#             */
/*   Updated: 2025/02/18 12:39:55 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_philosopher_dead(t_philosopher *philosopher)
{
	long	current_time;

	if (handle_mutex(philosopher->meal_mutex, LOCK))
		return (-1);
	current_time = get_current_time_in_milliseconds();
	if (current_time - philosopher->last_meal_time >= philosopher->time_to_die)
	{
		if (handle_mutex(philosopher->meal_mutex, UNLOCK))
			return (-1);
		return (1);
	}
	if (handle_mutex(philosopher->meal_mutex, UNLOCK))
		return (-1);
	return (0);
}

static int	is_someone_dead(t_philosopher *philosophers,
		size_t number_of_philosophers)
{
	size_t			i;
	t_philosopher	*philosopher;
	pthread_mutex_t	*death_mutex;
	long			dinner_start_time;

	i = 0;
	while (i < number_of_philosophers)
	{
		philosopher = philosophers + i;
		death_mutex = (philosophers + i)->death_mutex;
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

static int	is_all_philosophers_full(t_philosopher *philosophers,
		size_t number_of_philosophers)
{
	size_t			i;
	pthread_mutex_t	*meal_mutex;
	int				number_of_meals;

	i = 0;
	while (i < number_of_philosophers)
	{
		meal_mutex = (philosophers + i)->meal_mutex;
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

//! HANDLE -1
void	*waiter_routine(t_table *table)
{
	int	is_one_dead;
	int	is_all_full;

	while (1)
	{
		is_one_dead = is_someone_dead(table->philosophers,
				table->number_of_philosophers);
		if (is_one_dead == -1)
			return (NULL);
		if (is_one_dead)
			break ;
		is_all_full = is_all_philosophers_full(table->philosophers,
				table->number_of_philosophers);
		if (is_all_full == -1)
			return (NULL);
		if (table->number_of_meals > 0 && is_all_full)
			break ;
		usleep(5000);
	}
	if (handle_mutex(&table->death_mutex, LOCK))
		return (NULL);
	table->is_someone_dead = 1;
	if (handle_mutex(&table->death_mutex, UNLOCK))
		return (NULL);
	return (NULL);
}
