/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:00:44 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/06 17:02:33 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysym.h>

# define ZOOM_SCALE_FACTOR 1.5

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1920

# define MAX_ITERATIONS 100

# define COLOR_BLACK 0x000000
# define COLOR_WHITE 0xFFFFFF

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

typedef struct s_shift
{
	double	horizontal;
	double	vertical;
}	t_shift;

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

typedef struct s_position
{
	int	start_x;
	int	end_x;
	int	start_y;
	int	end_y;
}	t_position;


typedef struct s_mlx
{
	void		*ptr;
	void		*win_ptr;
	t_img		img;
	double		scale_factor;
	double		j_re;
	double		j_im;
	int			ww;
	int			wh;
	int			max_iterations;
	char		*palette;
	t_set		mandelbrot;
	t_set		julia;
	t_shift		shift;
	t_set		curr_set;
	t_set		primary_set;
	t_set		secondary_set;
	char		*curr_set_name;
}	t_mlx;

void	bind_control_hooks(t_mlx *mlx);
void	init_mlx_window_and_image(t_mlx *mlx, char *title);
void	center_set_on_plane(t_set *set, t_mlx *mlx);
void	init_data_struct(t_mlx *mlx);
void	init_set(t_mlx *mlx, char *set);

void	cleanup(t_mlx *mlx, unsigned int with_exit);
void	pixel_put(t_img *img, int x, int y, int color);
int		get_psychedelic_color(int iteration, int max_iterations);
int		get_smooth_color(int iteration, int max_iterations);
int		get_selected_color(int i, t_mlx *mlx);
double	scale_down_num(double num, double min_new, double max_new, double max);

int		is_within_cardioid(double re, double im);
int		is_within_bulb(double re, double im);

int		handle_close(t_mlx *mlx);
int		handle_keyboard(int keysym, t_mlx *mlx);
int		handle_mouse(int button, int x, int y, t_mlx *mlx);
int		handle_mouse_move(int x, int y, t_mlx *mlx);

void	render_mandelbrot_fractal(t_mlx *mlx);
void	render_julia_fractal(t_mlx *mlx, double re, double im);
void	render_mandelbrot_julia_set(t_mlx *mlx, int x1, int y1);

#endif