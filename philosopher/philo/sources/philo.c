/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:19:15 by rzvir             #+#    #+#             */
/*   Updated: 2025/02/18 16:14:51 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (validate_arguments(argc, argv))
		return (1);
	if (initialize_table(&table, argv))
		return (1);
	if (initialize_philosophers(&table, argv))
		return (1);
	if (waiter_routine(&table))
		return (1);
	if (deinitialize_philosophers(&table))
		return (1);
	if (deinitialize_table(&table))
		return (1);
	return (0);
}
