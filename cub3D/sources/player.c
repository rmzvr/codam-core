/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:19:37 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/18 15:40:26 by rzvir            ###   ########.fr       */
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
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E')
			{
				game->pos_x = x + (double)PLAYER_SIZE / (double)CELL_SIZE;
				game->pos_y = y + (double)PLAYER_SIZE / (double)CELL_SIZE;
			}
			x++;
		}
		y++;
	}
}

static void	init_player_direction(t_game *game)
{
	game->dir_x = 0;
	game->dir_y = 0;
	if (map[(int)game->pos_y][(int)game->pos_x] == 'N')
		game->dir_y = -1;
	else if (map[(int)game->pos_y][(int)game->pos_x] == 'S')
		game->dir_y = 1;
	else if (map[(int)game->pos_y][(int)game->pos_x] == 'W')
		game->dir_x = -1;
	else if (map[(int)game->pos_y][(int)game->pos_x] == 'E')
		game->dir_x = 1;
}

void	init_player(t_game *game)
{
	init_player_position(game);
	init_player_direction(game);
}