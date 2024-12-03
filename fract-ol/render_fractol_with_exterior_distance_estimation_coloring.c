/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractol_with_exterior_distance_estim        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:07:47 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/02 13:15:18 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractol_with_exterior_distance_estimation_coloring(t_mlx *mlx)
{
	int	iteration;
	int	x;
	int	y;

	y = 0;
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
			mlx->c.real = (scale_down_range(x, mlx->zoom.re_min, mlx->zoom.re_max, mlx->window_width)) + mlx->shift.horizontal;
			while (iteration < MAX_ITERATIONS)
			{
				double	temp_zd_real = 2 * (mlx->z.real * mlx->zd.real - mlx->z.imaginary * mlx->zd.imaginary) + 1;
				mlx->zd.imaginary = 2 * (mlx->z.real * mlx->zd.imaginary + mlx->z.imaginary * mlx->zd.real);
				mlx->zd.real = temp_zd_real;

				double	temp_real = (mlx->z.real * mlx->z.real) - (mlx->z.imaginary * mlx->z.imaginary);
				mlx->z.imaginary = 2 * mlx->z.real * mlx->z.imaginary;
				mlx->z.real = temp_real;
				mlx->z.real += mlx->c.real;
				mlx->z.imaginary += mlx->c.imaginary;
				int	res = (mlx->z.real * mlx->z.real) + (mlx->z.imaginary * mlx->z.imaginary);
				iteration++;
				if (res > 4.0)
				{
					double	d = (res * log(res)) / sqrt((mlx->zd.real * mlx->zd.real) + (mlx->zd.imaginary * mlx->zd.imaginary));
					if (d < 0.00001)
						pixel_put(&mlx->img, x, y, COLOR_BLACK);
					else
						pixel_put(&mlx->img, x, y, COLOR_WHITE);
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
