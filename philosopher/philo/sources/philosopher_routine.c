/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:19:32 by rmzvr             #+#    #+#             */
/*   Updated: 2025/02/19 11:33:12 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	sleeping(t_philosopher *philosopher)
{
	if (check_death(philosopher))
		return (1);
	if (action(SLEEP, *philosopher->dinner_start_time, philosopher))
		return (1);
	wait(philosopher->time_to_sleep);
	return (0);
}

static int	thinking(t_philosopher *philosopher)
{
	if (check_death(philosopher))
		return (1);
	if (action(THINK, *philosopher->dinner_start_time, philosopher))
		return (1);
	return (0);
}

void	wait(long time_to_wait)
{
	long	time_to_work;

	time_to_work = get_current_time_in_milliseconds() + time_to_wait;
	while (get_current_time_in_milliseconds() <= time_to_work)
		usleep(500);
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
