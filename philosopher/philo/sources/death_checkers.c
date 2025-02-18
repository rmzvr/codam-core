/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:46:12 by rzvir             #+#    #+#             */
/*   Updated: 2025/02/18 18:55:22 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philosopher *philosopher)
{
	if (handle_mutex(philosopher->death_mutex, LOCK))
		return (-1);
	if (*philosopher->is_someone_dead)
	{
		if (handle_mutex(philosopher->death_mutex, UNLOCK))
			return (-1);
		return (1);
	}
	if (handle_mutex(philosopher->death_mutex, UNLOCK))
		return (-1);
	return (0);
}

int	is_philosopher_dead(t_philosopher *philosopher)
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

int	is_someone_dead(t_philosopher *philosophers,
		size_t number_of_philosophers)
{
	size_t			i;
	t_philosopher	*philosopher;
	long			dinner_start_time;

	i = 0;
	while (i < number_of_philosophers)
	{
		philosopher = philosophers + i;
		dinner_start_time = *(philosophers + i)->dinner_start_time;
		if (is_philosopher_dead(philosopher))
		{
			action(DIE, dinner_start_time, philosopher);
			return (1);
		}
		i++;
	}
	return (0);
}
