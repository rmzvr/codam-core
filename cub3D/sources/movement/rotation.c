/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:13:39 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/22 17:50:50 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"
#include "movement.h"

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

void	keyboard_rotate(
	double rotation_angle,
	t_player *player
)
{
	double	sin_angle;
	double	cos_angle;

	sin_angle = sin(rotation_angle);
	cos_angle = cos(rotation_angle);
	rotate_vector(
		&player->direction.x,
		&player->direction.y,
		sin_angle,
		cos_angle
		);
	rotate_vector(
		&player->plane.x,
		&player->plane.y,
		sin_angle,
		cos_angle
		);
}

void	mouse_rotate(
	double rotation_angle,
	t_mouse *mouse,
	t_player *player,
	t_mlx *mlx
)
{
	double	delta_mouse_move;

	delta_mouse_move = mouse->x - WINDOW_WIDTH / 2;
	rotation_angle = rotation_angle * delta_mouse_move * (SENSITIVITY / 10.0);
	keyboard_rotate(rotation_angle, player);
	if (mouse->x != WINDOW_WIDTH / 2)
		mlx_mouse_move(
			mlx->ptr, mlx->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
}
