/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:11:45 by rzvir             #+#    #+#             */
/*   Updated: 2024/11/25 17:47:57 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <math.h>

typedef struct	s_img {
	void	*ptr;
	char	*pixels_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct	s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef struct	s_shift
{
	int	top;
	int	left;
	int	right;
	int	bottom;
}	t_shift;

typedef struct	s_mlx {
	void		*ptr;
	void		*win_ptr;
	t_img		img;
	int			iterations;
	int			max_iterations;
	t_complex	z;
	t_complex	zd;
	t_complex	c;
	int			window_width;
	int			window_height;
	int			x;
	int			y;
	double		zoom;
	t_shift		shift;
	int			current_buffer;
}	t_mlx;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int				offset;
	unsigned int	*curr_pixel;

	offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	curr_pixel = (unsigned int *)(img->pixels_addr + offset);
	*curr_pixel = color;
}

double	scale_x(int i, int width)
{
	double d_i;
	double d_width;

	d_i = (double) i;
	d_width = (double) width;
	return (1.0 - -2.0) * (i - 0.0) / (d_width - 0.0) + -2.0;
}

double	scale_y(int i, int height)
{
	double d_i;
	double d_height;

	d_i = (double) i;
	d_height = (double) height;
	return (1.5 - -1.5) * (i - 0.0) / (d_height - 0.0) + -1.5;
}

int	encode_rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red << 16 | green << 8 | blue);
}

void	render_fractal(t_mlx *mlx, double zoom, t_shift shift, t_img *img)
{
	while (mlx->y < mlx->window_height)
	{
		mlx->x = 0;
		mlx->c.imaginary = (scale_y(mlx->y + shift.bottom, mlx->window_height)) * zoom;
		while (mlx->x < mlx->window_width)
		{
			mlx->iterations = 0;
			mlx->z.real = 0;
			mlx->z.imaginary = 0;
			mlx->zd.real = 0;
			mlx->zd.imaginary = 0;
			mlx->c.real = (scale_x(mlx->x + shift.right, mlx->window_width)) * zoom;
			while (mlx->iterations < mlx->max_iterations)
			{

				double temp_zd_real = 2 * (mlx->z.real * mlx->zd.real - mlx->z.imaginary * mlx->zd.imaginary) + 1;
				mlx->zd.imaginary = 2 * (mlx->z.real * mlx->zd.imaginary + mlx->z.imaginary * mlx->zd.real);
				mlx->zd.real = temp_zd_real;

				double temp_real = (mlx->z.real * mlx->z.real) - (mlx->z.imaginary * mlx->z.imaginary);
				mlx->z.imaginary = 2 * mlx->z.real * mlx->z.imaginary;
				mlx->z.real = temp_real;
				mlx->z.real += mlx->c.real;
				mlx->z.imaginary += mlx->c.imaginary;
				int	res = (mlx->z.real * mlx->z.real) + (mlx->z.imaginary * mlx->z.imaginary);
				if (res > 4)
				{
					double	d = (res * log(res)) / sqrt((mlx->zd.real * mlx->zd.real) + (mlx->zd.imaginary * mlx->zd.imaginary));
					if (d < 0.0001)
						my_mlx_pixel_put(img, mlx->x, mlx->y, encode_rgb(0, 0, 0));
					else
						my_mlx_pixel_put(img, mlx->x, mlx->y, encode_rgb(255, 255, 255));
					// my_mlx_pixel_put(img, mlx->x, mlx->y, encode_rgb(255, 255, 255));
					break;
				}
				mlx->iterations++;
			}
			if (mlx->iterations == mlx->max_iterations)
				my_mlx_pixel_put(img, mlx->x, mlx->y, encode_rgb(0, 0, 0));
			mlx->x++;
		}
		mlx->y++;
	}
}

int	handle_input(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(mlx->ptr, mlx->img.ptr);
		mlx_destroy_window(mlx->ptr, mlx->win_ptr);
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		exit(1);
	}

	if (keysym == XK_Up)
	{
		printf("XK_Up\n");
		mlx->shift.bottom -= 200;
		printf("bottom = %d\n", mlx->shift.bottom);
		render_fractal(mlx, mlx->zoom, mlx->shift, &mlx->img);
		mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
	}
	else if (keysym == XK_Down)
	{
		printf("XK_Down\n");
		mlx->shift.bottom += 200;
		printf("bottom = %d\n", mlx->shift.bottom);
		render_fractal(mlx, mlx->zoom, mlx->shift, &mlx->img);
		mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
	}
	else if (keysym == XK_Left)
	{
		printf("XK_Left\n");
		mlx->shift.right -= 200;
		printf("right = %d\n", mlx->shift.right);
		render_fractal(mlx, mlx->zoom, mlx->shift, &mlx->img);
		mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
	}
	else if (keysym == XK_Right)
	{
		printf("XK_Right\n");
		mlx->shift.right += 200;
		printf("right = %d\n", mlx->shift.right);
		render_fractal(mlx, mlx->zoom, mlx->shift, &mlx->img);
		mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
	}
	return (0);
}

int mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	(void) x;
	(void) y;

	if (button == 4)
	{
		printf("XK_equal\n");
		if (mlx->zoom < 0.11)
			mlx->zoom -= 0.01;
		else
			mlx->zoom -= 0.1;
		printf("zoom = %f\n", mlx->zoom);
		render_fractal(mlx, mlx->zoom, mlx->shift, &mlx->img);
		mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
	}
	else if (button == 5)
	{
		printf("XK_minus\n");
		mlx->zoom += 0.1;
		render_fractal(mlx, mlx->zoom, mlx->shift, &mlx->img);
		mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
	}
	return (1);
}

int	main(void)
{
	t_mlx	mlx;
	mlx.x = 0;
	mlx.y = 0;
	mlx.zoom = 1.0;
	mlx.shift.top = 0;
	mlx.shift.left = 0;
	mlx.shift.right = 0;
	mlx.shift.bottom = 0;
	mlx.window_width = 1920;
	mlx.window_height = 1920;
	mlx.max_iterations = 6;

	//! Initiate mlx library
	mlx.ptr = mlx_init();
	if (mlx.ptr == NULL)
		return (1);

	//! Create new window
	mlx.win_ptr = mlx_new_window(mlx.ptr, mlx.window_width, mlx.window_height, "Hello world!");
	if (mlx.win_ptr == NULL)
	{
		mlx_destroy_display(mlx.ptr);
		free(mlx.ptr);
		return (1);
	}

	//! Create new image
	mlx.img.ptr = mlx_new_image(mlx.ptr, mlx.window_width, mlx.window_height);
	if (mlx.img.ptr == NULL)
	{
		mlx_destroy_window(mlx.ptr, mlx.win_ptr);
		mlx_destroy_display(mlx.ptr);
		free(mlx.ptr);
		exit(1);
	}
	//! Get image pointer address
	mlx.img.pixels_addr = mlx_get_data_addr(mlx.img.ptr, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	if (mlx.img.pixels_addr == NULL)
	{
		mlx_destroy_image(mlx.ptr, mlx.img.ptr);
		mlx_destroy_window(mlx.ptr, mlx.win_ptr);
		mlx_destroy_display(mlx.ptr);
		free(mlx.ptr);
		exit(1);
	}

	//! Render fractal
	render_fractal(&mlx, mlx.zoom, mlx.shift, &mlx.img);
	mlx_put_image_to_window(mlx.ptr, mlx.win_ptr, mlx.img.ptr, 0, 0);

	//! Graphic management
	mlx_key_hook(mlx.win_ptr, handle_input, &mlx);
	mlx_mouse_hook(mlx.win_ptr, mouse_hook, &mlx);

	//! Keep running
	mlx_loop(mlx.ptr);

	//! Clean up
	mlx_destroy_image(mlx.ptr, mlx.img.ptr);
	mlx_destroy_window(mlx.ptr, mlx.win_ptr);
	mlx_destroy_display(mlx.ptr);
	free(mlx.ptr);
	return (0);
}
