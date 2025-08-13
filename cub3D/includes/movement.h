/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:12:35 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/24 13:18:52 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H

typedef enum e_move_direction
{
	M_FORWARD,
	M_BACKWARD,
	M_LEFT,
	M_RIGHT,
}	t_move_direction;

typedef struct s_mouse
{
	int	x;
	int	y;
}	t_mouse;

typedef enum e_tile_type
{
	FLOOR = '0',
	WALL = '1',
	SPACE = ' '
}	t_tile_type;

typedef struct s_collision_tiles
{
	t_tile_type	top_left;
	t_tile_type	top_right;
	t_tile_type	bottom_left;
	t_tile_type	bottom_right;
}	t_collision_tiles;

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

typedef struct s_move
{
	int	forward;
	int	backward;
	int	left;
	int	right;
}	t_move;

typedef struct s_rotate
{
	int	left;
	int	right;
}	t_rotate;

void	move(
			t_move_direction move_direction,
			double time_since_last_frame,
			t_player *player
			);

void	keyboard_rotate(
			double rotation_angle,
			t_player *player
			);

void	mouse_rotate(
			double rotation_angle,
			t_mouse *mouse,
			t_player *player,
			t_mlx *mlx
			);

int		handle_movement(
			double time_since_last_frame,
			t_player *player,
			t_move *movement,
			t_mlx *mlx
			);

int		handle_rotation(
			double time_since_last_frame,
			t_player *player,
			t_rotate *rotate,
			t_mlx *mlx
			);

#endif