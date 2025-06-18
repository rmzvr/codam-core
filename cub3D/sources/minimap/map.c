/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:55:10 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/18 16:31:00 by rzvir            ###   ########.fr       */
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

// int	check_wall(t_direction direction, t_game *game)
// {
// 	int		curr_cell_y_index = get_cell_index(game->player_position.cell_y);
// 	int		sibling_cell_y_index = get_cell_index(game->player_position.cell_y + STEP_SIZE);

// 	int		curr_cell_x_index = get_cell_index(game->player_position.cell_x);
// 	int		sibling_cell_x_index = get_cell_index(game->player_position.cell_x + STEP_SIZE);

// 	if (direction == TOP)
// 	{
// 		int	prev_cell_y_index = get_cell_index(game->player_position.cell_y - STEP_SIZE);
// 		if (map[prev_cell_y_index][curr_cell_x_index] == WALL
// 			|| map[prev_cell_y_index][sibling_cell_x_index] == WALL)
// 		{
// 			return (1);
// 		}
// 	}
// 	else if (direction == RIGHT)
// 	{
// 		int	next_cell_x_index = get_cell_index(game->player_position.cell_x + STEP_SIZE - 1 + PLAYER_SIZE);
// 		if (map[curr_cell_y_index][next_cell_x_index] == WALL
// 			|| map[sibling_cell_y_index][next_cell_x_index] == WALL)
// 		{
// 			return (1);
// 		}
// 	}
// 	else if (direction == BOTTOM)
// 	{
// 		int	next_cell_y_index = get_cell_index(game->player_position.cell_y + STEP_SIZE - 1 + PLAYER_SIZE);
// 		if (map[next_cell_y_index][curr_cell_x_index] == WALL
// 			|| map[next_cell_y_index][sibling_cell_x_index] == WALL)
// 		{
// 			return (1);
// 		}
// 	}
// 	else if (direction == LEFT)
// 	{
// 		int	prev_cell_x_index = get_cell_index(game->player_position.cell_x - STEP_SIZE);
// 		if (map[curr_cell_y_index][prev_cell_x_index] == WALL
// 			|| map[sibling_cell_y_index][prev_cell_x_index] == WALL)
// 		{
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

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
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr, game->mlx.img.ptr, 0, 0);
}
