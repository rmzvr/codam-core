/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:12:09 by rmzvr             #+#    #+#             */
/*   Updated: 2025/06/24 21:06:26 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static double	get_time(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec + tv.tv_usec / 1000000.0);
}

int	handle_controls(
	t_game *game
)
{
	double	old_dir_x;
	double	old_plane_x;
	double	player_size = (double)PLAYER_SIZE / (double)TILE_SIZE;
	double	next_dir_x = game->dir_x * game->movement_speed;
	double	next_dir_y = game->dir_y * game->movement_speed;

	old_dir_x = 0.0;
	old_plane_x = 0.0;

	if (game->move_forward == TRUE)
	{
		double	top_left_x = game->pos_x + next_dir_x;
		double	top_left_y = game->pos_y + next_dir_y;

		double	bottom_left_y = game->pos_y + player_size + next_dir_y;

		double	top_right_x = game->pos_x + player_size + next_dir_x;
		double	top_right_y = game->pos_y + next_dir_y;

		double	bottom_right_y = game->pos_y + player_size + next_dir_y;

		if (map[(int)game->pos_y][(int)top_left_x] != 1
		&&  map[(int)(game->pos_y)][(int)top_right_x] != 1
		&&  map[(int)(game->pos_y + player_size)][(int)top_left_x] != 1
		&&  map[(int)(game->pos_y + player_size)][(int)top_right_x] != 1
		)
		{
			game->pos_x += next_dir_x;
		}

		if (map[(int)top_left_y][(int)game->pos_x] != 1
		&&  map[(int)top_right_y][(int)(game->pos_x + player_size)] != 1
		&&  map[(int)bottom_left_y][(int)(game->pos_x)] != 1
		&&  map[(int)bottom_right_y][(int)(game->pos_x + player_size)] != 1
		)
		{
			game->pos_y += next_dir_y;
		}
	}
	if (game->move_backward == TRUE)
	{
		double	top_left_x = game->pos_x - next_dir_x;
		double	top_left_y = game->pos_y - next_dir_y;

		double	bottom_left_y = game->pos_y + player_size - next_dir_y;

		double	top_right_x = game->pos_x + player_size - next_dir_x;
		double	top_right_y = game->pos_y - next_dir_y;

		double	bottom_right_y = game->pos_y + player_size - next_dir_y;

		if (map[(int)game->pos_y][(int)top_left_x] != 1
		&&  map[(int)(game->pos_y)][(int)top_right_x] != 1
		&&  map[(int)(game->pos_y + player_size)][(int)top_left_x] != 1
		&&  map[(int)(game->pos_y + player_size)][(int)top_right_x] != 1
		)
		{
			game->pos_x -= next_dir_x;
		}
		if (map[(int)top_left_y][(int)game->pos_x] != 1
		&&  map[(int)top_right_y][(int)(game->pos_x + player_size)] != 1
		&&  map[(int)bottom_left_y][(int)(game->pos_x)] != 1
		&&  map[(int)bottom_right_y][(int)(game->pos_x + player_size)] != 1
		)
		{
			game->pos_y -= next_dir_y;
		}
	}
	if (game->move_left == TRUE)
	{
		double	top_left_x = game->pos_x + next_dir_y;
		double	top_left_y = game->pos_y - next_dir_x;

		double	bottom_left_y = game->pos_y + player_size - next_dir_x;

		double	top_right_x = game->pos_x + player_size + next_dir_y;
		double	top_right_y = game->pos_y - next_dir_x;

		double	bottom_right_y = game->pos_y + player_size - next_dir_x;

		if (map[(int)game->pos_y][(int)top_left_x] != 1
		&&  map[(int)(game->pos_y)][(int)top_right_x] != 1
		&&  map[(int)(game->pos_y + player_size)][(int)top_left_x] != 1
		&&  map[(int)(game->pos_y + player_size)][(int)top_right_x] != 1
		)
		{
			game->pos_x += next_dir_y;
		}
		if (map[(int)top_left_y][(int)game->pos_x] != 1
		&&  map[(int)top_right_y][(int)(game->pos_x + player_size)] != 1
		&&  map[(int)bottom_left_y][(int)(game->pos_x)] != 1
		&&  map[(int)bottom_right_y][(int)(game->pos_x + player_size)] != 1
		)
		{
			game->pos_y -= next_dir_x;
		}
	}
	if (game->move_right == TRUE)
	{
		double	top_left_x = game->pos_x - next_dir_y;
		double	top_left_y = game->pos_y + next_dir_x;

		double	bottom_left_y = game->pos_y + player_size + next_dir_x;

		double	top_right_x = game->pos_x + player_size - next_dir_y;
		double	top_right_y = game->pos_y + next_dir_x;

		double	bottom_right_y = game->pos_y + player_size + next_dir_x;

		if (map[(int)game->pos_y][(int)top_left_x] != 1
		&&  map[(int)(game->pos_y)][(int)top_right_x] != 1
		&&  map[(int)(game->pos_y + player_size)][(int)top_left_x] != 1
		&&  map[(int)(game->pos_y + player_size)][(int)top_right_x] != 1
		)
		{
			game->pos_x -= next_dir_y;
		}
		if (map[(int)top_left_y][(int)game->pos_x] != 1
		&&  map[(int)top_right_y][(int)(game->pos_x + player_size)] != 1
		&&  map[(int)bottom_left_y][(int)(game->pos_x)] != 1
		&&  map[(int)bottom_right_y][(int)(game->pos_x + player_size)] != 1
		)
		{
			game->pos_y += next_dir_x;
		}
	}
	if (game->turn_left == TRUE)
	{
		old_dir_x = game->dir_x;
		game->dir_x = game->dir_x * cos(-game->rotation_speed) - game->dir_y * sin(-game->rotation_speed);
		game->dir_y = old_dir_x * sin(-game->rotation_speed) + game->dir_y * cos(-game->rotation_speed);
		old_plane_x = game->camera_plane_x;
		game->camera_plane_x = game->camera_plane_x * cos(-game->rotation_speed) - game->camera_plane_y * sin(-game->rotation_speed);
		game->camera_plane_y = old_plane_x * sin(-game->rotation_speed) + game->camera_plane_y * cos(-game->rotation_speed);
	}
	if (game->turn_right == TRUE)
	{
		old_dir_x = game->dir_x;
		game->dir_x = game->dir_x * cos(game->rotation_speed) - game->dir_y * sin(game->rotation_speed);
		game->dir_y = old_dir_x * sin(game->rotation_speed) + game->dir_y * cos(game->rotation_speed);
		old_plane_x = game->camera_plane_x;
		game->camera_plane_x = game->camera_plane_x * cos(game->rotation_speed) - game->camera_plane_y * sin(game->rotation_speed);
		game->camera_plane_y = old_plane_x * sin(game->rotation_speed) + game->camera_plane_y * cos(game->rotation_speed);
	}
	return (0);
}

int	game_loop(
	t_game *game
)
{
	double	current_time;
	double	delta_time;

	current_time = get_time();
	delta_time = (current_time - game->last_time);
	game->last_time = current_time;
	game->movement_speed = delta_time * MOVE_TILE_PER_SECOND;
	game->rotation_speed = delta_time * ROTATE_RADIAN_PER_SECOND;
	// printf("FPS: %d\n", (int)(1.0 / delta_time));
	// printf("\e[1;1H\e[2J");
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
	// printf("dir_x: %f, dir_y: %f\n", game.dir_x, game.dir_y);
	mlx_hook(game.mlx.win_ptr, 2, (1L<<0), handle_key_press, &game);
	mlx_hook(game.mlx.win_ptr, 3, (1L<<1), handle_key_release, &game);
	mlx_loop_hook(game.mlx.ptr, game_loop, &game);
	mlx_loop(game.mlx.ptr);
}