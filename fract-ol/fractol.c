/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:11:45 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/06 17:34:32 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

void	init_data_struct(t_mlx *mlx)
{
	mlx->scale_factor = 1.5;
	mlx->ww = 1000;
	mlx->wh = 1000;
	mlx->max_iterations = 100;
	mlx->ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->img.ptr = NULL;
	mlx->shift.horizontal = 0.0;
	mlx->shift.vertical = 0.0;
	mlx->mandelbrot.range_re = 2.5;
	mlx->mandelbrot.center_re = -0.75;
	mlx->mandelbrot.center_im = 0.0;
	mlx->julia.range_re = 4.0;
	mlx->julia.center_re = 0.0;
	mlx->julia.center_im = 0.0;
	mlx->palette = "smooth";
}

void	center_set_on_plane(t_set *set, t_mlx *mlx)
{
	double	scale;
	double	aspect_ratio;
	double	range_im;

	scale = 2.0;
	aspect_ratio = (double)mlx->ww / (double)mlx->wh;
	range_im = set->range_re / aspect_ratio;
	set->re_min = set->center_re - set->range_re / scale;
	set->re_max = set->center_re + set->range_re / scale;
	set->im_min = set->center_im - range_im / scale;
	set->im_max = set->center_im + range_im / scale;
}

void	init_set(t_mlx *mlx, char *set)
{
	if (ft_strncmp(set, "mandelbrot", ft_strlen(set)) == 0)
	{
		mlx->curr_set.range_re = 2.5;
		mlx->curr_set.center_re = -0.75;
		mlx->curr_set.center_im = 0.0;
	}
	else if (ft_strncmp(set, "julia", ft_strlen(set)) == 0)
	{
		mlx->curr_set.range_re = 4.0;
		mlx->curr_set.center_re = 0.0;
		mlx->curr_set.center_im = 0.0;
	}
	else if (ft_strncmp(set, "mandelbrot+julia", ft_strlen(set)) == 0)
	{
		mlx->curr_set.range_re = 2.5;
		mlx->curr_set.center_re = -0.75;
		mlx->curr_set.center_im = 0.0;
		mlx->secondary_set.range_re = 4.0;
		mlx->secondary_set.center_re = 0.0;
		mlx->secondary_set.center_im = 0.0;
		center_set_on_plane(&mlx->secondary_set, mlx);
	}
	center_set_on_plane(&mlx->curr_set, mlx);
}

void	init_mlx_window_and_image(t_mlx *mlx, char *title)
{
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		exit(1);
	mlx->win_ptr = mlx_new_window(mlx->ptr, mlx->ww, mlx->wh, title);
	if (mlx->win_ptr == NULL)
		cleanup(mlx, 1);
	mlx->img.ptr = mlx_new_image(mlx->ptr, mlx->ww, mlx->wh);
	if (mlx->img.ptr == NULL)
		cleanup(mlx, 1);
	mlx->img.pixels_addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp,
			&mlx->img.ll, &mlx->img.endian);
	if (mlx->img.pixels_addr == NULL)
		cleanup(mlx, 1);
}

void	bind_control_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, 17, (1L << 3), handle_close, mlx);
	mlx_hook(mlx->win_ptr, 05, (1L << 2), handle_mouse, mlx);
	mlx_hook(mlx->win_ptr, 06, (1L << 8), handle_mouse_move, mlx);
	mlx_hook(mlx->win_ptr, 03, (1L << 1), handle_keyboard, mlx);
}
