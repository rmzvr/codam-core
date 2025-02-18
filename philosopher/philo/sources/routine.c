/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:19:32 by rmzvr             #+#    #+#             */
/*   Updated: 2025/02/18 19:11:07 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait(long time_to_wait)
{
	long	time_to_work;

	time_to_work = get_current_time_in_milliseconds() + time_to_wait;
	while (get_current_time_in_milliseconds() <= time_to_work)
		usleep(500);
}

static int	eating(t_philosopher *philosopher)
{
	if (handle_mutex(philosopher->left_fork, LOCK))
		return (-1);
	if (action(TAKE, *philosopher->dinner_start_time, philosopher))
		return (1);
	if (handle_mutex(philosopher->right_fork, LOCK))
		return (-1);
	if (action(TAKE, *philosopher->dinner_start_time, philosopher))
		return (1);
	if (handle_mutex(philosopher->meal_mutex, LOCK))
		return (-1);
	philosopher->last_meal_time = get_current_time_in_milliseconds();
	philosopher->number_of_meals -= 1;
	if (handle_mutex(philosopher->meal_mutex, UNLOCK))
		return (-1);
	if (action(EAT, *philosopher->dinner_start_time, philosopher))
		return (1);
	wait(philosopher->time_to_eat);
	if (handle_mutex(philosopher->left_fork, UNLOCK))
		return (-1);
	if (handle_mutex(philosopher->right_fork, UNLOCK))
		return (-1);
	return (0);
}

static int	sleeping(t_philosopher *philosopher)
{
	if (action(SLEEP, *philosopher->dinner_start_time, philosopher))
		return (1);
	wait(philosopher->time_to_sleep);
	return (0);
}

static int	thinking(t_philosopher *philosopher)
{
	if (action(THINK, *philosopher->dinner_start_time, philosopher))
		return (1);
	return (0);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *) arg;
	if (handle_mutex(philosopher->start_mutex, LOCK))
		return (NULL);
	if (handle_mutex(philosopher->start_mutex, UNLOCK))
		return (NULL);
	if (philosopher->seat % 2)
		wait(philosopher->time_to_eat / 2);
	while (1)
	{
		if (philosopher->right_fork == NULL)
		{
			wait(philosopher->time_to_die);
			if (check_death(philosopher))
				return (NULL);
		}
		if (eating(philosopher))
			return (NULL);
		if (sleeping(philosopher))
			return (NULL);
		if (thinking(philosopher))
			return (NULL);
	}
	return (NULL);
}
