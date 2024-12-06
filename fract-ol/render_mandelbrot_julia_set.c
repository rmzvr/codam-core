/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mandelbrot_julia_set.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:16:06 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/06 17:44:16 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	naive_escape_time_calculation(int x, int y, t_mlx *mlx, t_set set)
{
	int		iteration;
	double	temp_re;

	iteration = 0;
	while (iteration < mlx->max_iterations)
	{
		temp_re = (set.z.re * set.z.re) - (set.z.im * set.z.im);
		set.z.im = 2 * set.z.re * set.z.im;
		set.z.re = temp_re;
		set.z.re += set.c.re;
		set.z.im += set.c.im;
		if ((set.z.re * set.z.re) + (set.z.im * set.z.im) > 4.0)
		{
			pixel_put(&mlx->img, x, y, get_selected_color(iteration, mlx));
			break ;
		}
		iteration++;
	}
	if (iteration == mlx->max_iterations)
		pixel_put(&mlx->img, x, y, COLOR_BLACK);
}

void	render_mandelbrot_julia_set(t_mlx *mlx, int x1, int y1)
{
	int	x;
	int	y;

	y = mlx->wh * 0.6;
	mlx->secondary_set.c.re = (scale_down_num(x1, mlx->curr_set.re_min,
				mlx->curr_set.re_max, mlx->ww - 1)) + mlx->shift.horizontal;
	mlx->secondary_set.c.im = (scale_down_num(y1, mlx->curr_set.im_min,
				mlx->curr_set.im_max, mlx->wh - 1)) + mlx->shift.vertical;
	while (y < mlx->wh - 20)
	{
		x = mlx->ww * 0.6;
		while (x < mlx->ww - 20)
		{
			if (x == mlx->ww * 0.6 || x == mlx->ww - 1 - 20
				|| y == mlx->wh * 0.6 || y == mlx->wh - 1 - 20)
			{
				pixel_put(&mlx->img, x, y, COLOR_WHITE);
				x++;
				continue ;
			}
			mlx->secondary_set.z.re = (scale_down_num(x - mlx->ww * 0.6,
						mlx->secondary_set.re_min, mlx->secondary_set.re_max,
						(mlx->ww - 1) - (mlx->ww * 0.6)));
			mlx->secondary_set.z.im = (scale_down_num(y - mlx->wh * 0.6,
						mlx->secondary_set.im_min, mlx->secondary_set.im_max,
						(mlx->wh - 1) - (mlx->wh * 0.6)));
			naive_escape_time_calculation(x, y, mlx, mlx->secondary_set);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
}
