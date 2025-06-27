/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:29:00 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/27 00:06:14 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	handle_mouse_rotation(t_game *game)
{
	int		x;
	int		y;
	double	rotation_angle;
	double	delta_mouse_move;

	rotation_angle = game->time_since_last_frame * ROTATE_RADIAN_PER_SECOND;

	mlx_mouse_hide(game->mlx.ptr, game->mlx.win_ptr);
	mlx_mouse_get_pos(game->mlx.ptr, game->mlx.win_ptr, &x, &y);

	delta_mouse_move = x - WINDOW_X_CENTER;

	if (delta_mouse_move != 0)
		rotation_angle = rotation_angle * delta_mouse_move;

	if (delta_mouse_move != 0)
		rotate(rotation_angle, game);

	if (x != WINDOW_X_CENTER)
		mlx_mouse_move(game->mlx.ptr,game->mlx.win_ptr, WINDOW_X_CENTER, WINDOW_Y_CENTER);
}

int	handle_movement(t_game *game)
{

	double	rotation_angle;

	rotation_angle = game->time_since_last_frame * ROTATE_RADIAN_PER_SECOND;

	if (game->move_forward == TRUE)
		move(M_FORWARD, game);
	if (game->move_backward == TRUE)
		move(M_BACKWARD, game);
	if (game->move_left == TRUE)
		move(M_LEFT, game);
	if (game->move_right == TRUE)
		move(M_RIGHT, game);
	if (game->rotate_left == TRUE)
		rotate(-rotation_angle, game);
	if (game->rotate_right == TRUE)
		rotate(rotation_angle, game);
	handle_mouse_rotation(game);
	return (0);
}
int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->move_forward = TRUE;
	if (keycode == XK_s)
		game->move_backward = TRUE;
	if (keycode == XK_a)
		game->move_left = TRUE;
	if (keycode == XK_d)
		game->move_right = TRUE;
	if (keycode == XK_Left)
		game->rotate_left = TRUE;
	if (keycode == XK_Right)
		game->rotate_right = TRUE;
	return (0);
}

int	handle_key_release(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->move_forward = FALSE;
	if (keycode == XK_s)
		game->move_backward = FALSE;
	if (keycode == XK_a)
		game->move_left = FALSE;
	if (keycode == XK_d)
		game->move_right = FALSE;
	if (keycode == XK_Left)
		game->rotate_left = FALSE;
	if (keycode == XK_Right)
		game->rotate_right = FALSE;
	return (0);
}
