/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:06:49 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/26 22:07:23 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	calc_distance_to_wall(
	t_ray *ray
)
{
	if (ray->hit_side == VERTICAL)
	{
		ray->length_to_wall = (ray->total_length_x - ray->current_length_x);
	}
	else
	{
		ray->length_to_wall = (ray->total_length_y - ray->current_length_y);
	}
}

void	calc_wall_color(
	t_side hit_side,
	int step_direction_x,
	int step_direction_y,
	t_wall *wall
)
{
	if (hit_side == VERTICAL)
	{
		if (step_direction_x == 1)
			wall->color = 0xFF0000;
		else
			wall->color = 0x00FF00;
	}
	else
	{
		if (step_direction_y == 1)
			wall->color = 0x0000FF;
		else
			wall->color = 0xFFFF00;
	}
}

void	calc_wall_height(
	t_wall *wall,
	double length_to_wall
)
{
	wall->height = (int)(WINDOW_HEIGHT / length_to_wall);
	wall->start = -wall->height / 2 + WINDOW_Y_CENTER;
	if (wall->start < 0)
	{
		wall->start = 0;
	}
	wall->end = wall->height / 2 + WINDOW_Y_CENTER;
	if (wall->end >= WINDOW_HEIGHT)
	{
		wall->end = MAX_WINDOW_Y;
	}
}
