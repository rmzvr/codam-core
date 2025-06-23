/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:55:10 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/23 14:53:25 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_elements(t_img *img, int cell_x, int cell_y, int x, int y)
{
	if (map[y][x] == WALL)
	{
		my_mlx_pixel_put(img, cell_x, cell_y, 0x008000);
	}
	else
	{
		my_mlx_pixel_put(img, cell_x, cell_y, 0x00BFFF);
	}
}

void	draw_borders(t_img *img, int cell_x, int cell_y, int x, int y)
{
	if (
		cell_x == x
		|| cell_y == y
		|| cell_x == MAX_WINDOW_X
		|| cell_y == MAX_WINDOW_Y
		|| cell_x == get_cell_x_head_addr(x)
		|| cell_x == get_cell_x_tile_addr(x)
		|| cell_y == get_cell_y_head_addr(y)
		|| cell_y == get_cell_y_tile_addr(y)
	)
	{
		my_mlx_pixel_put(img, cell_x, cell_y, 0xAAAAAA);
	}
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;
	int	cell_x;
	int	cell_y;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			cell_y = get_cell_y_head_addr(y);
			while (cell_y <= get_cell_y_tile_addr(y))
			{
				cell_x = get_cell_x_head_addr(x);
				while (cell_x <= get_cell_x_tile_addr(x))
				{
					draw_elements(&game->mlx.img, cell_x, cell_y, x, y);
					draw_borders(&game->mlx.img, cell_x, cell_y, x, y);
					cell_x++;
				}
				cell_y++;
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(
		game->mlx.ptr, game->mlx.win_ptr, game->mlx.img.ptr, 0, 0);
}
