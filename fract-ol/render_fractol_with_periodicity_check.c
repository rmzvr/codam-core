/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractol_with_periodicity_check.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:56:25 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/02 13:15:28 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractol_with_periodicity_check(t_mlx *mlx)
{
	int	iteration;
	int	x;
	int	y;

	y = 0;
	//! Periodicity checking (save ~3sec) no effect with cardioid / bulb checking
	// double y_min = 0;
	// double y_max = mlx->window_height;

	// if (mlx->zoom.im_min < 0 && mlx->zoom.im_max > 0)
	// {
	// 	if (mlx->zoom.im_max + mlx->zoom.im_min >= 0)
	// 		y_max = ((mlx->zoom.im_max * mlx->window_height) / (mlx->zoom.im_max - mlx->zoom.im_min)) + 1;
	// 	else
	// 		y_min = ((mlx->zoom.im_max * mlx->window_height) / (mlx->zoom.im_max - mlx->zoom.im_min));
	// }
	// y = y_min;
	// while (y < y_max)
	// {
	// 	x = 0;
	// 	while (x < mlx->window_width)
	// 	{
	// 		mlx->c.real = mlx->zoom.re_min + x * ((mlx->zoom.re_max - mlx->zoom.re_min) / mlx->window_width);
	// 		mlx->c.imaginary = mlx->zoom.im_max - ((y) * ((mlx->zoom.re_max - mlx->zoom.re_min) / mlx->window_width));
			
	// 	}
	// }
	//!

	while (y < mlx->window_height)
	{
		x = 0;
		mlx->c.imaginary = (scale_down_range(y, mlx->zoom.im_min, mlx->zoom.im_max, mlx->window_height)) + mlx->shift.vertical;
		while (x < mlx->window_width)
		{
			iteration = 0;
			mlx->z.real = 0;
			mlx->z.imaginary = 0;
			mlx->zd.real = 0;
			mlx->zd.imaginary = 0;

			//! Periodicity checking (save ~3sec) no effect with cardioid / bulb checking
			// double xold = 0;
			// double yold = 0;
			// int period = 0;
			//!

			mlx->c.real = (scale_down_range(x, mlx->zoom.re_min, mlx->zoom.re_max, mlx->window_width)) + mlx->shift.horizontal;

			// //! Cardioid checking (save ~30sec on init render)
			double q = (mlx->c.real - 0.25) * (mlx->c.real - 0.25) + (mlx->c.imaginary * mlx->c.imaginary);
			if (q * (q + (mlx->c.real - 0.25)) < 0.25 * (mlx->c.imaginary * mlx->c.imaginary))
			{
				pixel_put(&mlx->img, x, y, COLOR_BLACK);
				x++;
				continue ;
			}
			// //!

			// //! The period-2 bulb checking (save ~5sec on init render)
			if ((mlx->c.real * mlx->c.real) + (2.0 * mlx->c.real) + 1.0 + (mlx->c.imaginary * mlx->c.imaginary) < 0.0625) {
				pixel_put(&mlx->img, x, y, COLOR_BLACK);
				x++;
				continue ;
			}
			// //!

			while (iteration < MAX_ITERATIONS)
			{
				//! Exterior distance estimation coloring
				// double	temp_zd_real = 2 * (mlx->z.real * mlx->zd.real - mlx->z.imaginary * mlx->zd.imaginary) + 1;
				// mlx->zd.imaginary = 2 * (mlx->z.real * mlx->zd.imaginary + mlx->z.imaginary * mlx->zd.real);
				// mlx->zd.real = temp_zd_real;
				//!

				//! Unoptimized naïve escape time algorithm
				// double	temp_real = (mlx->z.real * mlx->z.real) - (mlx->z.imaginary * mlx->z.imaginary);
				// mlx->z.imaginary = 2 * mlx->z.real * mlx->z.imaginary;
				// mlx->z.real = temp_real;
				// mlx->z.real += mlx->c.real;
				// mlx->z.imaginary += mlx->c.imaginary;
				// int	res = (mlx->z.real * mlx->z.real) + (mlx->z.imaginary * mlx->z.imaginary);
				//!

				//! Optimized escape time algorithm
				mlx->z.imaginary = (mlx->z.real + mlx->z.real) * mlx->z.imaginary + mlx->c.imaginary;
				mlx->z.real = mlx->zd.real - mlx->zd.imaginary + mlx->c.real;
				mlx->zd.real = mlx->z.real * mlx->z.real;
				mlx->zd.imaginary = mlx->z.imaginary * mlx->z.imaginary;
				double res = mlx->zd.real + mlx->zd.imaginary;
				iteration++;

				//! Periodicity checking (save ~3sec) no effect with cardioid / bulb checking
				// if (mlx->z.real == xold && mlx->z.imaginary == yold)
				// {
				// 	iteration = MAX_ITERATIONS;
				// 	break ;
				// }
				// period++;
				// if (period > 20)
				// {
				// 	period = 0;
				// 	xold = mlx->z.real;
				// 	yold = mlx->z.imaginary;
				// }
				//!

				if (res > 4.0)
				{
					//! Exterior distance estimation coloring
					// double	d = (res * log(res)) / sqrt((mlx->zd.real * mlx->zd.real) + (mlx->zd.imaginary * mlx->zd.imaginary));
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