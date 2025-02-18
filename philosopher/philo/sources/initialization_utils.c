/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:51:03 by rzvir             #+#    #+#             */
/*   Updated: 2025/02/18 15:51:20 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_forks(t_philosopher *philosopher,
	pthread_mutex_t *forks, size_t seat, size_t number_of_philosophers)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	left_fork = &forks[seat];
	if (number_of_philosophers == 1)
		right_fork = NULL;
	else if (seat + 1 == number_of_philosophers)
		right_fork = &forks[0];
	else
		right_fork = &forks[seat + 1];
	philosopher->left_fork = left_fork;
	philosopher->right_fork = right_fork;
}

void	set_number_of_meals(t_table *table, char **argv)
{
	if (argv[5] == NULL)
		table->number_of_meals = -1;
	else
		table->number_of_meals = ft_atoi(argv[5]);
}
