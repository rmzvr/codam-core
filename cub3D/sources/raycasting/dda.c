/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:01:46 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/18 17:26:56 by rzvir            ###   ########.fr       */
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

void	init_texture_image(t_texture *texture, t_game *game)
{
	texture->xpm.path = "textures/wall.xpm";
	texture->img.ptr = mlx_xpm_file_to_image(
		game->mlx.ptr,
		texture->xpm.path,
		&texture->xpm.width,
		&texture->xpm.height
	);
}

void	render_frame_with_ray_casting(
	t_game *game
)
{
	int					x;
	t_ray				ray;
	t_wall				wall;
	t_texture			texture_data;

	init_texture_image(&texture_data, game);
	if (texture_data.img.ptr == NULL)
	{
		perror("Image load failed");
	}
	texture_data.img.pixels_addr = mlx_get_data_addr(
		texture_data.img.ptr,
		&texture_data.img.bytes_per_pixel,
		&texture_data.img.line_length,
		&texture_data.img.endian
	);

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		initialize_ray(x, &ray, game);
		initialize_wall(&wall);
		trace_ray_to_wall(&ray);
		draw_vertical_stripe(x, &ray, &wall, game, &texture_data);
		x++;
	}
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr, game->mlx.img.ptr, 0, 0);
}
