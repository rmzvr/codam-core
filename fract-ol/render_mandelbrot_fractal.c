/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mandelbrot_fractal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:13:24 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/06 17:24:29 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

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
	while (iteration < mlx->max_iterations)
	{
		set->z.im = (set->z.re + set->z.re) * set->z.im + set->c.im;
		set->z.re = set->z_temp.re - set->z_temp.im + set->c.re;
		set->z_temp.re = set->z.re * set->z.re;
		set->z_temp.im = set->z.im * set->z.im;
		if (set->z_temp.re + set->z_temp.im > 4.0)
		{
			pixel_put(&mlx->img, x, y, get_selected_color(iteration, mlx));
			break ;
		}
		iteration++;
	}
	if (iteration == mlx->max_iterations)
		pixel_put(&mlx->img, x, y, COLOR_BLACK);
}

int	is_within_shape(int x, int y, t_mlx *mlx)
{
	if (is_within_bulb(mlx->curr_set.c.re, mlx->curr_set.c.im)
		|| is_within_cardioid(mlx->curr_set.c.re, mlx->curr_set.c.im))
	{
		pixel_put(&mlx->img, x, y, COLOR_BLACK);
		return (1);
	}
	return (0);
}

void	render_mandelbrot_fractal(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	while (y < mlx->wh)
	{
		x = 0;
		mlx->curr_set.c.im = scale_down_num(y, mlx->curr_set.im_min,
				mlx->curr_set.im_max, mlx->wh - 1) + mlx->shift.vertical;
		while (x < mlx->ww)
		{
			reinit_set_values(&mlx->curr_set);
			mlx->curr_set.c.re = scale_down_num(x, mlx->curr_set.re_min,
					mlx->curr_set.re_max, mlx->ww - 1) + mlx->shift.horizontal;
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
