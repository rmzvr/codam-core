/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:06:49 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/16 18:00:15 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	calc_distance_to_wall(
	t_dda_data *dda_data,
	t_ray_trace_data *ray_trace_data
)
{
	if (dda_data->hit_side == VERTICAL)
	{
		dda_data->distance_to_wall = (ray_trace_data->total_ray_distance_x - ray_trace_data->ray_distance_x);
	}
	else
	{
		dda_data->distance_to_wall = (ray_trace_data->total_ray_distance_y - ray_trace_data->ray_distance_y);
	}
}

void	calc_wall_color(
	t_dda_data *dda_data
)
{
	if (dda_data->hit_side == VERTICAL)
	{
		if (dda_data->step_direction_x == 1)
			dda_data->wall_color = 0xFF0000;
		else
			dda_data->wall_color = 0x00FF00;
	}
	else
	{
		if (dda_data->step_direction_y == 1)
			dda_data->wall_color = 0x0000FF;
		else
			dda_data->wall_color = 0xFFFF00;
	}
}

void	calc_wall_height(
	t_dda_data *dda_data
)
{
	int	wall_height;

	wall_height = (int)(WINDOW_HEIGHT / dda_data->distance_to_wall);
	dda_data->wall_start = -wall_height / 2 + WINDOW_HEIGHT / 2;
	if (dda_data->wall_start < 0)
	{
		dda_data->wall_start = 0;
	}
	dda_data->wall_end = wall_height / 2 + WINDOW_HEIGHT / 2;
	if (dda_data->wall_end >= WINDOW_HEIGHT)
	{
		dda_data->wall_end = MAX_WINDOW_Y;
	}
}
