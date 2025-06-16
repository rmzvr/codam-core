/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:10:07 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/16 17:10:31 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	initialize_dda_data(
	int x,
	t_dda_data *dda_data,
	t_game *game
)
{
	dda_data->hit_side = VERTICAL;
	dda_data->ray_direction_x = calc_ray_direction(game->dir_x, game->camera_plane_x, x);
	dda_data->ray_direction_y = calc_ray_direction(game->dir_y, game->camera_plane_y, x);
	dda_data->step_direction_x = calc_step_direction(dda_data->ray_direction_x);
	dda_data->step_direction_y = calc_step_direction(dda_data->ray_direction_y);
	dda_data->distance_to_wall = 0.0;
	dda_data->wall_color = 0;
	dda_data->wall_start = 0;
	dda_data->wall_end = 0;
}

void	initialize_ray_trace_data(
	t_ray_trace_data *ray_trace_data,
	t_dda_data *dda_data,
	t_game *game
)
{
	ray_trace_data->hit = FALSE;
	ray_trace_data->current_tail_x = game->pos_x;
	ray_trace_data->current_tail_y = game->pos_y;
	ray_trace_data->ray_distance_x = calc_ray_distance(dda_data->ray_direction_x);
	ray_trace_data->ray_distance_y = calc_ray_distance(dda_data->ray_direction_y);
	ray_trace_data->total_ray_distance_x = calc_total_ray_distance(dda_data->ray_direction_x, ray_trace_data->ray_distance_x, game->pos_x, ray_trace_data->current_tail_x);
	ray_trace_data->total_ray_distance_y = calc_total_ray_distance(dda_data->ray_direction_y, ray_trace_data->ray_distance_y, game->pos_y, ray_trace_data->current_tail_y);
}
