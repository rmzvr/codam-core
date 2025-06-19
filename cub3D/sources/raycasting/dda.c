/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:01:46 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/19 17:33:02 by rzvir            ###   ########.fr       */
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

void	init_texture_image(char *path, t_texture *texture, t_game *game)
{
	texture->xpm.path = path;
	texture->img.ptr = mlx_xpm_file_to_image(
		game->mlx.ptr,
		texture->xpm.path,
		&texture->xpm.width,
		&texture->xpm.height
	);
	if (texture->img.ptr == NULL)
	{
		perror("Image load failed");
	}
	texture->img.pixels_addr = mlx_get_data_addr(
		texture->img.ptr,
		&texture->img.bytes_per_pixel,
		&texture->img.line_length,
		&texture->img.endian
	);
}

void	render_frame_with_ray_casting(
	t_game *game
)
{
	int					x;
	t_ray				ray;
	t_wall				wall;
	t_texture			front_wall;
	t_texture			back_wall;
	t_texture			left_wall;
	t_texture			right_wall;
	t_texture			*texture_data;

	init_texture_image("textures/wall/front.xpm", &front_wall, game);
	init_texture_image("textures/wall/back.xpm", &back_wall, game);
	init_texture_image("textures/wall/left.xpm", &left_wall, game);
	init_texture_image("textures/wall/right.xpm", &right_wall, game);
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		initialize_ray(x, &ray, game);
		initialize_wall(&wall);
		trace_ray_to_wall(&ray, game);
		if (ray.hit_side == VERTICAL)
		{
			if (ray.step_direction_x == 1)
				texture_data = &left_wall;
			else
				texture_data = &right_wall;

		}
		else
		{
			if (ray.step_direction_y == 1)
				texture_data = &back_wall;
			else
				texture_data = &front_wall;

		}
		draw_vertical_stripe(x, &ray, &wall, game, texture_data);
		x++;
	}
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr, game->mlx.img.ptr, 0, 0);
}
