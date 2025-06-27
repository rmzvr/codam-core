/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:58:49 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/27 17:08:25 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_player(t_game *game)
{
	int	player_x_start;
	int	player_y_start;
	int	player_x_end;
	int	player_y_end;

	player_x_start = (game->players_position_x - PLAYER_SIZE) * MINIMAP_TILE_SIZE;
	player_y_start = (game->players_position_y - PLAYER_SIZE) * MINIMAP_TILE_SIZE;
	player_x_end = (game->players_position_x + PLAYER_SIZE) * MINIMAP_TILE_SIZE;
	player_y_end = (game->players_position_y + PLAYER_SIZE) * MINIMAP_TILE_SIZE;
	while (player_y_start < player_y_end)
	{
		player_x_start = (game->players_position_x - PLAYER_SIZE) * MINIMAP_TILE_SIZE;
		while (player_x_start < player_x_end)
		{
			my_mlx_pixel_put(
				&game->mlx.img, player_x_start, player_y_start, 0x000000);
			player_x_start++;
		}
		player_y_start++;
	}
}
