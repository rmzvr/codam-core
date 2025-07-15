/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:04:18 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/15 17:05:16 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	get_player_start_position(
	double position
)
{
	double	position_fraction;
	double	player_start_position;

	position_fraction = position - floor(position);
	player_start_position = MINIMAP_RADIUS - PLAYER_SIZE + position_fraction;
	return (player_start_position * MINIMAP_TILE_SIZE + MINIMAP_OFFSET);
}

void	draw_player(
	t_game *game
)
{
	int	player_x_start;
	int	player_y_start;
	int	player_x_end;
	int	player_y_end;

	player_x_start = get_player_start_position(game->position_x);
	player_y_start = get_player_start_position(game->position_y);
	player_x_end = player_x_start + (PLAYER_SIZE * 2 * MINIMAP_TILE_SIZE);
	player_y_end = player_y_start + (PLAYER_SIZE * 2 * MINIMAP_TILE_SIZE);
	while (player_y_start < player_y_end)
	{
		player_x_start = get_player_start_position(game->position_x);
		while (player_x_start < player_x_end)
		{
			my_mlx_pixel_put(
				&game->mlx.img,
				player_x_start,
				player_y_start,
				0x000000);
			player_x_start++;
		}
		player_y_start++;
	}
}
