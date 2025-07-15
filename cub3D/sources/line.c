/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:06:00 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/15 12:21:46 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	get_delta(int a, int b)
{
	return (b - a);
}

static void	draw_line_horizontal(
	int x_start,
	int y_start,
	int x_end,
	int y_end,
	t_game *game,
	int color
)
{
	int	x;
	int	y;
	int	delta_x;
	int	delta_y;
	int	direction;
	int	decision_parameter;

	if (x_start > x_end)
	{
		swap_int(&x_start, &x_end);
		swap_int(&y_start, &y_end);
	}
	x = x_start;
	y = y_start;
	delta_x = get_delta(x_start, x_end);
	delta_y = get_delta(y_start, y_end);
	direction = 1;
	decision_parameter = 0;
	if (delta_y < 0)
	{
		direction = -1;
		delta_y = delta_y * direction;
	}
	if (delta_x != 0)
	{
		decision_parameter = 2 * delta_y - delta_x;
		while (x < x_end)
		{
			my_mlx_pixel_put(&game->mlx.img, x, y, color);
			if (decision_parameter >= 0)
			{
				y = y + direction;
				decision_parameter = decision_parameter - 2 * delta_x;
			}
			decision_parameter = decision_parameter + 2 * delta_y;
			x++;
		}
	}
}

static void	draw_line_vertical(
	int x_start,
	int y_start,
	int x_end,
	int y_end,
	t_game *game,
	int color
)
{
	int	delta_x;
	int	delta_y;
	int	direction;
	int	x;
	int	y;
	int	decision_parameter;

	if (y_start > y_end)
	{
		swap_int(&x_start, &x_end);
		swap_int(&y_start, &y_end);
	}
	x = x_start;
	y = y_start;
	delta_x = get_delta(x_start, x_end);
	delta_y = get_delta(y_start, y_end);
	direction = 1;
	decision_parameter = 0;
	if (delta_x < 0)
	{
		direction = -1;
		delta_x = delta_x * direction;
	}
	if (delta_y != 0)
	{
		decision_parameter = 2 * delta_x - delta_y;
		while (y < y_end)
		{
			my_mlx_pixel_put(&game->mlx.img, x, y, color);
			if (decision_parameter >= 0)
			{
				x = x + direction;
				decision_parameter = decision_parameter - (2 * delta_y);
			}
			decision_parameter = decision_parameter + 2 * delta_x;
			y++;
		}
	}
}

void	draw_line(t_game *game, int x_start, int y_start, int x_end, int y_end, int color)
{
	if (abs(x_end - x_start) > abs(y_end - y_start))
	{
		draw_line_horizontal(x_start, y_start, x_end, y_end, game, color);
	}
	else
	{
		draw_line_vertical(x_start, y_start, x_end, y_end, game, color);
	}
}
