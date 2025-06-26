/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:13:39 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/26 15:37:43 by rzvir            ###   ########.fr       */
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
	t_rotate_direction rotate_direction,
	t_game *game
)
{
	double	sin_angle;
	double	cos_angle;
	double	rotation_angle;

	rotation_angle = game->rotation_speed;
	if (rotate_direction == R_LEFT)
		rotation_angle = game->rotation_speed * -1;
	sin_angle = sin(rotation_angle);
	cos_angle = cos(rotation_angle);
	rotate_vector(&game->dir_x, &game->dir_y, sin_angle, cos_angle);
	rotate_vector(&game->plane_x, &game->plane_y, sin_angle, cos_angle);
}
