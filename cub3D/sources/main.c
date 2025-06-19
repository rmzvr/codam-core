/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:12:09 by rmzvr             #+#    #+#             */
/*   Updated: 2025/06/19 18:04:47 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double get_time(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec + tv.tv_usec / 1000000.0);
}

int	handle_controls(
	t_game *game
)
{
	if (game->move_forward == TRUE)
	{
		int	next_left_x;
		int	next_left_y;
		int	next_right_x;
		int	next_right_y;
		// int	next_tile_value1;
		// int	next_tile_value2;
		int	top_left_player_position_tile;
		(void)next_right_y;

		next_left_x = (int)(game->pos_x + (double)(PLAYER_SIZE / TILE_SIZE) + game->dir_x * game->movement_speed);
	
		next_left_y = (int)(game->pos_y + (double)(PLAYER_SIZE / TILE_SIZE) + game->dir_y * game->movement_speed);

		next_right_x = (int)(game->pos_x + ((double)(PLAYER_SIZE / TILE_SIZE) * 2) + game->dir_x * game->movement_speed);
		printf("next_left_x: %d, next_right_x: %d, \n", next_left_x, next_right_x);

		top_left_player_position_tile = map[next_left_y][next_left_x];

		// next_tile_value1 = map[next_left_y][next_left_x];
		// next_tile_value2 = map[next_left_y][next_left_x + 1];

		printf("current top-left corner of player pos_x: %d, pos_y: %d, \n", (int)game->pos_x, (int)game->pos_y);

		printf("next top_left_player_position_tile - x: %d, y: %d, value: %d\n", next_left_x, next_left_y, top_left_player_position_tile);

		// printf("current top-right corner of player pos_x: %f, pos_y: %f, \n", game->pos_x + (double)(PLAYER_SIZE / TILE_SIZE), game->pos_y + (double)(PLAYER_SIZE / TILE_SIZE));
		// printf("current pos_x: %d, pos_y: %d, \n", (int)game->pos_x, (int)game->pos_y);
		// printf("next pos_x: %d, pos_y: %d, value: %d\n", next_left_x, next_y, next_tile_value1);
		// printf("next pos_x: %d, pos_y: %d, \n", (int)(game->pos_x + (double)(PLAYER_SIZE / TILE_SIZE) + game->dir_x * game->movement_speed), );
		// if (next_tile_value1 == 1 || next_tile_value2 == 1)
		// {
		// 	printf("WORK\n");
		// 	return (1);
		// }

		game->pos_x += game->dir_x * game->movement_speed;
		game->pos_y += game->dir_y * game->movement_speed;
	}
	if (game->move_backward == TRUE)
	{
		game->pos_x -= game->dir_x * game->movement_speed;
		game->pos_y -= game->dir_y * game->movement_speed;
	}
	if (game->move_left == TRUE)
	{
		game->pos_x += game->dir_y * game->movement_speed;
		game->pos_y -= game->dir_x * game->movement_speed;
	}
	if (game->move_right == TRUE)
	{
		game->pos_x -= game->dir_y * game->movement_speed;
		game->pos_y += game->dir_x * game->movement_speed;
	}
	if (game->turn_left == TRUE)
	{
		game->dir_y = game->dir_x * sin(-game->rotation_speed) + game->dir_y * cos(-game->rotation_speed);
		game->dir_x = game->dir_x * cos(-game->rotation_speed) - game->dir_y * sin(-game->rotation_speed);
		game->camera_plane_y = game->camera_plane_x * sin(-game->rotation_speed) + game->camera_plane_y * cos(-game->rotation_speed);
		game->camera_plane_x = game->camera_plane_x * cos(-game->rotation_speed) - game->camera_plane_y * sin(-game->rotation_speed);
	}
	if (game->turn_right == TRUE)
	{
		game->dir_y = game->dir_x * sin(game->rotation_speed) + game->dir_y * cos(game->rotation_speed);
		game->dir_x = game->dir_x * cos(game->rotation_speed) - game->dir_y * sin(game->rotation_speed);
		game->camera_plane_y = game->camera_plane_x * sin(game->rotation_speed) + game->camera_plane_y * cos(game->rotation_speed);
		game->camera_plane_x = game->camera_plane_x * cos(game->rotation_speed) - game->camera_plane_y * sin(game->rotation_speed);
	}
	return (0);
}

int game_loop(
	t_game *game
)
{
	double current_time = get_time();
	double delta_time = (current_time - game->last_time);
	game->last_time = current_time;
	game->movement_speed = delta_time * MOVE_TILE_PER_SECOND;
	game->rotation_speed = delta_time * ROTATE_RADIAN_PER_SECOND;
	handle_controls(game);
	render_frame_with_ray_casting(game);
	draw_map(game);
	draw_player(game);
	init_draw_line(game);
	return (0);
}

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->move_forward = 1;
	if (keycode == XK_s)
		game->move_backward = 1;
	if (keycode == XK_a)
		game->move_left = 1;
	if (keycode == XK_d)
		game->move_right = 1;
	if (keycode == XK_Left)
		game->turn_left = 1;
	if (keycode == XK_Right)
		game->turn_right = 1;
	return (0);
}

int	handle_key_release(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->move_forward = 0;
	if (keycode == XK_s)
		game->move_backward = 0;
	if (keycode == XK_a)
		game->move_left = 0;
	if (keycode == XK_d)
		game->move_right = 0;
	if (keycode == XK_Left)
		game->turn_left = 0;
	if (keycode == XK_Right)
		game->turn_right = 0;
	return (0);
}

int	main(void)
{
	t_game	game;

	init_project(&game.mlx);
	init_game(&game);
	init_player(&game);
	mlx_hook(game.mlx.win_ptr, 2, (1L<<0), handle_key_press, &game);
	mlx_hook(game.mlx.win_ptr, 3, (1L<<1), handle_key_release, &game);
	mlx_loop_hook(game.mlx.ptr, game_loop, &game);
	mlx_loop(game.mlx.ptr);
}