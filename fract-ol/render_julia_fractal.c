/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_julia_fractal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:16:06 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/09 12:44:38 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	naive_escape_calculation(int x, int y, t_mlx *mlx, t_set set)
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

static int	render_image_border(t_mlx *mlx, int *x, int y)
{
	if (*x == mlx->ww * 0.6 || *x == mlx->ww - 20 - 1
		|| y == mlx->wh * 0.6 || y == mlx->wh - 20 - 1)
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
	while (y < mlx->wh)
	{
		x = 0;
		while (x < mlx->ww)
		{
			mlx->curr_set.z.re = (scale_n(x, mlx->curr_set.re_min,
						mlx->curr_set.re_max, mlx->ww - 1));
			mlx->curr_set.z.im = (scale_n(y, mlx->curr_set.im_min,
						mlx->curr_set.im_max, mlx->wh - 1));
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

	y = mlx->wh * 0.6;
	mlx->add_set.c.re = (scale_n(x1, mlx->curr_set.re_min,
				mlx->curr_set.re_max, mlx->ww - 1));
	mlx->add_set.c.im = (scale_n(y1, mlx->curr_set.im_min,
				mlx->curr_set.im_max, mlx->wh - 1));
	while (y < mlx->wh - 20)
	{
		x = mlx->ww * 0.6;
		while (x < mlx->ww - 20)
		{
			if (render_image_border(mlx, &x, y))
				continue ;
			mlx->add_set.z.re = (scale_n(x - mlx->ww * 0.6, mlx->add_set.re_min,
						mlx->add_set.re_max, (mlx->ww - 1) - (mlx->ww * 0.6)));
			mlx->add_set.z.im = (scale_n(y - mlx->wh * 0.6, mlx->add_set.im_min,
						mlx->add_set.im_max, (mlx->wh - 1) - (mlx->wh * 0.6)));
			naive_escape_calculation(x, y, mlx, mlx->add_set);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
}
