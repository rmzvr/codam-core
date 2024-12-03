/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:11:45 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/03 15:13:18 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_mlx_struct(t_mlx *mlx)
{
	double	aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;

	double	mandelbrot_real_range = 2.5;
	double	mandelbrot_imaginary_range = mandelbrot_real_range / aspect_ratio;

	double	mandelbrot_center_re = -0.75;
	double	mandelbrot_center_im = 0.0;

	mlx->mandelbrot.re_min = mandelbrot_center_re - mandelbrot_real_range / 2.0;
	mlx->mandelbrot.re_max = mandelbrot_center_re + mandelbrot_real_range / 2.0;
	mlx->mandelbrot.im_min = mandelbrot_center_im - mandelbrot_imaginary_range / 2.0;
	mlx->mandelbrot.im_max = mandelbrot_center_im + mandelbrot_imaginary_range / 2.0;

	double	julia_real_range = 4.0;
	double	julia_imaginary_range = julia_real_range / aspect_ratio;
	
	double	julia_center_re = 0.0;
	double	julia_center_im = 0.0;

	mlx->julia.re_min = julia_center_re - julia_real_range / 2.0;
	mlx->julia.re_max = julia_center_re + julia_real_range / 2.0;
	mlx->julia.im_min = julia_center_im - julia_imaginary_range / 2.0;
	mlx->julia.im_max = julia_center_im + julia_imaginary_range / 2.0;

	mlx->ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->img.ptr = NULL;
	mlx->shift.horizontal = 0.0;
	mlx->shift.vertical = 0.0;
}

int	main(void)
{
	t_mlx	mlx;

	init_mlx_struct(&mlx);
	mlx.ptr = mlx_init();
	if (mlx.ptr == NULL)
		return (1);
	mlx.win_ptr = mlx_new_window(mlx.ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"Fractol");
	if (mlx.win_ptr == NULL)
		cleanup(&mlx);
	mlx.img.ptr = mlx_new_image(mlx.ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (mlx.img.ptr == NULL)
		cleanup(&mlx);
	mlx.img.pixels_addr = mlx_get_data_addr(mlx.img.ptr, &mlx.img.bpp,
			&mlx.img.ll, &mlx.img.endian);
	if (mlx.img.pixels_addr == NULL)
		cleanup(&mlx);
	render_mandelbrot_fractal(&mlx);
	render_julia_fractal(&mlx, 0, 0);
	mlx_hook(mlx.win_ptr, 17, (1L << 3), handle_close, &mlx);
	mlx_hook(mlx.win_ptr, 05, (1L << 2), handle_mouse, &mlx);
	mlx_hook(mlx.win_ptr, 06, (1L << 8), handle_mouse_move, &mlx);
	mlx_hook(mlx.win_ptr, 03, (1L << 1), handle_keyboard, &mlx);
	mlx_loop(mlx.ptr);
	cleanup(&mlx);
	return (0);
}
