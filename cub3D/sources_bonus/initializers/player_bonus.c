/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:06:12 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/24 13:47:16 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state_bonus.h"

static void	initialize_player_size(t_player *player)
{
	player->size = (((double)(TILE_SIZE / 3.0) / (double)TILE_SIZE) / 2.0);
}

static void	initialize_player_position(t_player *player)
{
	player->position.x = (
			(int)player->map->spawn.x + (TILE_SIZE / TILE_SIZE / 2.0));
	player->position.y = (
			(int)player->map->spawn.y + (TILE_SIZE / TILE_SIZE / 2.0));
}

static void	initialize_player_direction(t_player *player)
{
	if (player->map->spawn_dir == 'N')
	{
		player->direction.x = 0.0;
		player->direction.y = -1.0;
	}
	else if (player->map->spawn_dir == 'S')
	{
		player->direction.x = 0.0;
		player->direction.y = 1.0;
	}
	else if (player->map->spawn_dir == 'W')
	{
		player->direction.x = -1.0;
		player->direction.y = 0.0;
	}
	else if (player->map->spawn_dir == 'E')
	{
		player->direction.x = 1.0;
		player->direction.y = 0.0;
	}
	player->plane.x = -player->direction.y * FOV;
	player->plane.y = player->direction.x * FOV;
}

void	initialize_player(t_player *player)
{
	initialize_player_size(player);
	initialize_player_position(player);
	initialize_player_direction(player);
}
