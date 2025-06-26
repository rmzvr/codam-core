/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:06:00 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/26 15:39:41 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_line_horizontal(
	int x0,
	int y0,
	int x1,
	int y1,
	t_game *game,
	int color
)
{
	int	dx;
	int	dy;
	int	dir;
	int	x;
	int	y;
	int	d;

	if (x0 > x1)
	{
		swap_int(&x0, &x1);
		swap_int(&y0, &y1);
	}
	dx = x1 - x0;
	dy = y1 - y0;
	dir = 1;
	if (dy < 0)
	{
		dir = -1;
		dy = dy * dir;
	}
	if (dx != 0)
	{
		x = x0;
		y = y0;
		d = (2 * dy) - dx;
		while (x < x1)
		{
			my_mlx_pixel_put(&game->mlx.img, x, y, color);
			if (d >= 0)
			{
				y = y + dir;
				d = d - (2 * dx);
			}
			d = d + 2 * dy;
			x++;
		}
	}
}

void	draw_line_vertical(int x0, int y0, int x1, int y1, t_game *game, int color)
{
	int	dx;
	int	dy;
	int	dir;
	int	x;
	int	y;
	int	d;

	if (y0 > y1)
	{
		swap_int(&x0, &x1);
		swap_int(&y0, &y1);
	}
	dx = x1 - x0;
	dy = y1 - y0;
	dir = 1;
	if (dx < 0)
	{
		dir = -1;
		dx = dx * dir;
	}
	if (dy != 0)
	{
		x = x0;
		y = y0;
		d = (2 * dx) - dy;
		while (y < y1)
		{
			my_mlx_pixel_put(&game->mlx.img, x, y, color);
			if (d >= 0)
			{
				x = x + dir;
				d = d - (2 * dy);
			}
			d = d + 2 * dx;
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
