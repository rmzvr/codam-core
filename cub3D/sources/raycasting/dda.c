/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:01:46 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/17 16:58:42 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	move_to_next_tile_side(
	t_ray_trace_data *ray_trace_data,
	t_dda_data *dda_data
)
{
	if (ray_trace_data->total_ray_distance_x < ray_trace_data->total_ray_distance_y)
	{
		ray_trace_data->total_ray_distance_x += ray_trace_data->ray_distance_x;
		ray_trace_data->current_tile_x += dda_data->step_direction_x;
		dda_data->hit_side = VERTICAL;
	}
	else if (ray_trace_data->total_ray_distance_x > ray_trace_data->total_ray_distance_y)
	{
		ray_trace_data->total_ray_distance_y += ray_trace_data->ray_distance_y;
		ray_trace_data->current_tile_y += dda_data->step_direction_y;
		dda_data->hit_side = HORIZONTAL;
	}
}

void	check_wall_hit(
	t_ray_trace_data *ray_trace_data
)
{
	if (map[ray_trace_data->current_tile_y][ray_trace_data->current_tile_x] == 1)
	{
		ray_trace_data->hit = TRUE;
	}
}

void	trace_ray_to_wall(
	t_ray_trace_data *ray_trace_data,
	t_dda_data *dda_data,
	t_game *game
)
{
	initialize_ray_trace_data(ray_trace_data, dda_data, game);
	while (ray_trace_data->hit == FALSE)
	{
		move_to_next_tile_side(ray_trace_data, dda_data);
		check_wall_hit(ray_trace_data);
	}
}

void	render_frame_with_ray_casting(
	t_game *game
)
{
	int					x;
	t_dda_data			dda_data;
	t_ray_trace_data	ray_trace_data;
	t_texture			texture_data;

	texture_data.relative_path = "textures/wall.xpm";

	texture_data.wall_img = mlx_xpm_file_to_image(game->mlx.ptr, texture_data.relative_path, &texture_data.wall_img_width, &texture_data.wall_img_height);
	if (!texture_data.wall_img)
	{
		perror("Image load failed");
	}
	texture_data.wall_pixels_addr = mlx_get_data_addr(texture_data.wall_img, &texture_data.bpp, &texture_data.line_len, &texture_data.endian);
	printf("bpp: %d, line_len: %d, endian: %d\n", texture_data.bpp, texture_data.line_len, texture_data.endian);
	texture_data.screen_img = mlx_new_image(game->mlx.ptr, 750, 750);
	// char *screen_data = mlx_get_data_addr(game->mlx.img.ptr, &game->mlx.img.bpp, &game->mlx.img.ll, &game->mlx.img.endian);

	// mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr, screen_img, 0, 0);

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		initialize_dda_data(x, &dda_data, game);
		trace_ray_to_wall(&ray_trace_data, &dda_data, game);
		draw_vertical_stripe(x, &ray_trace_data, &dda_data, game, &texture_data);
		x++;
	}
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr, game->mlx.img.ptr, 0, 0);
}
