/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:03:33 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/15 12:37:29 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	calc_step_direction(
	double ray_direction
)
{
	int	step_direction;

	if (ray_direction < 0)
	{
		step_direction = -1;
	}
	else
	{
		step_direction = 1;
	}
	return (step_direction);
}

double	calc_total_ray_distance(
	double ray_direction,
	double ray_distance,
	double player_position,
	int current_tile
)
{
	double	tile_distance;

	if (ray_direction < 0)
	{
		tile_distance = (player_position - current_tile);
	}
	else
	{
		tile_distance = (current_tile + 1 - player_position);
	}
	return (tile_distance * ray_distance);
}

double	calc_ray_distance(
	double ray_direction
)
{
	double	ray_distance;

	ray_distance = INFINITY;
	if (ray_direction != 0)
	{
		ray_distance = fabs(1 / ray_direction);
	}
	return (ray_distance);
}

double	calc_ray_direction(
	double player_direction,
	double camera_plane,
	int x
)
{
	double	normalized_screen_x;
	double	ray_direction;

	normalized_screen_x = (2 * x / (double)WINDOW_WIDTH) - 1;
	ray_direction = player_direction + camera_plane * normalized_screen_x;
	return (ray_direction);
}
