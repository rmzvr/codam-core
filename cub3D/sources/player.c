/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:19:37 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/27 15:24:59 by rzvir            ###   ########.fr       */
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
				game->players_position_x = x + (TILE_SIZE / TILE_SIZE / 2.0);
				game->players_position_y = y + (TILE_SIZE / TILE_SIZE / 2.0);
			}
			x++;
		}
		y++;
	}
}

static void	init_player_direction(t_game *game)
{
	if (map[(int)game->players_position_y][(int)game->players_position_x] == 'N')
	{
		game->player_direction_x = 0.0;
		game->player_direction_y = -1.0;
		game->plane_x = 0.66;
		game->plane_y = 0;
	}
	else if (map[(int)game->players_position_y][(int)game->players_position_x] == 'S')
	{
		game->player_direction_x = 0.0;
		game->player_direction_y = 1.0;
		game->plane_x = -0.66;
		game->plane_y = 0;
	}
	else if (map[(int)game->players_position_y][(int)game->players_position_x] == 'W')
	{
		game->player_direction_x = -1.0;
		game->player_direction_y = 0.0;
		game->plane_x = 0;
		game->plane_y = -0.66;
	}
	else if (map[(int)game->players_position_y][(int)game->players_position_x] == 'E')
	{
		game->player_direction_x = 1.0;
		game->player_direction_y = 0.0;
		game->plane_x = 0;
		game->plane_y = 0.66;
	}
}

void	init_player(t_game *game)
{
	init_player_position(game);
	init_player_direction(game);
}
