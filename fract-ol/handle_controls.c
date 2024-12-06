/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:09:17 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/06 17:13:09 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

void	scale_fractal(int x, int y, double scale_factor, t_mlx *mlx)
{
	double	x_ratio;
	double	y_ratio;
	double	d_re;
	double	d_im;

	x_ratio = x / (double)mlx->ww;
	y_ratio = y / (double)mlx->wh;
	d_re = mlx->curr_set.re_max - mlx->curr_set.re_min;
	d_im = mlx->curr_set.im_max - mlx->curr_set.im_min;
	mlx->curr_set.re_min -= ((scale_factor * d_re - d_re) * x_ratio);
	mlx->curr_set.re_max += ((scale_factor * d_re - d_re) * (1 - x_ratio));
	mlx->curr_set.im_min -= ((scale_factor * d_im - d_im) * (y_ratio));
	mlx->curr_set.im_max += ((scale_factor * d_im - d_im) * (1 - y_ratio));
}

int	handle_close(t_mlx *mlx)
{
	cleanup(mlx, 1);
	return (1);
}

void	render_selected_fractal(int x, int y, t_mlx *mlx)
{
	size_t	set_len;

	set_len = ft_strlen(mlx->curr_set_name);
	if (ft_strncmp(mlx->curr_set_name, "mandelbrot", set_len) == 0)
	{
		render_mandelbrot_fractal(mlx);
	}
	else if (ft_strncmp(mlx->curr_set_name, "julia", set_len) == 0)
	{
		render_julia_fractal(mlx, mlx->j_re, mlx->j_im);
	}
	else if (ft_strncmp(mlx->curr_set_name, "mandelbrot+julia", set_len) == 0)
	{
		render_mandelbrot_fractal(mlx);
		render_mandelbrot_julia_set(mlx, x, y);
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
}

int	handle_keyboard(int keysym, t_mlx *mlx)
{
	double	shift_factor;
	double	visible_width;
	double	visible_height;
	double	adjusted_x_shift;
	double	adjusted_y_shift;

	shift_factor = 0.05;
	visible_width = mlx->curr_set.re_max - mlx->curr_set.re_min;
	visible_height = mlx->curr_set.im_max - mlx->curr_set.im_min;
	adjusted_x_shift = shift_factor * visible_width;
	adjusted_y_shift = shift_factor * visible_height;
	if (keysym == XK_Escape)
		cleanup(mlx, 1);
	else if (keysym == XK_Up)
		mlx->shift.vertical -= adjusted_y_shift;
	else if (keysym == XK_Down)
		mlx->shift.vertical += adjusted_y_shift;
	else if (keysym == XK_Left)
		mlx->shift.horizontal -= adjusted_x_shift;
	else if (keysym == XK_Right)
		mlx->shift.horizontal += adjusted_x_shift;
	render_selected_fractal(mlx->ww / 2, mlx->wh / 2, mlx);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_mlx *mlx)
{
	double	scale_factor;

	if (button == 1 && !ft_strncmp(
			mlx->curr_set_name,
			"mandelbrot+julia",
			ft_strlen("mandelbrot+julia"))
	)
	{
		render_mandelbrot_julia_set(mlx, x, y);
	}
	if (button == 4 || button == 5)
	{
		scale_factor = 1.0 / mlx->scale_factor;
		if (button == 5)
		{
			scale_factor = mlx->scale_factor;
		}
		scale_fractal(x, y, scale_factor, mlx);
		render_selected_fractal(x, y, mlx);
	}
	return (1);
}

int	handle_mouse_move(int x, int y, t_mlx *mlx)
{
	if (!ft_strncmp(
			mlx->curr_set_name,
			"mandelbrot+julia",
			ft_strlen("mandelbrot+julia")))
	{
		render_mandelbrot_julia_set(mlx, x, y);
	}
	return (1);
}
