/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:13:39 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/27 15:24:59 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	rotate_vector(
	double *direction_x,
	double *direction_y,
	double sin_angle,
	double cos_angle
)
{
	double	prev_direction_x;

	prev_direction_x = *direction_x;
	*direction_x = *direction_x * cos_angle - *direction_y * sin_angle;
	*direction_y = prev_direction_x * sin_angle + *direction_y * cos_angle;
}

void	rotate(
	double rotation_angle,
	t_game *game
)
{
	double	sin_angle;
	double	cos_angle;

	sin_angle = sin(rotation_angle);
	cos_angle = cos(rotation_angle);
	rotate_vector(&game->player_direction_x, &game->player_direction_y, sin_angle, cos_angle);
	rotate_vector(&game->plane_x, &game->plane_y, sin_angle, cos_angle);
}

void	mouse_rotate(
	double rotation_angle,
	t_game *game
)
{
	double	delta_mouse_move;

	delta_mouse_move = game->mouse.x - WINDOW_X_CENTER;
	rotation_angle = rotation_angle * delta_mouse_move * SENSITIVITY;
	rotate(rotation_angle, game);
	if (game->mouse.x != WINDOW_X_CENTER)
		mlx_mouse_move(
			game->mlx.ptr, game->mlx.win_ptr, WINDOW_X_CENTER, WINDOW_Y_CENTER);
}
