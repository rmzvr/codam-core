/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:55:10 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/27 17:54:29 by rzvir            ###   ########.fr       */
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

void	draw_map(t_game *game)
{
	double	tile_x;
	double	tile_y;
	int		window_x;
	int		window_y;
	// double	delta_x = (game->players_position_x + 5.0) - (game->players_position_x - 4.0);
	// double	delta_y = (game->players_position_y + 5.0) - (game->players_position_y - 4.0);

	double	start_x = 0.0;
	double	start_y = 0.0;

	tile_y = game->players_position_y - 4.0;
	// printf("players_position_x: %f, players_position_y: %f\n", game->players_position_x, game->players_position_y);
	// printf("delta_x: %f, delta_y: %f\n", delta_x, delta_y);
	while (tile_y < game->players_position_y + 5.0)
	{
		tile_x = game->players_position_x - 4.0;
		while (tile_x < game->players_position_x + 5.0)
		{
			// printf("tile_x: %f, tile_y: %f\n", tile_x, tile_y);
			window_y = start_y * MINIMAP_TILE_SIZE;
			while (window_y <= start_y * MINIMAP_TILE_SIZE + MINIMAP_TILE_SIZE - 1)
			{
				window_x = start_x * MINIMAP_TILE_SIZE;
				while (window_x <= start_x * MINIMAP_TILE_SIZE + MINIMAP_TILE_SIZE - 1)
				{
					printf("window_x: %d, window_y: %d\n", window_x, window_y);
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
			// start_x += 1.0;
			tile_x += 1.0;
		}
		start_y += 1.0;
		tile_y += 1.0;
	}
	mlx_put_image_to_window(
		game->mlx.ptr, game->mlx.win_ptr, game->mlx.img.ptr, 0, 0);
}
