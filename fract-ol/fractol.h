/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:00:44 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/10 11:09:33 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include "libft/libft.h"

# define MAX_ITERATIONS 100
# define PALETTE "smooth"
# define SCALE_FACTOR 1.5
# define WW 1000
# define WH 1000

# define COLOR_BLACK 0x000000
# define COLOR_WHITE 0xFFFFFF

# define SET_MB "mandelbrot"
# define SET_JL "julia"
# define SET_MB_JL "mandelbrot+julia"

typedef struct s_img
{
	void	*ptr;
	char	*pixels_addr;
	int		bpp;
	int		ll;
	int		endian;
}	t_img;

typedef struct s_complex_n
{
	double	re;
	double	im;
}	t_complex_n;

typedef struct s_set
{
	t_complex_n	c;
	t_complex_n	z;
	t_complex_n	z_temp;
	double		re_min;
	double		re_max;
	double		im_min;
	double		im_max;
	double		center_re;
	double		center_im;
	double		range_re;
}	t_set;

typedef struct s_mlx
{
	void		*ptr;
	void		*win_ptr;
	t_img		img;
	double		j_re;
	double		j_im;
	t_set		curr_set;
	t_set		add_set;
	char		*curr_set_name;
}	t_mlx;

void	pixel_put(t_img *img, int x, int y, int color);

void	init_project(t_mlx *mlx);

void	show_help_and_exit(void);
void	cleanup(t_mlx *mlx, unsigned int with_exit);

int		get_selected_color(int i);

double	scale_n(double num, double min_new, double max_new, double max);

int		is_within_shape(int x, int y, t_mlx *mlx);

void	scale_view(int x, int y, double scale_factor, t_mlx *mlx);

void	bind_control_hooks(t_mlx *mlx);

void	render_mandelbrot_fractal(t_mlx *mlx);
void	render_julia_fractal(t_mlx *mlx, double re, double im);
void	render_mandelbrot_julia_fractal(t_mlx *mlx, int x1, int y1);
void	render_selected_fractal(int x, int y,t_mlx *mlx);

void	scale_view(int x, int y, double scale_factor, t_mlx *mlx);
void	shift_horizontal_view(t_set *set, char *direction);
void	shift_vertical_view(t_set *set, char *direction);
void	center_fractal_on_plane(t_set *set);
double	ft_atof(char *str);
int		is_valid_double(char *str);

#endif