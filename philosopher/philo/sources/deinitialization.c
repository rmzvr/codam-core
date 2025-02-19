/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deinitialization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:26:02 by rmzvr             #+#    #+#             */
/*   Updated: 2025/02/19 11:29:23 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	deinitialize_table(t_table *table)
{
	if (handle_mutex(&table->meal_mutex, DESTROY))
		return (1);
	if (handle_mutex(&table->start_mutex, DESTROY))
		return (1);
	if (handle_mutex(&table->death_mutex, DESTROY))
		return (1);
	if (handle_mutex(&table->print_mutex, DESTROY))
		return (1);
	return (0);
}

int	deinitialize_philosophers(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (handle_thread(&table->philosophers[i].thread, NULL, NULL, JOIN))
			return (1);
		i++;
	}
	free(table->philosophers);
	table->philosophers = NULL;
	return (0);
}

int	deinitialize_forks(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (handle_mutex(&table->forks[i], DESTROY))
			return (1);
		i++;
	}
	free(table->forks);
	table->forks = NULL;
	return (0);
}
