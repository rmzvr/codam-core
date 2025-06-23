/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:06:23 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/23 21:45:31 by rmzvr            ###   ########.fr       */
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

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define MAP_WIDTH 25
# define MAP_HEIGHT 25
# define TILE_SIZE 30
# define PLAYER_SIZE 10
# define STEP_SIZE (TILE_SIZE / 3)
# define WINDOW_WIDTH (MAP_WIDTH * TILE_SIZE)
# define WINDOW_HEIGHT (MAP_HEIGHT * TILE_SIZE)
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

typedef enum e_hit_side
{
	VERTICAL,
	HORIZONTAL,
}	t_hit_side;

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
	t_hit_side	hit_side;

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

extern char	map[MAP_HEIGHT][MAP_WIDTH];

typedef enum e_element
{
	FLOOR,
	WALL,
}	t_element;

typedef enum e_direction
{
	TOP,
	RIGHT,
	BOTTOM,
	LEFT,
}	t_direction;

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

typedef struct s_game
{
	double				vector_x_start;
	double				vector_y_start;

	int					vector_x_end;
	int					vector_y_end;

	double				pos_x;
	double				pos_y;

	double				dir_x;
	double				dir_y;

	double				camera_plane_x;
	double				camera_plane_y;

	int					move_forward;
	int					move_backward;
	int					move_left;
	int					move_right;
	int					turn_left;
	int					turn_right;
	double				last_time;

	double				movement_speed;
	double				rotation_speed;

	t_texture			front_wall;
	t_texture			back_wall;
	t_texture			left_wall;
	t_texture			right_wall;
	t_texture			*texture_data;
	t_mlx				mlx;
}	t_game;

void	clear_image(t_game *game);
void	cleanup(t_mlx *mlx, unsigned int with_exit);

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

void	init_player(t_game *game);
void	draw_player(t_game *game);
void	draw_map(t_game *game);

void	init_project(t_mlx *mlx);
void	init_game(t_game *game);

void	render_frame_with_ray_casting(t_game *game);

int		get_cell_x_head_addr(int x);
int		get_cell_x_tile_addr(int x);
int		get_cell_y_head_addr(int y);
int		get_cell_y_tile_addr(int y);
int		get_cell_index(int position);

void	init_draw_line(t_game *game);
void	draw_line(t_game *game, int x0, int y0, int x1, int y1, int color);

// ray calculations
int		calc_step_direction(double ray_direction);
double	calc_total_ray_distance(double ray_direction, double ray_distance, double player_position, int current_tile);
double	calc_ray_distance(double ray_direction);
double	calc_ray_direction(double player_direction, double camera_plane, int x);

// wall calculations
void	calc_distance_to_wall(t_ray *ray);
void	calc_wall_color(t_hit_side hit_side, int step_direction_x, int step_direction_y, t_wall *wall);
void	calc_wall_height(t_wall *wall, double length_to_wall);

// draw
void	draw_vertical_stripe(int x, t_ray *ray, t_wall *wall, t_game *game, t_texture *texture_data);

// init
void	initialize_wall(t_wall *wall);
void	initialize_ray(int x, t_ray *ray, t_game *game);

#endif