/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:55:10 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/28 21:09:52 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	get_tile_start_position(int tile_index)
{
	return (tile_index * MINIMAP_TILE_SIZE);
}

static int	get_tile_end_position(int tile_index)
{
	return (tile_index * MINIMAP_TILE_SIZE + MINIMAP_TILE_SIZE - 1);
}

void	draw_elements(int window_x, int window_y, int tile_x, int tile_y, t_img *img)
{
	if (map[tile_y][tile_x] == WALL)
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
	if (
		window_x == tile_x
		|| window_y == tile_y
		|| window_x == (MAX_WINDOW_X / 3)
		|| window_y == (MAX_WINDOW_Y / 3)
		|| window_x == get_tile_start_position(tile_x)
		|| window_x == get_tile_end_position(tile_x)
		|| window_y == get_tile_start_position(tile_y)
		|| window_y == get_tile_end_position(tile_y)
	)
	{
		my_mlx_pixel_put(img, window_x, window_y, 0xAAAAAA);
	}
}

static void	draw_player(t_game *game)
{
	int	player_x_start;
	int	player_y_start;
	int	player_x_end;
	int	player_y_end;

	player_x_start = (6.0 - PLAYER_SIZE) * MINIMAP_TILE_SIZE;
	player_y_start = (5.5 - PLAYER_SIZE) * MINIMAP_TILE_SIZE;
	player_x_end = (6.0 + PLAYER_SIZE) * MINIMAP_TILE_SIZE;
	player_y_end = (5.5 + PLAYER_SIZE) * MINIMAP_TILE_SIZE;
	while (player_y_start < player_y_end)
	{
		player_x_start = (6.0 - PLAYER_SIZE) * MINIMAP_TILE_SIZE;
		while (player_x_start < player_x_end)
		{
			my_mlx_pixel_put(
				&game->mlx.img, player_x_start, player_y_start, 0x000000);
			player_x_start++;
		}
		player_y_start++;
	}
}

void	draw_map(t_game *game)
{
	double	tile_x;
	double	tile_y;
	int		window_x;
	int		window_y;

	double	start_x = 0.0;
	double	start_y = 0.0;

	tile_y = game->players_position_y - 5.5;
	while (tile_y < game->players_position_y + 5.5)
	{
		tile_x = game->players_position_x - 5.5;
		while (tile_x < game->players_position_x + 5.5)
		{
			window_y = start_y * MINIMAP_TILE_SIZE;
			while (window_y <= start_y * MINIMAP_TILE_SIZE + MINIMAP_TILE_SIZE - 1)
			{
				window_x = start_x * MINIMAP_TILE_SIZE;
				while (window_x <= start_x * MINIMAP_TILE_SIZE + MINIMAP_TILE_SIZE - 1)
				{
					// printf("tile: %d\n", map[(int)tile_y][(int)tile_x]);
					if (map[(int)tile_y][(int)tile_x] == WALL)
						my_mlx_pixel_put(&game->mlx.img, window_x, window_y, 0x008000);
					else
						my_mlx_pixel_put(&game->mlx.img, window_x, window_y, 0x00BFFF);
					// draw_elements(window_x, window_y, tile_x, tile_y, &game->mlx.img);
					// draw_borders(window_x, window_y, tile_x, tile_y, &game->mlx.img);
					window_x++;
				}
				window_y++;
			}
			start_x += PLAYER_SIZE;
			tile_x += PLAYER_SIZE;
		}
		start_x = 0.0;
		start_y += PLAYER_SIZE;
		tile_y += PLAYER_SIZE;
	}
	draw_player(game);
	mlx_put_image_to_window(
		game->mlx.ptr, game->mlx.win_ptr, game->mlx.img.ptr, 0, 0);
}
