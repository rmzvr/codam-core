/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:06:23 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/12 11:57:28 by rmzvr            ###   ########.fr       */
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

	double				plane_x;
	double				plane_y;
	double				time;
	double				old_time;
	double				frame_time;

	double				move_speed;
	double				rot_speed;

	double				player_velocity_x;
	double				player_velocity_y;
	t_mlx	mlx;
}	t_game;

#endif