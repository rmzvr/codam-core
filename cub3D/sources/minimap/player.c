/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:58:49 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/19 13:58:38 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_player(t_game *game)
{
	int	x;
	int	y;

	double	player_x_end;
	double	player_y_end;

	player_x_end = game->pos_x + ((double)PLAYER_SIZE / (double)TILE_SIZE);
	player_y_end = game->pos_y + ((double)PLAYER_SIZE / (double)TILE_SIZE);

	y = game->pos_y * TILE_SIZE;
	while (y < player_y_end  * TILE_SIZE)
	{
		x = game->pos_x  * TILE_SIZE;
		while (x < player_x_end  * TILE_SIZE)
		{
			my_mlx_pixel_put(&game->mlx.img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}