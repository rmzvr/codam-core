/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:58:39 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/27 15:24:59 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_draw_line(t_game *game)
{
	double	tx1;
	double	tx2;
	double	ty1;
	double	ty2;
	double	tmax;
	double	vector_x_start;
	double	vector_y_start;
	int		vector_x_end;
	int		vector_y_end;

	tx1 = -INFINITY;
	tx2 = INFINITY;
	ty1 = -INFINITY;
	ty2 = INFINITY;
	vector_x_start = game->players_position_x * (double)MINIMAP_TILE_SIZE + MINIMAP_OFFSET;
	vector_y_start = game->players_position_y * (double)MINIMAP_TILE_SIZE + MINIMAP_OFFSET;
	if (game->player_direction_x != 0)
		tx1 = (MIN_WINDOW_X + MINIMAP_OFFSET + MINIMAP_TILE_SIZE - vector_x_start) / game->player_direction_x;
	if (game->player_direction_x != 0)
		tx2 = ((MAX_WINDOW_X / 3) - vector_x_start) / game->player_direction_x;
	if (game->player_direction_y != 0)
		ty1 = (MIN_WINDOW_Y + MINIMAP_OFFSET + MINIMAP_TILE_SIZE - vector_y_start) / game->player_direction_y;
	if (game->player_direction_y != 0)
		ty2 = ((MAX_WINDOW_Y / 3) - vector_y_start) / game->player_direction_y;
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
	vector_x_end = vector_x_start + game->player_direction_x * tmax;
	vector_y_end = vector_y_start + game->player_direction_y * tmax;
	draw_line(game, vector_x_start, vector_y_start, vector_x_end, vector_y_end, 0x000000);
}
