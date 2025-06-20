/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:01:46 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/20 17:58:33 by rzvir            ###   ########.fr       */
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
	t_ray *ray,
	t_game *game
)
{
	(void)game;
	while (ray->hit == FALSE)
	{
		move_to_next_tile_side(ray);
		check_wall_hit(ray);
	}
}

void	print_ray_debug(t_game *game, t_ray *ray, int x)
{
	printf("=== RAY DEBUG INFO (x = %d) ===\n", x);
	printf("Player pos:         (%.2f, %.2f)\n", game->pos_x, game->pos_y);
	printf("Ray direction:      (%.4f, %.4f)\n", ray->direction_x, ray->direction_y);
	printf("Ray step direction: (%.0d, %.0d)\n", ray->step_direction_x, ray->step_direction_y);
	printf("Current tile:       (%d, %d)\n", ray->current_tile_x, ray->current_tile_y);
	printf("Initial distances:  X = %.4f, Y = %.4f\n", ray->current_length_x, ray->current_length_y);
	printf("Total distances:    X = %.4f, Y = %.4f\n", ray->total_length_x, ray->total_length_y);
	printf("Hit:                %s\n", ray->hit ? "TRUE" : "FALSE");
	printf("Hit side:           %s\n", ray->hit_side == VERTICAL ? "VERTICAL" : "HORIZONTAL");
	printf("Length to wall:     %.4f\n", ray->length_to_wall);
	printf("================================\n");
}

void	render_frame_with_ray_casting(
	t_game *game
)
{
	int					x;
	t_ray				ray;
	t_wall				wall;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		initialize_ray(x, &ray, game);
		initialize_wall(&wall);
		trace_ray_to_wall(&ray, game);
		if (ray.hit_side == VERTICAL)
		{
			if (ray.step_direction_x > 0)
				game->texture_data = &game->left_wall;
			else
				game->texture_data = &game->right_wall;
		}
		else
		{
			if (ray.step_direction_y > 0)
				game->texture_data = &game->front_wall;
			else
				game->texture_data = &game->front_wall;
		}
		draw_vertical_stripe(x, &ray, &wall, game, game->texture_data);
		x++;
	}
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr, game->mlx.img.ptr, 0, 0);
}
