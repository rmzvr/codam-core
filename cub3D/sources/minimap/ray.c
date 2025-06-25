/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:58:39 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/25 15:29:00 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	swap_double(double *a, double *b)
{
	double	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	init_draw_line(t_game *game)
{
	double	tx1;
	double	tx2;
	double	ty1;
	double	ty2;
	double	tmax;

	tx1 = -INFINITY;
	tx2 = INFINITY;
	ty1 = -INFINITY;
	ty2 = INFINITY;
	game->vector_x_start = game->pos_x * (double)TILE_SIZE;
	game->vector_y_start = game->pos_y * (double)TILE_SIZE;
	if (game->dir_x != 0)
		tx1 = (MIN_WINDOW_X - game->vector_x_start) / game->dir_x;
	if (game->dir_x != 0)
		tx2 = (MAX_WINDOW_X - game->vector_x_start) / game->dir_x;
	if (game->dir_y != 0)
		ty1 = (MIN_WINDOW_Y - game->vector_y_start) / game->dir_y;
	if (game->dir_y != 0)
		ty2 = (MAX_WINDOW_Y - game->vector_y_start) / game->dir_y;
	if (tx1 > tx2)
		swap_double(&tx1, &tx2);
	if (ty1 > ty2)
		swap_double(&ty1, &ty2);
	if (tx2 < ty2)
		tmax = tx2;
	else
		tmax = ty2;
	if (tmax < 0)
		printf("Ray points backwards or no exit ahead\n");
	game->vector_x_end = game->vector_x_start + game->dir_x * tmax;
	game->vector_y_end = game->vector_y_start + game->dir_y * tmax;
	draw_line(game, game->vector_x_start, game->vector_y_start, game->vector_x_end, game->vector_y_end, 0x000000);
}
