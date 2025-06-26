/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:29:00 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/26 18:36:45 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	handle_movement(t_game *game)
{
	if (game->move_forward == TRUE)
		move(M_FORWARD, game);
	if (game->move_backward == TRUE)
		move(M_BACKWARD, game);
	if (game->move_left == TRUE)
		move(M_LEFT, game);
	if (game->move_right == TRUE)
		move(M_RIGHT, game);
	if (game->rotate_left == TRUE)
		rotate(R_LEFT, game);
	if (game->rotate_right == TRUE)
		rotate(R_RIGHT, game);
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

double normalize_pixel_to_unit_range(int pixel, int max_range)
{
	return (pixel - (max_range / 2.0)) / (max_range / 2.0);
}

// static void	rotate_vector(
// 	double *direction_x,
// 	double *direction_y,
// 	double sin_angle,
// 	double cos_angle
// )
// {
// 	double	prev_direction_x;

// 	prev_direction_x = *direction_x;
// 	*direction_x = *direction_x * cos_angle - *direction_y * sin_angle;
// 	*direction_y = prev_direction_x * sin_angle + *direction_y * cos_angle;
// }

int	handle_mouse_movement(int x, int y, t_game *game)
{

	(void) y;
	(void) game;
	double	normalized_mouse_x;
	double	normalized_mouse_y;

	mlx_mouse_hide(game->mlx.ptr,game->mlx.win_ptr);
	normalized_mouse_x = normalize_pixel_to_unit_range(x, WINDOW_WIDTH);
	normalized_mouse_y = normalize_pixel_to_unit_range(y, WINDOW_HEIGHT);
	if (normalized_mouse_y < 0)
		normalized_mouse_y = floor(normalized_mouse_y);
	else
		normalized_mouse_y = ceil(normalized_mouse_y);
	double	delta_x;
	double	curr_x;
	double	sin_angle;
	double	cos_angle;
	curr_x = normalize_pixel_to_unit_range(x, WINDOW_WIDTH);
	delta_x = curr_x - game->prev_x;
	game->prev_x = curr_x;
	sin_angle = sin(delta_x * M_PI);
	cos_angle = cos(delta_x * M_PI);
	double	prev_direction_x;
	double	prev_direction_y;

	prev_direction_x = game->dir_x;
	prev_direction_y = game->plane_x;
	game->dir_x = game->dir_x * cos_angle - game->dir_y * sin_angle;
	game->dir_y = prev_direction_x * sin_angle + game->dir_y * cos_angle;
	game->plane_x = game->plane_x * cos_angle - game->plane_y * sin_angle;
	game->plane_y = prev_direction_y * sin_angle + game->plane_y * cos_angle;
	return (0);
}
