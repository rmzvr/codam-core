/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_julia_fractal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:16:06 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/03 15:27:56 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_julia_fractal(t_mlx *mlx, int x1, int y1)
{
	int	iteration;
	int	x;
	int	y;
	(void) x1;
	(void) y1;

	y = WINDOW_HEIGHT * 0.5;
	mlx->julia.c.re = (scale_down_range(x1, mlx->mandelbrot.re_min, mlx->mandelbrot.re_max, 0, WINDOW_WIDTH - 1)) + mlx->shift.horizontal;
	mlx->julia.c.im = (scale_down_range(y1, mlx->mandelbrot.im_min, mlx->mandelbrot.im_max, 0, WINDOW_HEIGHT - 1)) + mlx->shift.vertical;
	while (y < WINDOW_HEIGHT)
	{
		x = WINDOW_WIDTH * 0.5;
		while (x < WINDOW_WIDTH)
		{
			// if (x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
			// {
			// 	pixel_put(&mlx->img, x, y, COLOR_WHITE);
			// 	continue ;
			// }
			// printf("x: %d, y: %d\n", x, y);
			iteration = 0;
			mlx->julia.z.re = (scale_down_range(x, mlx->julia.re_min, mlx->julia.re_max, WINDOW_WIDTH * 0.5, WINDOW_WIDTH - 1));
			mlx->julia.z.im = (scale_down_range(y, mlx->julia.im_min, mlx->julia.im_max, WINDOW_HEIGHT * 0.5, WINDOW_HEIGHT - 1));
			while (iteration < MAX_ITERATIONS)
			{
				double	temp_re = (mlx->julia.z.re * mlx->julia.z.re) - (mlx->julia.z.im * mlx->julia.z.im);
				mlx->julia.z.im = 2 * mlx->julia.z.re * mlx->julia.z.im;
				mlx->julia.z.re = temp_re;
				mlx->julia.z.re += mlx->julia.c.re;
				mlx->julia.z.im += mlx->julia.c.im;
				if ((mlx->julia.z.re * mlx->julia.z.re) + (mlx->julia.z.im * mlx->julia.z.im) > 4.0)
				{
					pixel_put(&mlx->img, x, y, calculate_smooth_color(iteration));
					break;
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