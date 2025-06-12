/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:06:23 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/12 17:16:02 by rzvir            ###   ########.fr       */
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

# define MAP_WIDTH 25
# define MAP_HEIGHT 25

# define WINDOW_WIDTH (MAP_WIDTH * TAIL_SIZE)
# define WINDOW_HEIGHT (MAP_HEIGHT * TAIL_SIZE)

# define WINDOW_MIN_X 0
# define WINDOW_MAX_X (WINDOW_WIDTH - 1)

# define WINDOW_MIN_Y 0
# define WINDOW_MAX_Y (WINDOW_HEIGHT - 1)

# define TAIL_SIZE 30
# define PLAYER_SIZE 10
# define STEP_SIZE (TAIL_SIZE / 6)


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

	double				player_position_x_double;
	double				player_position_y_double;

	int					player_position_x_int_rounded;
	int					player_position_y_int_rounded;

	int					player_position_x_px;
	int					player_position_y_px;

	double				dir_x;
	double				dir_y;

	double				plane_x;
	double				plane_y;
	double				time;
	double				old_time;
	double				frame_time;

	double				move_speed;
	double				rot_speed;

	double				player_velocity_x;
	double				player_velocity_y;

	double				delta_vector_x;
	double				delta_vector_y;

	double				unit_delta_vector_x;
	double				unit_delta_vector_y;

	
	t_mlx	mlx;
}	t_game;

#endif