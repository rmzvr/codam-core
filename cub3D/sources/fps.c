/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:23:22 by rmzvr             #+#    #+#             */
/*   Updated: 2025/06/26 22:24:34 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "main.h"

static double	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec + tv.tv_usec / 1000000.0);
}

void	set_time_since_last_frame(
	double *time_since_last_frame
)
{
	static double	previous_time;
	double			current_time;

	current_time = get_time();
	*time_since_last_frame = current_time - previous_time;
	previous_time = current_time;
}
