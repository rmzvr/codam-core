/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:06:59 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/16 17:53:04 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	handle_keyboard(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		cleanup(&game->mlx, 1);
	}
	else if (keysym == XK_w)
	{
		int	x = game->pos_x + game->dir_x * STEP_SIZE / 10;
		int	y = game->pos_y + game->dir_y * STEP_SIZE / 10;
		if (map[y][x] != 0 && map[y][x] != 69)
			return (0);
		game->pos_x += game->dir_x * STEP_SIZE / 10;
		game->pos_y += game->dir_y * STEP_SIZE / 10;
	}
	else if (keysym == XK_s)
	{
		int	x = game->pos_x - game->dir_x * STEP_SIZE / 10;
		int	y = game->pos_y - game->dir_y * STEP_SIZE / 10;
		if (map[y][x] != 0 && map[y][x] != 69)
			return (0);
		game->pos_x -= game->dir_x * STEP_SIZE / 10;
		game->pos_y -= game->dir_y * STEP_SIZE / 10;
	}
	else if (keysym == XK_a)
	{
		int	x = game->pos_x + game->dir_y * STEP_SIZE / 10;
		int	y = game->pos_y - game->dir_x * STEP_SIZE / 10;
		if (map[y][x] != 0 && map[y][x] != 69)
			return (0);
		game->pos_x += game->dir_y * STEP_SIZE / 10;
		game->pos_y -= game->dir_x * STEP_SIZE / 10;
	}
	else if (keysym == XK_d)
	{
		int	x = game->pos_x - game->dir_y * STEP_SIZE / 10;
		int	y = game->pos_y + game->dir_x * STEP_SIZE / 10;
		if (map[y][x] != 0 && map[y][x] != 69)
			return (0);
		game->pos_x -= game->dir_y * STEP_SIZE / 10;
		game->pos_y += game->dir_x * STEP_SIZE / 10;
	}
	else if (keysym == XK_Left)
	{
		double oldDirX = game->dir_x;
		game->dir_x = game->dir_x * cos(-M_PI / 6) - game->dir_y * sin(-M_PI / 6);
		game->dir_y = oldDirX * sin(-M_PI / 6) + game->dir_y * cos(-M_PI / 6);
		double oldPlaneX = game->camera_plane_x;
		game->camera_plane_x = game->camera_plane_x * cos(-M_PI / 6) - game->camera_plane_y * sin(-M_PI / 6);
		game->camera_plane_y = oldPlaneX * sin(-M_PI / 6) + game->camera_plane_y * cos(-M_PI / 6);
	}
	else if (keysym == XK_Right)
	{
		double oldDirX = game->dir_x;
		game->dir_x = game->dir_x * cos(M_PI / 6) - game->dir_y * sin(M_PI / 6);
		game->dir_y = oldDirX * sin(M_PI / 6) + game->dir_y * cos(M_PI / 6);
		double oldPlaneX = game->camera_plane_x;
		game->camera_plane_x = game->camera_plane_x * cos(M_PI / 6) - game->camera_plane_y * sin(M_PI / 6);
		game->camera_plane_y = oldPlaneX * sin(M_PI / 6) + game->camera_plane_y * cos(M_PI / 6);
	}
	clear_image(game);
	render_frame_with_ray_casting(game);
	// draw_map(game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr, game->mlx.img.ptr, 0, 0);
	return (0);
}
