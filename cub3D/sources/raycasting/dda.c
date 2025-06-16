/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:01:46 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/16 18:03:02 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

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

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		initialize_dda_data(x, &dda_data, game);
		trace_ray_to_wall(&ray_trace_data, &dda_data, game);
		draw_vertical_stripe(x, &ray_trace_data, &dda_data, game);
		x++;
	}
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr, game->mlx.img.ptr, 0, 0);
}
