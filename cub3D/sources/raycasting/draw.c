/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:08:24 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/16 17:54:21 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void	draw_ceiling(
	int x,
	double wall_start,
	t_game *game
)
{
	if (wall_start > 0)
	{
		draw_line(game, x, 0, x, wall_start, 0x87CEEB);
	}
}

static void	draw_floor(
	int x,
	double wall_end,
	t_game *game
)
{
	if (wall_end < WINDOW_WIDTH)
	{
		draw_line(game, x, wall_end, x, WINDOW_WIDTH, 0x4B3621);
	}
}

static void	draw_wall(
	int x,
	t_dda_data *dda_data,
	t_game *game
)
{
	draw_line(game, x, dda_data->wall_start, x, dda_data->wall_end, dda_data->wall_color);
}

void	draw_vertical_stripe(
	int x,
	t_ray_trace_data *ray_trace_data,
	t_dda_data *dda_data,
	t_game *game
)
{
	calc_distance_to_wall(dda_data, ray_trace_data);
	calc_wall_height(dda_data);
	calc_wall_color(dda_data);
	draw_ceiling(x, dda_data->wall_start, game);
	draw_wall(x, dda_data, game);
	draw_floor(x, dda_data->wall_end, game);
}
