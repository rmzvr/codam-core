/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:58:39 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/16 12:59:24 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_draw_line(t_game *game)
{
	double	dx = 0;
	double	dy = 0;
	game->vector_x_start = game->player_position.cell_x + (playerSize / 2);
	game->vector_y_start = game->player_position.cell_y + (playerSize / 2);
	if (map[game->init_cell_pos_y][game->init_cell_pos_x] == 'N')
		dy = -1;
	else if (map[game->init_cell_pos_y][game->init_cell_pos_x] == 'S')
		dy = 1;
	else if (map[game->init_cell_pos_y][game->init_cell_pos_x] == 'W')
		dx = -1;
	else if (map[game->init_cell_pos_y][game->init_cell_pos_x] == 'E')
		dx = 1;

	double	xmin = 0;
	double	xmax = mapWidth * cellSize - 1;

	double	ymin = 0;
	double	ymax = mapHeight * cellSize - 1;

	double	tx1;
	if (dx != 0)
	{
		tx1 = (xmin - game->vector_x_start) / dx;
	}
	else
	{
		tx1 = -INFINITY;
	}

	double	tx2;
	if (dx != 0)
	{
		tx2 = (xmax - game->vector_x_start) / dx;
	}
	else
	{
		tx2 = INFINITY;
	}

	double	ty1;
	if (dy != 0)
	{
		ty1 = (ymin - game->vector_y_start) / dy;
	}
	else
	{
		ty1 = -INFINITY;
	}

	double	ty2;
	if (dy != 0)
	{
		ty2 = (ymax - game->vector_y_start) / dy;
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