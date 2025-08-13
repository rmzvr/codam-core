/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:18:54 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/24 13:47:20 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer_bonus.h"

static int	get_step_direction(
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

static double	get_total_ray_distance(
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

static double	get_current_ray_distance(
	double ray_direction
)
{
	double	ray_distance;

	ray_distance = INFINITY;
	if (ray_direction != 0)
	{
		ray_distance = fabs(1.0 / ray_direction);
	}
	return (ray_distance);
}

static double	get_ray_direction(
	int x,
	double camera_plane,
	double player_direction
)
{
	double	normalized_screen_x;
	double	ray_direction;

	normalized_screen_x = (2 * x / (double)WINDOW_WIDTH) - 1;
	ray_direction = player_direction + camera_plane * normalized_screen_x;
	return (ray_direction);
}

void	initialize_ray(
	int x,
	t_ray *ray,
	t_player *player
)
{
	ray->hit = FALSE;
	ray->hit_side = VERTICAL;
	ray->current_tile_x = player->position.x;
	ray->current_tile_y = player->position.y;
	ray->direction_x = get_ray_direction(
			x, player->plane.x, player->direction.x);
	ray->direction_y = get_ray_direction(
			x, player->plane.y, player->direction.y);
	ray->step_direction_x = get_step_direction(ray->direction_x);
	ray->step_direction_y = get_step_direction(ray->direction_y);
	ray->current_length_x = get_current_ray_distance(ray->direction_x);
	ray->current_length_y = get_current_ray_distance(ray->direction_y);
	ray->total_length_x = get_total_ray_distance(ray->direction_x,
			ray->current_length_x, player->position.x, ray->current_tile_x);
	ray->total_length_y = get_total_ray_distance(ray->direction_y,
			ray->current_length_y, player->position.y, ray->current_tile_y);
	ray->length_to_wall = 0.0;
}
