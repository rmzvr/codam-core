/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:18:17 by rmzvr             #+#    #+#             */
/*   Updated: 2025/02/18 12:37:46 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_mutex(pthread_mutex_t *mutex, t_mutex_action action)
{
	int	return_code;

	return_code = 0;
	if (action == INIT)
		return_code = handle_mutex_error(pthread_mutex_init(mutex, NULL), INIT);
	else if (action == DESTROY)
		return_code = handle_mutex_error(pthread_mutex_destroy(mutex), DESTROY);
	else if (action == LOCK)
		return_code = handle_mutex_error(pthread_mutex_lock(mutex), LOCK);
	else if (action == UNLOCK)
		return_code = handle_mutex_error(pthread_mutex_unlock(mutex), UNLOCK);
	return (return_code);
}

int	handle_thread(pthread_t *thread, void *(*routine)(void *),
		void *arg, t_thread_action action)
{
	int	return_code;

	return_code = 0;
	if (action == CREATE)
		return_code = handle_thread_error(
				pthread_create(thread, NULL, routine, arg), CREATE
				);
	else if (action == JOIN)
		return_code = handle_thread_error(pthread_join(*thread, NULL), JOIN);
	return (return_code);
}
