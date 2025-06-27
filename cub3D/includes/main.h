/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:06:23 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/27 15:24:59 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <X11/keysym.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define PROGRAM_NAME "cub3D"
# define MAP_WIDTH 25
# define MAP_HEIGHT 25
# define TILE_SIZE 30
# define MINIMAP_TILE_SIZE (TILE_SIZE / 3)
# define MINIMAP_OFFSET 10
# define SENSITIVITY 0.1
# define PLAYER_SIZE (((double)10 / (double)TILE_SIZE) / 2.0)
# define WINDOW_WIDTH (MAP_WIDTH * TILE_SIZE)
# define WINDOW_HEIGHT (MAP_HEIGHT * TILE_SIZE)
# define WINDOW_X_CENTER (WINDOW_WIDTH / 2)
# define WINDOW_Y_CENTER (WINDOW_HEIGHT / 2)
# define MIN_WINDOW_X 0
# define MAX_WINDOW_X (WINDOW_WIDTH - 1)
# define MIN_WINDOW_Y 0
# define MAX_WINDOW_Y (WINDOW_HEIGHT - 1)
# define CAMERA_PLANE_X 0.0
# define CAMERA_PLANE_Y 0.66
# define MOVE_TILE_PER_SECOND 3.0
# define ROTATE_RADIAN_PER_SECOND 3.0

typedef enum s_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef enum e_side
{
	VERTICAL,
	HORIZONTAL,
}	t_side;

extern char	map[MAP_HEIGHT][MAP_WIDTH];

typedef enum e_tile_type
{
	FLOOR,
	WALL,
}	t_tile_type;

typedef enum e_move_direction
{
	M_FORWARD,
	M_BACKWARD,
	M_LEFT,
	M_RIGHT,
}	t_move_direction;

typedef enum e_rotate_direction
{
	R_LEFT,
	R_RIGHT,
}	t_rotate_direction;

typedef struct s_wall
{
	int		start;
	int		end;
	int		color;
	int		height;
}	t_wall;

typedef struct s_ray
{
	t_bool		hit;
	t_side	hit_side;

	int			current_tile_x;
	int			current_tile_y;

	double		direction_x;
	double		direction_y;

	int			step_direction_x;
	int			step_direction_y;

	double		current_length_x;
	double		current_length_y;

	double		total_length_x;
	double		total_length_y;

	double		length_to_wall;
}	t_ray;

typedef struct s_hitbox
{
	int	left_x;
	int	right_x;
	int	top_y;
	int	bottom_y;
	int	next_left_x;
	int	next_right_x;
	int	next_top_y;
	int	next_bottom_y;
}	t_hitbox;

typedef struct s_collision_tiles
{
	t_tile_type	top_left;
	t_tile_type	top_right;
	t_tile_type	bottom_left;
	t_tile_type	bottom_right;
}	t_collision_tiles;

typedef struct s_img
{
	void	*ptr;
	char	*pixels_addr;
	int		bytes_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_xpm
{
	char	*path;
	int		width;
	int		height;
}	t_xpm;

typedef struct s_texture
{
	t_xpm	xpm;
	t_img	img;
}	t_texture;

typedef struct s_mlx
{
	void	*ptr;
	void	*win_ptr;
	t_img	img;
}	t_mlx;

typedef struct s_mouse
{
	int	x;
	int	y;
}	t_mouse;

typedef struct s_game
{
	double				players_position_x;
	double				players_position_y;

	double				player_direction_x;
	double				player_direction_y;

	double				plane_x;
	double				plane_y;

	int					move_forward;
	int					move_backward;
	int					move_left;
	int					move_right;
	int					rotate_left;
	int					rotate_right;

	double				previous_time;
	double				time_since_last_frame;

	t_mouse				mouse;

	t_texture			front_wall;
	t_texture			back_wall;
	t_texture			left_wall;
	t_texture			right_wall;
	t_texture			*texture_data;
	t_mlx				mlx;
}	t_game;

void	clear_image(t_game *game);
void	cleanup(t_mlx *mlx, unsigned int with_exit);

void	my_mlx_pixel_put(t_img *datvector_x_enda, int x, int y, int color);

void	init_player(t_game *game);
void	draw_player(t_game *game);
void	draw_map(t_game *game);

void	init_project(t_mlx *mlx);
void	init_game(t_game *game);

void	render_frame(t_game *game);

void	init_draw_line(t_game *game);
void	draw_line(t_game *game, int x0, int y0, int x1, int y1, int color);

// ray calculations
int		calc_step_direction(double ray_direction);
double	calc_total_ray_distance(double ray_direction, double ray_distance, double player_position, int current_tile);
double	calc_ray_distance(double ray_direction);
double	calc_ray_direction(double player_direction, double camera_plane, int x);

// wall calculations
void	calc_distance_to_wall(t_ray *ray);
void	calc_wall_color(t_side hit_side, int step_direction_x, int step_direction_y, t_wall *wall);
void	calc_wall_height(t_wall *wall, double length_to_wall);

// draw
void	draw_vertical_stripe(int x, t_ray *ray, t_wall *wall, t_game *game, t_texture *texture_data);

// init
void	initialize_wall(t_wall *wall);
void	initialize_ray(int x, t_ray *ray, t_game *game);

void	move(t_move_direction move_direction, t_game *game);

void	rotate(double rotation_angle, t_game *game);

int		handle_movement(t_game *game);
int		handle_key_press(int keycode, t_game *game);
int		handle_key_release(int keycode, t_game *game);

void	swap_int(int *a, int *b);
void	swap_double(double *a, double *b);

void	set_time_since_last_frame(double *time_since_last_frame);

void	mouse_rotate(double rotation_angle, t_game *game);

#endif