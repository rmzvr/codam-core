/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:58:39 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/16 17:59:00 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_draw_line(t_game *game)
{
	double	dx = 0;
	double	dy = 0;
	game->vector_x_start = game->player_position.cell_x + (PLAYER_SIZE / 2);
	game->vector_y_start = game->player_position.cell_y + (PLAYER_SIZE / 2);
	if (map[game->init_cell_pos_y][game->init_cell_pos_x] == 'N')
		dy = -1;
	else if (map[game->init_cell_pos_y][game->init_cell_pos_x] == 'S')
		dy = 1;
	else if (map[game->init_cell_pos_y][game->init_cell_pos_x] == 'W')
		dx = -1;
	else if (map[game->init_cell_pos_y][game->init_cell_pos_x] == 'E')
		dx = 1;

	double	tx1;
	if (dx != 0)
	{
		tx1 = (MIN_WINDOW_X - game->vector_x_start) / dx;
	}
	else
	{
		tx1 = -INFINITY;
	}

	double	tx2;
	if (dx != 0)
	{
		tx2 = (MAX_WINDOW_X - game->vector_x_start) / dx;
	}
	else
	{
		tx2 = INFINITY;
	}

	double	ty1;
	if (dy != 0)
	{
		ty1 = (MIN_WINDOW_Y - game->vector_y_start) / dy;
	}
	else
	{
		ty1 = -INFINITY;
	}

	double	ty2;
	if (dy != 0)
	{
		ty2 = (MAX_WINDOW_Y - game->vector_y_start) / dy;
	}
	else
	{
		ty2 = INFINITY;
	}

	if (tx1 > tx2)
	{
		double	temp = tx1;
		tx1 = tx2;
		tx2 = temp;
	}
	if (ty1 > ty2)
	{
		double	temp = ty1;
		ty1 = ty2;
		ty2 = temp;
	}

	double	tmax;
	if (tx2 < ty2)
	{
		tmax = tx2;
	}
	else
	{
		tmax = ty2;
	}

	if (tmax < 0)
	{
		printf("Ray points backwards or no exit ahead\n");
	}

	game->vector_x_end = game->vector_x_start + dx * tmax;
	game->vector_y_end = game->vector_y_start + dy * tmax;
	draw_line(game, game->vector_x_start, game->vector_y_start, game->vector_x_end, game->vector_y_end, 0x000000);
}