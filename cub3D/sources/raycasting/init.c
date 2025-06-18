/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:10:07 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/18 17:25:52 by rzvir            ###   ########.fr       */
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

	ray->current_tile_x = game->pos_x;
	ray->current_tile_y = game->pos_y;

	ray->direction_x = calc_ray_direction(game->dir_x, game->camera_plane_x, x);
	ray->direction_y = calc_ray_direction(game->dir_y, game->camera_plane_y, x);

	ray->step_direction_x = calc_step_direction(ray->direction_x);
	ray->step_direction_y = calc_step_direction(ray->direction_y);

	ray->current_length_x = calc_ray_distance(ray->direction_x);
	ray->current_length_y = calc_ray_distance(ray->direction_y);

	ray->total_length_x = calc_total_ray_distance(ray->direction_x, ray->current_length_x, game->pos_x, ray->current_tile_x);
	ray->total_length_y = calc_total_ray_distance(ray->direction_y, ray->current_length_y, game->pos_y, ray->current_tile_y);

	ray->length_to_wall = 0.0;
}
