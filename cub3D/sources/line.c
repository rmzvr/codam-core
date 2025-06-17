/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:06:00 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/17 14:12:09 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_line_horizontal(int x0, int y0, int x1, int y1, t_game *game, int color)
{
	int	temp;

	if (x0 > x1)
	{
		temp = x0;
		x0 = x1;
		x1 = temp;

		temp = y0;
		y0 = y1;
		y1 = temp;
	}

	int	dx = x1 - x0;
	int	dy = y1 - y0;
	int	dir = 1;
	if (dy < 0)
	{
		dir = -1;
		dy = dy * dir;
	}
	
	if (dx != 0)
	{
		int	x = x0;
		int	y = y0;
		int	D = (2 * dy) - dx;

		while (x < x1)
		{
			my_mlx_pixel_put(&game->mlx.img, x, y, color);
			if (D >= 0)
			{
				y = y + dir;
				D = D - (2 * dx);
			}
			D = D + 2 * dy;
			x++;
		}
	}
}

void	draw_line_vertical(int x0, int y0, int x1, int y1, t_game *game, int color)
{
	int	temp;

	if (y0 > y1)
	{
		temp = x0;
		x0 = x1;
		x1 = temp;

		temp = y0;
		y0 = y1;
		y1 = temp;
	}

	int	dx = x1 - x0;
	int	dy = y1 - y0;
	int	dir = 1;
	if (dx < 0)
	{
		dir = -1;
		dx = dx * dir;
	}
	if (dy != 0)
	{
		int	x = x0;
		int	y = y0;
		int	D = (2 * dx) - dy;

		while (y < y1)
		{
			my_mlx_pixel_put(&game->mlx.img, x, y, color);
			if (D >= 0)
			{
				x = x + dir;
				D = D - (2 * dy);
			}
			D = D + 2 * dx;
			y++;
		}
	}
}

void	draw_line(t_game *game, int x0, int y0, int x1, int y1, int color)
{
	if (abs(x1 - x0) > abs(y1 - y0))
	{
		draw_line_horizontal(x0, y0, x1, y1, game, color);
	}
	else
	{
		draw_line_vertical(x0, y0, x1, y1, game, color);
	}
}
