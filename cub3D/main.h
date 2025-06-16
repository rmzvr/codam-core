/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:06:23 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/16 17:20:34 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <sys/time.h>
# include <X11/keysym.h>

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

# define mapWidth 25
# define mapHeight 25
# define cellSize 30
# define playerSize 10
# define stepSize cellSize / 6
# define screenSize mapWidth * cellSize
# define CAMERA_PLANE_X 0.0
# define CAMERA_PLANE_Y 0.66

typedef enum s_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;


typedef enum	e_hit_side {
	VERTICAL,
	HORIZONTAL,
}	t_hit_side;

typedef struct s_dda_data
{
	t_hit_side	hit_side;

	double	ray_direction_x;
	double	ray_direction_y;

	int		step_direction_x;
	int		step_direction_y;

	double	distance_to_wall;
	int		wall_color;
	int		wall_start;
	int		wall_end;
}	t_dda_data;


typedef struct s_ray_trace_data
{
	t_bool	hit;

	int		current_tail_x;
	int		current_tail_y;

	double	ray_distance_x;
	double	ray_distance_y;

	double	total_ray_distance_x;
	double	total_ray_distance_y;
}	t_ray_trace_data;

extern char map[mapHeight][mapWidth];

typedef enum	e_element {
	FLOOR,
	WALL,
}	t_element;

typedef enum	e_direction {
	TOP,
	RIGHT,
	BOTTOM,
	LEFT,
}	t_direction;

typedef struct s_player_position
{
	int	cell_x;
	int	cell_y;
}	t_player_position;

typedef struct s_img
{
	void	*ptr;
	char	*pixels_addr;
	int		bpp;
	int		ll;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*win_ptr;
	t_img	img;
}	t_mlx;

typedef struct s_game
{
	int					x;
	int					y;
	int					mapWidthPx;
	int					mapHeightPx;
	int					shiftX;
	int					shiftY;
	int					init_cell_pos_x;
	int					init_cell_pos_y;
	double				bx;
	double				by;
	double				vector_x_start;
	double				vector_y_start;
	int					vector_x_end;
	int					vector_y_end;
	t_player_position	player_position;

	double				pos_x;
	double				pos_y;

	double				dir_x;
	double				dir_y;

	double				camera_plane_x;
	double				camera_plane_y;
	double				time;
	double				old_time;
	double				frame_time;

	double				move_speed;
	double				rot_speed;

	double				player_velocity_x;
	double				player_velocity_y;
	t_mlx	mlx;
}	t_game;

void	clear_image(t_game *game);
void	cleanup(t_mlx *mlx, unsigned int with_exit);

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

int		handle_keyboard(int keysym, t_game *game);

void	init_player_position(t_game *game);
void	init_player_direction(t_game *game);
void	draw_player(t_img *img, t_game *game);

void	init_project(t_mlx *mlx);
void	init_game(t_game *game);

void	render_frame_with_ray_casting(t_game *game);

int		get_cell_x_head_addr(int x);
int		get_cell_x_tail_addr(int x);
int		get_cell_y_head_addr(int y);
int		get_cell_y_tail_addr(int y);
int		get_cell_index(int position);

void	draw_line(t_game *game, int x0, int y0, int x1, int y1, int color);

// ray calculations
int	calc_step_direction(double ray_direction);
double	calc_total_ray_distance(double ray_direction, double ray_distance, double player_position, int current_tail);
double	calc_ray_distance(double ray_direction);
double	calc_ray_direction(double player_direction, double camera_plane, int x);

// wall calculations
void	calc_distance_to_wall(t_dda_data *dda_data, t_ray_trace_data *ray_trace_data);
void	calc_wall_color(t_dda_data *dda_data);
void	calc_wall_height(t_dda_data *dda_data);

// draw
void	draw_vertical_stripe(int x, t_ray_trace_data *ray_trace_data, t_dda_data *dda_data, t_game *game);

// init
void	initialize_dda_data(int x, t_dda_data *dda_data, t_game *game);
void	initialize_ray_trace_data(t_ray_trace_data *ray_trace_data, t_dda_data *dda_data, t_game *game);

#endif