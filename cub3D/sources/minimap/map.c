/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:55:10 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/14 18:17:27 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// static int	get_tile_start_position(int tile_index)
// {
// 	return (tile_index * TILE_SIZE);
// }

// static int	get_tile_end_position(int tile_index)
// {
// 	return (tile_index * TILE_SIZE + TILE_SIZE - 1);
// }

void	draw_elements(int window_x, int window_y, int tile_x, int tile_y, t_img *img)
{
	if (tile_x < 0 || tile_y < 0 || tile_x >= MAP_WIDTH || tile_y >= MAP_HEIGHT)
	{
		my_mlx_pixel_put(
			img, window_x, window_y, 0x2C2D2D);
	}
	else if (map[tile_y][tile_x] == WALL)
	{
		my_mlx_pixel_put(
			img, window_x, window_y, 0x008000);
	}
	else
	{
		my_mlx_pixel_put(
			img, window_x, window_y, 0x00BFFF);
	}
}

void	draw_borders(int window_x, int window_y, int tile_x, int tile_y, t_img *img)
{
	(void) tile_x;
	(void) tile_y;
	if (
		window_x == 0
		|| window_y == 0
		|| window_x == tile_x * TILE_SIZE + TILE_SIZE - 1
		|| window_y == tile_y * TILE_SIZE + TILE_SIZE - 1
	)
	{
		my_mlx_pixel_put(img, window_x, window_y, 0x000000);
	}
}

// static void	draw_player(t_game *game)
// {
// 	int	player_x_start;
// 	int	player_y_start;
// 	int	player_x_end;
// 	int	player_y_end;

// 	player_x_start = (game->players_position_x - PLAYER_SIZE) * TILE_SIZE;
// 	player_y_start = (game->players_position_y - PLAYER_SIZE) * TILE_SIZE;
// 	player_x_end = (game->players_position_x + PLAYER_SIZE) * TILE_SIZE;
// 	player_y_end = (game->players_position_y + PLAYER_SIZE) * TILE_SIZE;
// 	while (player_y_start < player_y_end)
// 	{
// 		player_x_start = (game->players_position_x - PLAYER_SIZE) * TILE_SIZE;
// 		while (player_x_start < player_x_end)
// 		{
// 			my_mlx_pixel_put(
// 				&game->mlx.img, player_x_start, player_y_start, 0x000000);
// 			player_x_start++;
// 		}
// 		player_y_start++;
// 	}
// }

static void	draw_player(t_game *game)
{
	int	player_x_start;
	int	player_y_start;
	int	player_x_end;
	int	player_y_end;

	player_x_start = (5 - PLAYER_SIZE + (game->players_position_x - (int)game->players_position_x)) * TILE_SIZE;
	player_y_start = (5 - PLAYER_SIZE + (game->players_position_y - (int)game->players_position_y)) * TILE_SIZE;
	player_x_end = (5 + PLAYER_SIZE + (game->players_position_x - (int)game->players_position_x)) * TILE_SIZE;
	player_y_end = (5 + PLAYER_SIZE + (game->players_position_y - (int)game->players_position_y)) * TILE_SIZE;
	while (player_y_start < player_y_end)
	{
		player_x_start = (5 - PLAYER_SIZE + (game->players_position_x - (int)game->players_position_x)) * TILE_SIZE;
		while (player_x_start < player_x_end)
		{
			my_mlx_pixel_put(&game->mlx.img, player_x_start, player_y_start, 0x000000);
			player_x_start++;
		}
		player_y_start++;
	}
}

void	draw_map(t_game *game)
{
	int		tile_x;
	int		tile_y;
	int		start_x = 0;
	int		start_y = 0;
	int		window_x;
	int		window_y;

	tile_y = game->players_position_y - 5;
	if (game->players_position_y - 5 < 0.0)
	{
		tile_y -= 1;
	}
	while (tile_y < game->players_position_y + 5)
	{
		tile_x = game->players_position_x - 5;
		if (game->players_position_x - 5 < 0.0)
		{
			tile_x -= 1;
		}
		while (tile_x < game->players_position_x + 5)
		{
			window_y = start_y * TILE_SIZE;
			while (window_y <= start_y * TILE_SIZE + TILE_SIZE - 1)
			{
				window_x = start_x * TILE_SIZE;
				while (window_x <= start_x * TILE_SIZE + TILE_SIZE - 1)
				{
					draw_elements(window_x, window_y, tile_x, tile_y, &game->mlx.img);
					draw_borders(window_x, window_y, start_x, start_y, &game->mlx.img);
					window_x++;
				}
				window_y++;
			}
			start_x += 1;
			tile_x += 1;
		}
		start_x = 0;
		start_y += 1;
		tile_y += 1;
	}
	draw_player(game);
	mlx_put_image_to_window(
		game->mlx.ptr, game->mlx.win_ptr, game->mlx.img.ptr, 0, 0);
}
