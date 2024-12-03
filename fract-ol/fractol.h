/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:00:44 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/03 15:23:32 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h>

#define ZOOM_SCALE_FACTOR 0.95

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000

#define MAX_ITERATIONS 100

#define COLOR_BLACK 0x000000
#define COLOR_WHITE 0xFFFFFF


typedef struct	s_img {
	void	*ptr;
	char	*pixels_addr;
	int		bpp;
	int		ll;
	int		endian;
}	t_img;

typedef struct	s_complex_n
{
	double	re;
	double	im;
}	t_complex_n;

typedef struct	s_shift
{
	double	horizontal;
	double	vertical;
}	t_shift;

typedef struct	s_set
{
	t_complex_n	c;
	t_complex_n	z;
	t_complex_n	z_temp;
	double		re_min;
	double		re_max;
	double		im_min;
	double		im_max;
}	t_set;

typedef struct	s_mlx {
	void		*ptr;
	void		*win_ptr;
	t_img		img;
	int			window_width;
	int			window_height;
	t_set		mandelbrot;
	t_set		julia;
	t_shift		shift;
}	t_mlx;

void	cleanup(t_mlx *mlx);
void	pixel_put(t_img *img, int x, int y, int color);
int		calculate_psychedelic_color(int iteration);
int		calculate_smooth_color(int iteration);

double	scale_sub_range(int coord, double min, double max, int start, int end);
double	scale_down_range(double unscaledNum, double minAllowed, double maxAllowed, double min, double max);

int		is_within_cardioid(double re, double im);
int		is_within_bulb(double re, double im);

int		handle_close(t_mlx *mlx);
int		handle_keyboard(int keysym, t_mlx *mlx);
int		handle_mouse(int button, int x, int y, t_mlx *mlx);
int handle_mouse_move(int x, int y, t_mlx *mlx);

void	render_mandelbrot_fractal(t_mlx *mlx);
void	render_julia_fractal(t_mlx *mlx, int x1, int y1);
void	render_fractol_with_periodicity_check(t_mlx *mlx);
void	render_fractol_with_exterior_distance_estimation_coloring(t_mlx *mlx);

#endif