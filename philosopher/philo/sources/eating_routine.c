/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:31:05 by rzvir             #+#    #+#             */
/*   Updated: 2025/02/19 11:31:45 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philosopher *philosopher)
{
	if (handle_mutex(philosopher->left_fork, LOCK))
		return (-1);
	if (action(TAKE, *philosopher->dinner_start_time, philosopher))
		return (1);
	if (handle_mutex(philosopher->right_fork, LOCK))
		return (-1);
	if (check_death(philosopher))
	{
		handle_mutex(philosopher->left_fork, UNLOCK);
		handle_mutex(philosopher->right_fork, UNLOCK);
		return (1);
	}
	if (action(TAKE, *philosopher->dinner_start_time, philosopher))
		return (1);
	return (0);
}

int	put_forks(t_philosopher *philosopher)
{
	if (check_death(philosopher))
	{
		if (handle_mutex(philosopher->left_fork, UNLOCK))
			return (-1);
		if (handle_mutex(philosopher->right_fork, UNLOCK))
			return (-1);
		return (1);
	}
	if (handle_mutex(philosopher->left_fork, UNLOCK))
		return (-1);
	if (handle_mutex(philosopher->right_fork, UNLOCK))
		return (-1);
	return (0);
}

int	eating(t_philosopher *philosopher)
{
	if (take_forks(philosopher))
		return (1);
	if (handle_mutex(philosopher->meal_mutex, LOCK))
		return (-1);
	philosopher->last_meal_time = get_current_time_in_milliseconds();
	philosopher->number_of_meals -= 1;
	if (handle_mutex(philosopher->meal_mutex, UNLOCK))
		return (-1);
	if (check_death(philosopher))
	{
		handle_mutex(philosopher->left_fork, UNLOCK);
		handle_mutex(philosopher->right_fork, UNLOCK);
		return (1);
	}
	if (action(EAT, *philosopher->dinner_start_time, philosopher))
		return (1);
	wait(philosopher->time_to_eat);
	if (put_forks(philosopher))
		return (1);
	return (0);
}
