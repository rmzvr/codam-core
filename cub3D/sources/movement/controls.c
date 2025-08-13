/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:29:00 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/23 16:55:41 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"
#include "movement.h"

static void	set_mouse_position(
	t_mouse *mouse,
	t_mlx *mlx
)
{
	mlx_mouse_get_pos(mlx->ptr, mlx->win_ptr, &mouse->x, &mouse->y);
}

static t_bool	is_mouse_moving(
	t_mouse mouse
)
{
	double	delta_mouse_move;

	delta_mouse_move = mouse.x - WINDOW_WIDTH / 2;
	if (delta_mouse_move == 0)
	{
		return (FALSE);
	}
	return (TRUE);
}

int	handle_rotation(
	double time_since_last_frame,
	t_player *player,
	t_rotate *rotate,
	t_mlx *mlx
)
{
	double	rotation_angle;
	t_mouse	mouse;

	rotation_angle = time_since_last_frame * ROTATE_RADIAN_PER_SECOND;
	if (!mlx->is_focused)
	{
		mlx_mouse_show(mlx->ptr, mlx->win_ptr);
		return (0);
	}
	mlx_mouse_hide(mlx->ptr, mlx->win_ptr);
	set_mouse_position(&mouse, mlx);
	if (rotate->left == TRUE)
		keyboard_rotate(-rotation_angle, player);
	if (rotate->right == TRUE)
		keyboard_rotate(rotation_angle, player);
	if (is_mouse_moving(mouse) == TRUE)
		mouse_rotate(rotation_angle, &mouse, player, mlx);
	return (0);
}

int	handle_movement(
	double time_since_last_frame,
	t_player *player,
	t_move *movement,
	t_mlx *mlx
)
{
	double	movement_speed;

	movement_speed = time_since_last_frame * MOVE_TILE_PER_SECOND;
	if (!mlx->is_focused)
		return (0);
	if (movement->forward == TRUE)
		move(M_FORWARD, movement_speed, player);
	if (movement->backward == TRUE)
		move(M_BACKWARD, movement_speed, player);
	if (movement->left == TRUE)
		move(M_LEFT, movement_speed, player);
	if (movement->right == TRUE)
		move(M_RIGHT, movement_speed, player);
	return (0);
}
