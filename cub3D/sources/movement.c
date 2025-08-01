/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:12:10 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/15 14:46:05 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

static void	move_horizontally(
	t_move_direction move_direction,
	double next_direction_x,
	double next_direction_y,
	t_game *game
)
{
	t_hitbox			hitbox;
	t_collision_tiles	collision_tiles;
	double				horizontal_offset;

	horizontal_offset = get_horizontal_offset(
			move_direction, next_direction_x, next_direction_y);
	hitbox.top_y = game->position_y - PLAYER_SIZE;
	hitbox.bottom_y = game->position_y + PLAYER_SIZE;
	hitbox.next_left_x = game->position_x - PLAYER_SIZE + horizontal_offset;
	hitbox.next_right_x = game->position_x + PLAYER_SIZE + horizontal_offset;
	collision_tiles.top_left = map[hitbox.top_y][hitbox.next_left_x];
	collision_tiles.top_right = map[hitbox.top_y][hitbox.next_right_x];
	collision_tiles.bottom_left = map[hitbox.bottom_y][hitbox.next_left_x];
	collision_tiles.bottom_right = map[hitbox.bottom_y][hitbox.next_right_x];
	if (collision_tiles.top_left != WALL
		&& collision_tiles.top_right != WALL
		&& collision_tiles.bottom_left != WALL
		&& collision_tiles.bottom_right != WALL
	)
	{
		game->position_x += horizontal_offset;
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

static void	move_vertically(
	t_move_direction move_direction,
	double next_direction_x,
	double next_direction_y,
	t_game *game
)
{
	t_hitbox			hitbox;
	t_collision_tiles	collision_tiles;
	double				vertical_offset;

	vertical_offset = get_vertical_offset(
			move_direction, next_direction_x, next_direction_y);
	hitbox.next_top_y = game->position_y - PLAYER_SIZE + vertical_offset;
	hitbox.next_bottom_y = game->position_y + PLAYER_SIZE + vertical_offset;
	hitbox.left_x = game->position_x - PLAYER_SIZE;
	hitbox.right_x = game->position_x + PLAYER_SIZE;
	collision_tiles.top_left = map[hitbox.next_top_y][hitbox.left_x];
	collision_tiles.top_right = map[hitbox.next_top_y][hitbox.right_x];
	collision_tiles.bottom_left = map[hitbox.next_bottom_y][hitbox.left_x];
	collision_tiles.bottom_right = map[hitbox.next_bottom_y][hitbox.right_x];
	if (collision_tiles.top_left != WALL
		&& collision_tiles.top_right != WALL
		&& collision_tiles.bottom_left != WALL
		&& collision_tiles.bottom_right != WALL
	)
	{
		game->position_y += vertical_offset;
	}
}

void	move(
	t_move_direction move_direction,
	t_game *game
)
{
	double	next_direction_x;
	double	next_direction_y;
	double	movement_speed;

	movement_speed = game->time_since_last_frame * MOVE_TILE_PER_SECOND;
	next_direction_x = game->direction_x * movement_speed;
	next_direction_y = game->direction_y * movement_speed;
	move_horizontally(move_direction, next_direction_x, next_direction_y, game);
	move_vertically(move_direction, next_direction_x, next_direction_y, game);
}
