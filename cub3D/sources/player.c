/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:19:37 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/26 15:37:43 by rzvir            ###   ########.fr       */
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
				game->pos_x = x + (TILE_SIZE / TILE_SIZE / 2.0);
				game->pos_y = y + (TILE_SIZE / TILE_SIZE / 2.0);
			}
			x++;
		}
		y++;
	}
}

static void	init_player_direction(t_game *game)
{
	if (map[(int)game->pos_y][(int)game->pos_x] == 'N')
	{
		game->dir_x = 0.0;
		game->dir_y = -1.0;
		game->plane_x = 0.66;
		game->plane_y = 0;
	}
	else if (map[(int)game->pos_y][(int)game->pos_x] == 'S')
	{
		game->dir_x = 0.0;
		game->dir_y = 1.0;
		game->plane_x = -0.66;
		game->plane_y = 0;
	}
	else if (map[(int)game->pos_y][(int)game->pos_x] == 'W')
	{
		game->dir_x = -1.0;
		game->dir_y = 0.0;
		game->plane_x = 0;
		game->plane_y = -0.66;
	}
	else if (map[(int)game->pos_y][(int)game->pos_x] == 'E')
	{
		game->dir_x = 1.0;
		game->dir_y = 0.0;
		game->plane_x = 0;
		game->plane_y = 0.66;
	}
}

void	init_player(t_game *game)
{
	init_player_position(game);
	init_player_direction(game);
}
