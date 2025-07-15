/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:01:53 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/15 17:02:31 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	fill_tile(
	int window_x,
	int window_y,
	t_minimap *minimap,
	t_img *img
)
{
	if (minimap->map_tile_x < 0
		|| minimap->map_tile_y < 0
		|| minimap->map_tile_x >= MAP_WIDTH
		|| minimap->map_tile_y >= MAP_HEIGHT)
	{
		my_mlx_pixel_put(
			img, window_x, window_y, 0x2C2D2D);
	}
	else if (map[minimap->map_tile_y][minimap->map_tile_x] == WALL)
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

static void	draw_border(
	int window_x,
	int window_y,
	t_minimap *minimap,
	t_img *img
)
{
	int	tile_x_position;
	int	tile_y_position;

	tile_x_position = minimap->window_tile_x * MINIMAP_TILE_SIZE;
	tile_y_position = minimap->window_tile_y * MINIMAP_TILE_SIZE;
	if (
		window_x == MINIMAP_OFFSET
		|| window_y == MINIMAP_OFFSET
		|| window_x == tile_x_position + MINIMAP_OFFSET + MINIMAP_TILE_SIZE - 1
		|| window_y == tile_y_position + MINIMAP_OFFSET + MINIMAP_TILE_SIZE - 1
	)
	{
		my_mlx_pixel_put(img, window_x, window_y, 0x000000);
	}
}

void	draw_tile(
	t_minimap *minimap,
	t_game *game
)
{
	int	window_x_start;
	int	window_x_end;
	int	window_y_start;
	int	window_y_end;

	window_y_start = (
			minimap->window_tile_y * MINIMAP_TILE_SIZE + MINIMAP_OFFSET);
	window_y_end = window_y_start + MINIMAP_TILE_SIZE;
	while (window_y_start < window_y_end)
	{
		window_x_start = (
				minimap->window_tile_x * MINIMAP_TILE_SIZE + MINIMAP_OFFSET);
		window_x_end = window_x_start + MINIMAP_TILE_SIZE;
		while (window_x_start < window_x_end)
		{
			fill_tile(
				window_x_start, window_y_start, minimap, &game->mlx.img);
			draw_border(
				window_x_start, window_y_start, minimap, &game->mlx.img);
			window_x_start++;
		}
		window_y_start++;
	}
}
