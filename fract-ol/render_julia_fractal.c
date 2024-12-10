/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_julia_fractal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:16:06 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/09 17:15:15 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	naive_escape_calculation(int x, int y, t_mlx *mlx, t_set set)
{
	int		iteration;
	double	temp_re;

	iteration = 0;
	while (iteration < MAX_ITERATIONS)
	{
		temp_re = (set.z.re * set.z.re) - (set.z.im * set.z.im);
		set.z.im = 2 * set.z.re * set.z.im;
		set.z.re = temp_re;
		set.z.re += set.c.re;
		set.z.im += set.c.im;
		if ((set.z.re * set.z.re) + (set.z.im * set.z.im) > 4.0)
		{
			pixel_put(&mlx->img, x, y, get_selected_color(iteration));
			break ;
		}
		iteration++;
	}
	if (iteration == MAX_ITERATIONS)
		pixel_put(&mlx->img, x, y, COLOR_BLACK);
}

static int	render_image_border(t_mlx *mlx, int *x, int y)
{
	if (*x == WW * 0.6 || *x == WW - 20 - 1
		|| y == WH * 0.6 || y == WH - 20 - 1)
	{
		pixel_put(&mlx->img, *x, y, COLOR_WHITE);
		(*x)++;
		return (1);
	}
	return (0);
}

void	render_julia_fractal(t_mlx *mlx, double re, double im)
{
	int		x;
	int		y;

	y = 0;
	mlx->curr_set.c.re = re;
	mlx->curr_set.c.im = -im;
	while (y < WH)
	{
		x = 0;
		while (x < WW)
		{
			mlx->curr_set.z.re = (scale_n(x, mlx->curr_set.re_min,
						mlx->curr_set.re_max, WW - 1));
			mlx->curr_set.z.im = (scale_n(y, mlx->curr_set.im_min,
						mlx->curr_set.im_max, WH - 1));
			naive_escape_calculation(x, y, mlx, mlx->curr_set);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
}

void	render_mandelbrot_julia_fractal(t_mlx *mlx, int x1, int y1)
{
	int	x;
	int	y;

	y = WH * 0.6;
	mlx->add_set.c.re = (scale_n(x1, mlx->curr_set.re_min,
				mlx->curr_set.re_max, WW - 1));
	mlx->add_set.c.im = (scale_n(y1, mlx->curr_set.im_min,
				mlx->curr_set.im_max, WH - 1));
	while (y < WH - 20)
	{
		x = WW * 0.6;
		while (x < WW - 20)
		{
			if (render_image_border(mlx, &x, y))
				continue ;
			mlx->add_set.z.re = (scale_n(x - WW * 0.6, mlx->add_set.re_min,
						mlx->add_set.re_max, (WW - 1) - (WW * 0.6)));
			mlx->add_set.z.im = (scale_n(y - WH * 0.6, mlx->add_set.im_min,
						mlx->add_set.im_max, (WH - 1) - (WH * 0.6)));
			naive_escape_calculation(x, y, mlx, mlx->add_set);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
}
