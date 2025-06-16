/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:58:49 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/16 17:52:56 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	init_player_position(t_game *game)
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
				game->pos_x = x + (double)PLAYER_SIZE / CELL_SIZE;
				game->pos_y = y + (double)PLAYER_SIZE / CELL_SIZE;
			}
			x++;
		}
		y++;
	}
}

void	init_player_direction(t_game *game)
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

void	draw_player(t_img *img, t_game *game)
{
	int	x;
	int	y;

	int	player_x_start;
	int	player_x_end;

	int	player_y_start;
	int	player_y_end;

	player_x_start = get_cell_x_head_addr(game->init_cell_pos_x) + PLAYER_SIZE + game->shiftX;
	player_x_end = player_x_start + PLAYER_SIZE;

	player_y_start = get_cell_y_head_addr(game->init_cell_pos_y) + PLAYER_SIZE + game->shiftY;
	player_y_end = player_y_start + PLAYER_SIZE;

	game->player_position.cell_x = player_x_start;
	game->player_position.cell_y = player_y_start;

	y = player_y_start;
	while (y < player_y_end)
	{
		x = player_x_start;
		while (x < player_x_end)
		{
			my_mlx_pixel_put(img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}