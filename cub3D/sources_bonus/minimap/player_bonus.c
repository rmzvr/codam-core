/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:11:12 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/24 13:47:38 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state_bonus.h"

static int	get_player_start_position(
	double position,
	double player_size
)
{
	int		minimap_offset;
	int		minimap_tile_size;
	double	position_fraction;
	double	player_start_position;

	minimap_offset = TILE_SIZE / 2;
	minimap_tile_size = TILE_SIZE / 2;
	position_fraction = position - floor(position);
	player_start_position = MINIMAP_RADIUS - player_size + position_fraction;
	return (player_start_position * minimap_tile_size + minimap_offset);
}

void	draw_player(
	double position_x,
	double position_y,
	t_player *player,
	t_image *img
)
{
	t_vec2	player_start;
	t_vec2	player_end;
	int		minimap_tile_size;

	minimap_tile_size = TILE_SIZE / 2;
	player_start.x = get_player_start_position(position_x, player->size);
	player_start.y = get_player_start_position(position_y, player->size);
	player_end.x = player_start.x + (player->size * 2 * minimap_tile_size);
	player_end.y = player_start.y + (player->size * 2 * minimap_tile_size);
	while (player_start.y < player_end.y)
	{
		player_start.x = get_player_start_position(position_x, player->size);
		while (player_start.x < player_end.x)
		{
			put_pixel(img, player_start.x, player_start.y, 0x000000);
			player_start.x++;
		}
		player_start.y++;
	}
}
