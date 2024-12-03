/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:16:06 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/02 17:40:01 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal(t_mlx *mlx)
{
	int	iteration;
	int	x;
	int	y;

	y = 0;
	//! Periodicity checking (save ~3sec) no effect with cardioid / bulb checking
	// double y_min = 0;
	// double y_max = WINDOW_HEIGHT;

	// if (mlx->im_min < 0 && mlx->im_max > 0)
	// {
	// 	if (mlx->im_max + mlx->im_min >= 0)
	// 		y_max = ((mlx->im_max * WINDOW_HEIGHT) / (mlx->im_max - mlx->im_min)) + 1;
	// 	else
	// 		y_min = ((mlx->im_max * WINDOW_HEIGHT) / (mlx->im_max - mlx->im_min));
	// }
	// y = y_min;
	// while (y < y_max)
	// {
	// 	x = 0;
	// 	while (x < WINDOW_WIDTH)
	// 	{
	// 		mlx->c.re = mlx->re_min + x * ((mlx->re_max - mlx->re_min) / WINDOW_WIDTH);
	// 		mlx->c.im = mlx->im_max - ((y) * ((mlx->re_max - mlx->re_min) / WINDOW_WIDTH));
			
	// 	}
	// }
	//!

	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		mlx->c.im = (scale_down_range(y, mlx->im_min, mlx->im_max, WINDOW_HEIGHT)) + mlx->shift.vertical;
		while (x < WINDOW_WIDTH)
		{
			iteration = 0;
			mlx->z.re = 0;
			mlx->z.im = 0;
			mlx->z_temp.re = 0;
			mlx->z_temp.im = 0;

			//! Periodicity checking (save ~3sec) no effect with cardioid / bulb checking
			// double xold = 0;
			// double yold = 0;
			// int period = 0;
			//!

			mlx->c.re = (scale_down_range(x, mlx->re_min, mlx->re_max, WINDOW_WIDTH)) + mlx->shift.horizontal;

			// //! Cardioid checking (save ~30sec on init render)
			double q = (mlx->c.re - 0.25) * (mlx->c.re - 0.25) + (mlx->c.im * mlx->c.im);
			if (q * (q + (mlx->c.re - 0.25)) < 0.25 * (mlx->c.im * mlx->c.im))
			{
				pixel_put(&mlx->img, x, y, COLOR_BLACK);
				x++;
				continue ;
			}
			// //!

			// //! The period-2 bulb checking (save ~5sec on init render)
			if ((mlx->c.re * mlx->c.re) + (2.0 * mlx->c.re) + 1.0 + (mlx->c.im * mlx->c.im) < 0.0625) {
				pixel_put(&mlx->img, x, y, COLOR_BLACK);
				x++;
				continue ;
			}
			// //!

			while (iteration < MAX_ITERATIONS)
			{
				//! Exterior distance estimation coloring
				// double	temp_zd_re = 2 * (mlx->z.re * mlx->z_temp.re - mlx->z.im * mlx->z_temp.im) + 1;
				// mlx->z_temp.im = 2 * (mlx->z.re * mlx->z_temp.im + mlx->z.im * mlx->z_temp.re);
				// mlx->z_temp.re = temp_zd_re;
				//!

				//! Unoptimized naïve escape time algorithm
				// double	temp_re = (mlx->z.re * mlx->z.re) - (mlx->z.im * mlx->z.im);
				// mlx->z.im = 2 * mlx->z.re * mlx->z.im;
				// mlx->z.re = temp_re;
				// mlx->z.re += mlx->c.re;
				// mlx->z.im += mlx->c.im;
				// int	res = (mlx->z.re * mlx->z.re) + (mlx->z.im * mlx->z.im);
				//!

				//! Optimized escape time algorithm
				mlx->z.im = (mlx->z.re + mlx->z.re) * mlx->z.im + mlx->c.im;
				mlx->z.re = mlx->z_temp.re - mlx->z_temp.im + mlx->c.re;
				mlx->z_temp.re = mlx->z.re * mlx->z.re;
				mlx->z_temp.im = mlx->z.im * mlx->z.im;
				double res = mlx->z_temp.re + mlx->z_temp.im;
				iteration++;

				//! Periodicity checking (save ~3sec) no effect with cardioid / bulb checking
				// if (mlx->z.re == xold && mlx->z.im == yold)
				// {
				// 	iteration = MAX_ITERATIONS;
				// 	break ;
				// }
				// period++;
				// if (period > 20)
				// {
				// 	period = 0;
				// 	xold = mlx->z.re;
				// 	yold = mlx->z.im;
				// }
				//!

				if (res > 4.0)
				{
					//! Exterior distance estimation coloring
					// double	d = (res * log(res)) / sqrt((mlx->z_temp.re * mlx->z_temp.re) + (mlx->z_temp.im * mlx->z_temp.im));
					// if (d < 0.00001)
					// 	pixel_put(&mlx->img, x, y, COLOR_BLACK);
					// else
					// 	pixel_put(&mlx->img, x, y, calculate_color(mlx));
					//!
					pixel_put(&mlx->img, x, y, calculate_smooth_color(iteration));
					break;
				}
			}
			if (iteration == MAX_ITERATIONS)
				pixel_put(&mlx->img, x, y, COLOR_BLACK);
			x++;
		}
		y++;
	}

	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
}