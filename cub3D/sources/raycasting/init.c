/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:10:07 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/15 14:46:05 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	initialize_wall(
	t_wall *wall
)
{
	wall->start = 0;
	wall->end = 0;
	wall->color = 0x000000;
	wall->height = 0;
}

void	initialize_ray(
	int x,
	t_ray *ray,
	t_game *game
)
{
	ray->hit = FALSE;
	ray->hit_side = VERTICAL;
	ray->current_tile_x = game->position_x;
	ray->current_tile_y = game->position_y;
	ray->direction_x = calc_ray_direction(
			game->direction_x, game->plane_x, x);
	ray->direction_y = calc_ray_direction(
			game->direction_y, game->plane_y, x);
	ray->step_direction_x = calc_step_direction(ray->direction_x);
	ray->step_direction_y = calc_step_direction(ray->direction_y);
	ray->current_length_x = calc_ray_distance(ray->direction_x);
	ray->current_length_y = calc_ray_distance(ray->direction_y);
	ray->total_length_x = calc_total_ray_distance(
			ray->direction_x,
			ray->current_length_x,
			game->position_x,
			ray->current_tile_x
			);
	ray->total_length_y = calc_total_ray_distance(
			ray->direction_y,
			ray->current_length_y,
			game->position_y,
			ray->current_tile_y
			);
	ray->length_to_wall = 0.0;
}

void	initialize_textures(
	t_ray *ray,
	t_game *game
)
{
	if (ray->hit_side == VERTICAL)
	{
		if (ray->step_direction_x > 0)
		{
			game->texture_data = &game->left_wall;
		}
		else
		{
			game->texture_data = &game->right_wall;
		}
	}
	else
	{
		if (ray->step_direction_y > 0)
		{
			game->texture_data = &game->front_wall;
		}
		else
		{
			game->texture_data = &game->front_wall;
		}
	}
}
