/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deinitialization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:26:02 by rmzvr             #+#    #+#             */
/*   Updated: 2025/02/18 12:26:29 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	deinitialize_table(t_table *table)
{
	free(table->forks);
	free(table->philosophers);
	table->forks = NULL;
	table->philosophers = NULL;
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
	return (0);
}
