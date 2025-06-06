/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mandelbrot_fractal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:13:24 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/09 17:15:15 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	reinit_set_values(t_set *set)
{
	set->z.re = 0;
	set->z.im = 0;
	set->z_temp.re = 0;
	set->z_temp.im = 0;
}

static void	get_pixel_color(int x, int y, t_mlx *mlx, t_set *set)
{
	int	iteration;

	iteration = 0;
	while (iteration < MAX_ITERATIONS)
	{
		set->z.im = (set->z.re + set->z.re) * set->z.im + set->c.im;
		set->z.re = set->z_temp.re - set->z_temp.im + set->c.re;
		set->z_temp.re = set->z.re * set->z.re;
		set->z_temp.im = set->z.im * set->z.im;
		if (set->z_temp.re + set->z_temp.im > 4.0)
		{
			pixel_put(&mlx->img, x, y, get_selected_color(iteration));
			break ;
		}
		iteration++;
	}
	if (iteration == MAX_ITERATIONS)
		pixel_put(&mlx->img, x, y, COLOR_BLACK);
}

void	render_mandelbrot_fractal(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	while (y < WH)
	{
		x = 0;
		mlx->curr_set.c.im = scale_n(y, mlx->curr_set.im_min,
				mlx->curr_set.im_max, WH - 1);
		while (x < WW)
		{
			reinit_set_values(&mlx->curr_set);
			mlx->curr_set.c.re = scale_n(x, mlx->curr_set.re_min,
					mlx->curr_set.re_max, WW - 1);
			if (is_within_shape(x, y, mlx))
			{
				x++;
				continue ;
			}
			get_pixel_color(x, y, mlx, &mlx->curr_set);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
}
