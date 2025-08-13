/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:01:53 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/24 13:47:41 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state_bonus.h"
#include "minimap_bonus.h"

static void	fill_tile(
	t_vec2	window,
	t_minimap *minimap,
	t_image *img,
	t_player *player
)
{
	char	**map;

	map = player->map->raw;
	if (minimap->map_tile_x < 0
		|| minimap->map_tile_y < 0
		|| minimap->map_tile_x >= (int)player->map->width
		|| minimap->map_tile_y >= (int)player->map->height)
	{
		put_pixel(img, window.x, window.y, 0x2C2D2D);
	}
	else if (map[minimap->map_tile_y][minimap->map_tile_x] == WALL)
	{
		put_pixel(img, window.x, window.y, 0x008000);
	}
	else if (map[minimap->map_tile_y][minimap->map_tile_x] == SPACE)
	{
		put_pixel(img, window.x, window.y, 0x2C2D2D);
	}
	else
	{
		put_pixel(img, window.x, window.y, 0x00BFFF);
	}
}

static void	draw_border(
	t_vec2	window,
	t_minimap *minimap,
	t_image *img
)
{
	int	minimap_offset;
	int	minimap_tile_size;
	int	tile_x_position;
	int	tile_y_position;

	minimap_offset = TILE_SIZE / 2;
	minimap_tile_size = TILE_SIZE / 2;
	tile_x_position = minimap->window_tile_x * minimap_tile_size;
	tile_y_position = minimap->window_tile_y * minimap_tile_size;
	if (
		window.x == minimap_offset
		|| window.y == minimap_offset
		|| window.x == tile_x_position + minimap_offset + minimap_tile_size - 1
		|| window.y == tile_y_position + minimap_offset + minimap_tile_size - 1
	)
	{
		put_pixel(img, window.x, window.y, 0x000000);
	}
}

void	draw_tile(
	t_minimap *minimap,
	t_image *img,
	t_player *player
)
{
	int		minimap_offset;
	int		minimap_tile_size;
	t_vec2	window_start;
	t_vec2	window_end;

	minimap_offset = TILE_SIZE / 2;
	minimap_tile_size = TILE_SIZE / 2;
	window_start.y = (
			minimap->window_tile_y * minimap_tile_size + minimap_offset);
	window_end.y = window_start.y + minimap_tile_size;
	while (window_start.y < window_end.y)
	{
		window_start.x = (
				minimap->window_tile_x * minimap_tile_size + minimap_offset);
		window_end.x = window_start.x + minimap_tile_size;
		while (window_start.x < window_end.x)
		{
			fill_tile(window_start, minimap, img, player);
			draw_border(window_start, minimap, img);
			window_start.x++;
		}
		window_start.y++;
	}
}
