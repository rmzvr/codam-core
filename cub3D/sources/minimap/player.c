/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:58:49 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/25 15:58:40 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_player(t_game *game)
{
	double	player_x_start;
	double	player_y_start;
	double	player_x_end;
	double	player_y_end;

	player_x_start = (game->pos_x - PLAYER_SIZE) * TILE_SIZE;
	player_y_start = (game->pos_y - PLAYER_SIZE) * TILE_SIZE;
	player_x_end = (game->pos_x + PLAYER_SIZE) * TILE_SIZE;
	player_y_end = (game->pos_y + PLAYER_SIZE) * TILE_SIZE;
	while (player_y_start < player_y_end)
	{
		player_x_start = (game->pos_x - PLAYER_SIZE) * TILE_SIZE;
		while (player_x_start < player_x_end)
		{
			my_mlx_pixel_put(&game->mlx.img, player_x_start, player_y_start, 0x000000);
			player_x_start++;
		}
		player_y_start++;
	}
}
