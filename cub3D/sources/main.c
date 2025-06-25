/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:12:09 by rmzvr             #+#    #+#             */
/*   Updated: 2025/06/25 20:38:57 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static double	get_time(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec + tv.tv_usec / 1000000.0);
}

static double	get_horizontal_offset(
	t_move_direction move_direction,
	double move_delta_x,
	double move_delta_y
)
{
	double	movement_offset;
	double	adjusted_x;
	double	adjusted_y;

	adjusted_x = move_delta_x;
	if (move_direction == M_BACKWARD)
		adjusted_x = move_delta_x * -1;

	adjusted_y = move_delta_y;
	if (move_direction == M_RIGHT)
		adjusted_y = move_delta_y * -1;

	if (move_direction == M_FORWARD || move_direction == M_BACKWARD)
		movement_offset = adjusted_x;
	else
		movement_offset = adjusted_y;
	return (movement_offset);
}

void	move_horizontally(
	t_move_direction move_direction,
	double next_dir_x,
	double next_dir_y,
	t_game *game
)
{
	double		horizontal_offset;

	int			top_side_y;
	int			bottom_side_y;

	int			next_left_side_x;
	int			next_right_side_x;

	t_element	tile_top_left;
	t_element	tile_top_right;
	t_element	tile_bottom_left;
	t_element	tile_bottom_right;

	horizontal_offset = get_horizontal_offset(move_direction, next_dir_x, next_dir_y);

	top_side_y = game->pos_y - PLAYER_SIZE;
	bottom_side_y = game->pos_y + PLAYER_SIZE;

	next_left_side_x = game->pos_x - PLAYER_SIZE + horizontal_offset;
	next_right_side_x = game->pos_x + PLAYER_SIZE + horizontal_offset;

	tile_top_left = map[top_side_y][next_left_side_x];
	tile_top_right = map[top_side_y][next_right_side_x];
	tile_bottom_left = map[bottom_side_y][next_left_side_x];
	tile_bottom_right = map[bottom_side_y][next_right_side_x];

	if (tile_top_left != WALL && tile_top_right != WALL
		&& tile_bottom_left != WALL && tile_bottom_right != WALL)
	{
		game->pos_x += horizontal_offset;
	}
}

static double	get_vertical_offset(
	t_move_direction move_direction,
	double move_delta_x,
	double move_delta_y
)
{
	double	movement_offset;
	double	adjusted_x;
	double	adjusted_y;

	adjusted_x = move_delta_x;
	if (move_direction == M_LEFT)
		adjusted_x = move_delta_x * -1;

	adjusted_y = move_delta_y;
	if (move_direction == M_BACKWARD)
		adjusted_y = move_delta_y * -1;

	if (move_direction == M_FORWARD || move_direction == M_BACKWARD)
		movement_offset = adjusted_y;
	else
		movement_offset = adjusted_x;
	return (movement_offset);
}

void	move_vertically(
	t_move_direction move_direction,
	double next_dir_x,
	double next_dir_y,
	t_game *game
)
{
	double		vertical_offset;

	int			next_top_side_y = 0;
	int			next_bottom_side_y = 0;

	int			left_side_x;
	int			right_side_x;

	t_element	tile_top_left;
	t_element	tile_top_right;
	t_element	tile_bottom_left;
	t_element	tile_bottom_right;

	vertical_offset = get_vertical_offset(move_direction, next_dir_x, next_dir_y);

	next_top_side_y = game->pos_y - PLAYER_SIZE + vertical_offset;
	next_bottom_side_y = game->pos_y + PLAYER_SIZE + vertical_offset;

	left_side_x = game->pos_x - PLAYER_SIZE;
	right_side_x = game->pos_x + PLAYER_SIZE;

	tile_top_left = map[next_top_side_y][left_side_x];
	tile_top_right = map[next_top_side_y][right_side_x];
	tile_bottom_left = map[next_bottom_side_y][left_side_x];
	tile_bottom_right = map[next_bottom_side_y][right_side_x];

	if (tile_top_left != WALL && tile_top_right != WALL
		&& tile_bottom_left != WALL && tile_bottom_right != WALL)
	{
		game->pos_y += vertical_offset;
	}
}

void	move(
	t_move_direction move_direction,
	t_game *game
)
{
	double	next_dir_x;
	double	next_dir_y;

	next_dir_x = game->dir_x * game->movement_speed;
	next_dir_y = game->dir_y * game->movement_speed;
	move_horizontally(move_direction, next_dir_x, next_dir_y, game);
	move_vertically(move_direction, next_dir_x, next_dir_y, game);
}

void	rotate(
	t_rotate_direction rotate_direction,
	t_game *game
)
{
	double	prev_direction_x;
	double	prev_direction_y;
	double	adjusted_rotation_direction;

	adjusted_rotation_direction = game->rotation_speed;
	if (rotate_direction == R_LEFT)
		adjusted_rotation_direction = game->rotation_speed * -1;

	prev_direction_x = game->dir_x;
	game->dir_x = game->dir_x * cos(adjusted_rotation_direction) - game->dir_y * sin(adjusted_rotation_direction);
	game->dir_y = prev_direction_x * sin(adjusted_rotation_direction) + game->dir_y * cos(adjusted_rotation_direction);
	prev_direction_y = game->camera_plane_x;
	game->camera_plane_x = game->camera_plane_x * cos(adjusted_rotation_direction) - game->camera_plane_y * sin(adjusted_rotation_direction);
	game->camera_plane_y = prev_direction_y * sin(adjusted_rotation_direction) + game->camera_plane_y * cos(adjusted_rotation_direction);
}

int	handle_controls(
	t_game *game
)
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
		game->rotate_left = 1;
	if (keycode == XK_Right)
		game->rotate_right = 1;
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
		game->rotate_left = 0;
	if (keycode == XK_Right)
		game->rotate_right = 0;
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