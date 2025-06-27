/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:55:10 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/27 15:15:32 by rzvir            ###   ########.fr       */
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
			img, window_x + MINIMAP_OFFSET, window_y + MINIMAP_OFFSET, 0x008000);
	}
	else
	{
		my_mlx_pixel_put(
			img, window_x + MINIMAP_OFFSET, window_y + MINIMAP_OFFSET, 0x00BFFF);
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
		my_mlx_pixel_put(img, window_x + MINIMAP_OFFSET, window_y + MINIMAP_OFFSET, 0xAAAAAA);
	}
}

void	draw_map(t_game *game)
{
	int	tile_x;
	int	tile_y;
	int	window_x;
	int	window_y;

	tile_y = 0;
	while (tile_y < MAP_HEIGHT)
	{
		tile_x = 0;
		while (tile_x < MAP_WIDTH)
		{
			window_y = get_tile_start_position(tile_y);
			while (window_y <= get_tile_end_position(tile_y))
			{
				window_x = get_tile_start_position(tile_x);
				while (window_x <= get_tile_end_position(tile_x))
				{
					draw_elements(window_x, window_y, tile_x, tile_y, &game->mlx.img);
					draw_borders(window_x, window_y, tile_x, tile_y, &game->mlx.img);
					window_x++;
				}
				window_y++;
			}
			tile_x++;
		}
		tile_y++;
	}
	mlx_put_image_to_window(
		game->mlx.ptr, game->mlx.win_ptr, game->mlx.img.ptr, 0, 0);
}
