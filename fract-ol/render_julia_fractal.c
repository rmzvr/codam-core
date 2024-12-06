/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_julia_fractal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:16:06 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/06 17:36:28 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_pixel_color(int x, int y, t_mlx *mlx)
{
	int		iteration;
	double	temp_re;
	t_set	set;

	iteration = 0;
	set = mlx->curr_set;
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

void	render_julia_fractal(t_mlx *mlx, double re, double im)
{
	int		x;
	int		y;

	y = 0;
	mlx->curr_set.c.re = re + mlx->shift.horizontal;
	mlx->curr_set.c.im = -im + mlx->shift.vertical;
	while (y < mlx->wh)
	{
		x = 0;
		while (x < mlx->ww)
		{
			mlx->curr_set.z.re = (scale_down_num(x, mlx->curr_set.re_min,
						mlx->curr_set.re_max, mlx->ww - 1));
			mlx->curr_set.z.im = (scale_down_num(y, mlx->curr_set.im_min,
						mlx->curr_set.im_max, mlx->wh - 1));
			get_pixel_color(x, y, mlx);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
}
