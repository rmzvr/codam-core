/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:09:17 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/03 14:32:49 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_close(t_mlx *mlx)
{
	cleanup(mlx);
	return (1);
}

int	handle_keyboard(int keysym, t_mlx *mlx)
{
	double	shift_factor;
	double	visible_width;
	double	visible_height;
	double	adjusted_x_shift;
	double	adjusted_y_shift;

	shift_factor = 0.05;
	visible_width = mlx->mandelbrot.re_max - mlx->mandelbrot.re_min;
	visible_height = mlx->mandelbrot.im_max - mlx->mandelbrot.im_min;
	adjusted_x_shift = shift_factor * visible_width;
	adjusted_y_shift = shift_factor * visible_height;
	if (keysym == XK_Escape)
		cleanup(mlx);
	else if (keysym == XK_Up)
		mlx->shift.vertical -= adjusted_y_shift;
	else if (keysym == XK_Down)
		mlx->shift.vertical += adjusted_y_shift;
	else if (keysym == XK_Left)
		mlx->shift.horizontal -= adjusted_x_shift;
	else if (keysym == XK_Right)
		mlx->shift.horizontal += adjusted_x_shift;
	render_mandelbrot_fractal(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
	return (0);
}


int handle_mouse(int button, int x, int y, t_mlx *mlx)
{
	double	scale_factor;
	double	x_ratio;
	double	y_ratio;
	double	delta_re;
	double	delta_im;
	double	double_delta_re;
	double	double_delta_im;
	if (button == 1)
		render_julia_fractal(mlx, x, y);
	if (button == 4 || button == 5)
	{
		scale_factor = ZOOM_SCALE_FACTOR;
		if (button == 5)
			scale_factor = 1 / scale_factor;

		x_ratio = x / (double)WINDOW_WIDTH;
		y_ratio = y / (double)WINDOW_HEIGHT;
		delta_re = mlx->mandelbrot.re_max - mlx->mandelbrot.re_min;
		delta_im = mlx->mandelbrot.im_max - mlx->mandelbrot.im_min;

		double_delta_re = (scale_factor * delta_re) - delta_re;
		double_delta_im = (scale_factor * delta_im) - delta_im;

		mlx->mandelbrot.re_min = mlx->mandelbrot.re_min - (double_delta_re * x_ratio);
		mlx->mandelbrot.re_max = mlx->mandelbrot.re_max + (double_delta_re * (1 - x_ratio));
		mlx->mandelbrot.im_min = mlx->mandelbrot.im_min - (double_delta_im * (y_ratio));
		mlx->mandelbrot.im_max = mlx->mandelbrot.im_max + (double_delta_im * (1 - y_ratio));

		render_mandelbrot_fractal(mlx);
		render_julia_fractal(mlx, x, y);
		mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
	}
	return (1);
}

int handle_mouse_move(int x, int y, t_mlx *mlx)
{
	(void) x;
	(void) y;
	(void) mlx;
	// double	scale_factor;
	// double	x_ratio;
	// double	y_ratio;
	// double	delta_re;
	// double	delta_im;
	// double	double_delta_re;
	// double	double_delta_im;
	// printf("x: %d, y: %d\n", x, y);
	// render_fractal(mlx, x, y);
	render_julia_fractal(mlx, x, y);
	// if (button == 4 || button == 5)
	// {
	// 	scale_factor = ZOOM_SCALE_FACTOR;
	// 	x_ratio = x / (double)WINDOW_WIDTH;
	// 	y_ratio = y / (double)WINDOW_HEIGHT;
	// 	delta_re = mlx->mandelbrot.re_max - mlx->mandelbrot.re_min;
	// 	delta_im = mlx->mandelbrot.im_max - mlx->mandelbrot.im_min;

	// 	if (button == 5)
	// 		scale_factor = 1 / scale_factor;

	// 	double_delta_re = (scale_factor * delta_re) - delta_re;
	// 	double_delta_im = (scale_factor * delta_im) - delta_im;

	// 	mlx->mandelbrot.re_min = mlx->mandelbrot.re_min - (double_delta_re * x_ratio);
	// 	mlx->mandelbrot.re_max = mlx->mandelbrot.re_max + (double_delta_re * (1 - x_ratio));
	// 	mlx->mandelbrot.im_min = mlx->mandelbrot.im_min - (double_delta_im * (y_ratio));
	// 	mlx->mandelbrot.im_max = mlx->mandelbrot.im_max + (double_delta_im * (1 - y_ratio));

	// 	render_mandelbrot_fractal(mlx);
	// 	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
	// }
	return (1);
}
