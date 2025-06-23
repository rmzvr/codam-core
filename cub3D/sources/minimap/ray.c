/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:58:39 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/23 14:57:29 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	swap_double(double *a, double *b)
{
	double	temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

void	init_draw_line(t_game *game)
{
	double	tx1;
	double	tx2;
	double	ty1;
	double	ty2;

	tx1 = -INFINITY;
	tx2 = INFINITY;
	ty1 = -INFINITY;
	ty2 = INFINITY;
	game->vector_x_start = game->pos_x * (double)TILE_SIZE + (PLAYER_SIZE / 2);
	game->vector_y_start = game->pos_y * (double)TILE_SIZE + (PLAYER_SIZE / 2);
	if (game->dir_x != 0)
		tx1 = (MIN_WINDOW_X - game->vector_x_start) / game->dir_x;

	if (game->dir_x != 0)
		tx2 = (MAX_WINDOW_X - game->vector_x_start) / game->dir_x;

	if (game->dir_y != 0)
		ty1 = (MIN_WINDOW_Y - game->vector_y_start) / game->dir_y;

	if (game->dir_y != 0)
		ty2 = (MAX_WINDOW_Y - game->vector_y_start) / game->dir_y;

	if (tx1 > tx2)
	{
		swap_double(&tx1, &tx2);
		// double	temp = tx1;
		// tx1 = tx2;
		// tx2 = temp;
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

	game->vector_x_end = game->vector_x_start + game->dir_x * tmax;
	game->vector_y_end = game->vector_y_start + game->dir_y * tmax;
	draw_line(game, game->vector_x_start, game->vector_y_start, game->vector_x_end, game->vector_y_end, 0x000000);
}