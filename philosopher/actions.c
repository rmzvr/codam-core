/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:33:44 by rmzvr             #+#    #+#             */
/*   Updated: 2025/02/18 12:38:39 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	action(t_action action, long dinner_start_time, t_philosopher *philosopher)
{
	long	current_time;
	long	difference;

	if (handle_mutex(philosopher->print_mutex, LOCK))
		return (1);
	current_time = get_current_time_in_milliseconds();
	difference = current_time - dinner_start_time;
	if (action == TAKE)
		printf("%ld %ld has taken a fork\n", difference, philosopher->seat);
	else if (action == EAT)
		printf("%ld %ld is eating\n", difference, philosopher->seat);
	else if (action == SLEEP)
		printf("%ld %ld is sleeping\n", difference, philosopher->seat);
	else if (action == THINK)
		printf("%ld %ld is thinking\n", difference, philosopher->seat);
	else if (action == DIE)
		printf("%ld %ld died\n", difference, philosopher->seat);
	if (handle_mutex(philosopher->print_mutex, UNLOCK))
		return (1);
	return (0);
}
