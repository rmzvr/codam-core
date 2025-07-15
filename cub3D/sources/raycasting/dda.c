/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:01:46 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/15 12:55:08 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	move_to_next_tile_side(
	t_ray *ray
)
{
	if (ray->total_length_x < ray->total_length_y)
	{
		ray->total_length_x += ray->current_length_x;
		ray->current_tile_x += ray->step_direction_x;
		ray->hit_side = VERTICAL;
	}
	else if (ray->total_length_x > ray->total_length_y)
	{
		ray->total_length_y += ray->current_length_y;
		ray->current_tile_y += ray->step_direction_y;
		ray->hit_side = HORIZONTAL;
	}
}

void	check_wall_hit(
	t_ray *ray
)
{
	if (map[ray->current_tile_y][ray->current_tile_x] == 1)
	{
		ray->hit = TRUE;
	}
}

void	trace_ray_to_wall(
	t_ray *ray
)
{
	while (ray->hit == FALSE)
	{
		move_to_next_tile_side(ray);
		check_wall_hit(ray);
	}
}

void	render_frame(
	t_game *game
)
{
	int		x;
	t_ray	ray;
	t_wall	wall;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		initialize_ray(x, &ray, game);
		initialize_wall(&wall);
		trace_ray_to_wall(&ray);
		initialize_textures(&ray, game);
		draw_vertical_stripe(x, &ray, &wall, game);
		x++;
	}
	mlx_put_image_to_window(
		game->mlx.ptr, game->mlx.win_ptr, game->mlx.img.ptr, 0, 0);
}
