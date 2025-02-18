/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:24:06 by rmzvr             #+#    #+#             */
/*   Updated: 2025/02/18 16:02:03 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	waiter_routine(t_table *table)
{
	int	is_one_dead;
	int	is_all_full;

	while (1)
	{
		is_one_dead = is_someone_dead(table->philosophers,
				table->number_of_philosophers);
		if (is_one_dead == -1)
			return (-1);
		if (is_one_dead == 1)
			break ;
		is_all_full = is_all_philosophers_full(table->philosophers,
				table->number_of_philosophers);
		if (is_all_full == -1)
			return (-1);
		if (table->number_of_meals > 0 && is_all_full == 1)
			break ;
		usleep(1000);
	}
	if (handle_mutex(&table->death_mutex, LOCK))
		return (-1);
	table->is_someone_dead = 1;
	if (handle_mutex(&table->death_mutex, UNLOCK))
		return (-1);
	return (0);
}
