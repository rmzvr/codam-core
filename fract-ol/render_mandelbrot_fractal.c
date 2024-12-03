/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mandelbrot_fractal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:13:24 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/03 14:36:17 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_complex_number(t_mlx *mlx)
{
	mlx->mandelbrot.z.im = (mlx->mandelbrot.z.re + mlx->mandelbrot.z.re) * mlx->mandelbrot.z.im + mlx->mandelbrot.c.im;
	mlx->mandelbrot.z.re = mlx->mandelbrot.z_temp.re - mlx->mandelbrot.z_temp.im + mlx->mandelbrot.c.re;
	mlx->mandelbrot.z_temp.re = mlx->mandelbrot.z.re * mlx->mandelbrot.z.re;
	mlx->mandelbrot.z_temp.im = mlx->mandelbrot.z.im * mlx->mandelbrot.z.im;
}

void	render_mandelbrot_fractal(t_mlx *mlx)
{
	int		x;
	int		y;
	int		iteration;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		mlx->mandelbrot.c.im = (scale_down_range(y, mlx->mandelbrot.im_min, mlx->mandelbrot.im_max, 0, WINDOW_HEIGHT - 1)) + mlx->shift.vertical;
		while (x < WINDOW_WIDTH)
		{
			iteration = 0;
			mlx->mandelbrot.z.re = 0;
			mlx->mandelbrot.z.im = 0;
			mlx->mandelbrot.z_temp.re = 0;
			mlx->mandelbrot.z_temp.im = 0;
			mlx->mandelbrot.c.re = (scale_down_range(x, mlx->mandelbrot.re_min, mlx->mandelbrot.re_max, 0, WINDOW_WIDTH - 1)) + mlx->shift.horizontal;
			// printf("x: %d, y: %d, c.re: %f, c.im: %f\n", x, y, mlx->mandelbrot.c.re,  mlx->mandelbrot.c.im);
			if (is_within_bulb(mlx->mandelbrot.c.re, mlx->mandelbrot.c.im)
				|| is_within_cardioid(mlx->mandelbrot.c.re, mlx->mandelbrot.c.im))
			{
				pixel_put(&mlx->img, x, y, COLOR_BLACK);
				x++;
				continue ;
			}
			while (iteration < MAX_ITERATIONS)
			{
				calculate_complex_number(mlx);
				if (mlx->mandelbrot.z_temp.re + mlx->mandelbrot.z_temp.im > 4.0)
				{
					pixel_put(&mlx->img, x, y, calculate_smooth_color(iteration));
					break ;
				}
				iteration++;
			}
			if (iteration == MAX_ITERATIONS)
				pixel_put(&mlx->img, x, y, COLOR_BLACK);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
}
