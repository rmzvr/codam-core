/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:19:37 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/15 14:46:05 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	init_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			if (map[y][x] == 'N'
				|| map[y][x] == 'S'
				|| map[y][x] == 'W'
				|| map[y][x] == 'E'
			)
			{
				game->position_x = x + (TILE_SIZE / TILE_SIZE / 2.0);
				game->position_y = y + (TILE_SIZE / TILE_SIZE / 2.0);
			}
			x++;
		}
		y++;
	}
}

static void	init_player_direction(t_game *game)
{
	char	tile;

	tile = map[(int)game->position_y][(int)game->position_x];
	if (tile == 'N')
	{
		game->direction_x = 0.0;
		game->direction_y = -1.0;
	}
	else if (tile == 'S')
	{
		game->direction_x = 0.0;
		game->direction_y = 1.0;
	}
	else if (tile == 'W')
	{
		game->direction_x = -1.0;
		game->direction_y = 0.0;
	}
	else if (tile == 'E')
	{
		game->direction_x = 1.0;
		game->direction_y = 0.0;
	}
	game->plane_x = -game->direction_y * FOV;
	game->plane_y = game->direction_x * FOV;
}

void	init_player(t_game *game)
{
	init_player_position(game);
	init_player_direction(game);
}
