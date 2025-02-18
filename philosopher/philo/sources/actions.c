/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:33:44 by rmzvr             #+#    #+#             */
/*   Updated: 2025/02/18 16:23:07 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	action(t_action action, long dinner_start_time, t_philosopher *philosopher)
{
	long	current_time;
	long	elapsed_time;

	if (check_death(philosopher))
		return (1);
	if (handle_mutex(philosopher->print_mutex, LOCK))
		return (-1);
	current_time = get_current_time_in_milliseconds();
	elapsed_time = current_time - dinner_start_time;
	if (action == TAKE)
		printf("%ld %ld has taken a fork\n", elapsed_time, philosopher->seat);
	else if (action == EAT)
		printf("%ld %ld is eating\n", elapsed_time, philosopher->seat);
	else if (action == SLEEP)
		printf("%ld %ld is sleeping\n", elapsed_time, philosopher->seat);
	else if (action == THINK)
		printf("%ld %ld is thinking\n", elapsed_time, philosopher->seat);
	else if (action == DIE)
		printf("%ld %ld died\n", elapsed_time, philosopher->seat);
	if (handle_mutex(philosopher->print_mutex, UNLOCK))
		return (-1);
	return (0);
}
