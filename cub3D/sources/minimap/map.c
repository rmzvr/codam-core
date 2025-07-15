/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:55:10 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/15 17:04:37 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	set_start_tile(
	int *tile,
	double position
)
{
	*tile = position - MINIMAP_RADIUS;
	if (position - MINIMAP_RADIUS < 0.0)
		*tile -= 1;
}

static void	initialize_minimap_data(
	t_minimap *minimap,
	t_game *game
)
{
	minimap->window_tile_x = 0;
	minimap->window_tile_y = 0;
	set_start_tile(&minimap->map_tile_y, game->position_y);
	set_start_tile(&minimap->map_tile_x, game->position_x);
}

void	draw_map(
	t_game *game
)
{
	t_minimap	minimap;

	initialize_minimap_data(&minimap, game);
	while (minimap.map_tile_y < game->position_y + MINIMAP_RADIUS)
	{
		minimap.window_tile_x = 0;
		set_start_tile(&minimap.map_tile_x, game->position_x);
		while (minimap.map_tile_x < game->position_x + MINIMAP_RADIUS)
		{
			draw_tile(&minimap, game);
			minimap.map_tile_x += 1;
			minimap.window_tile_x += 1;
		}
		minimap.map_tile_y += 1;
		minimap.window_tile_y += 1;
	}
	draw_player(game);
	mlx_put_image_to_window(
		game->mlx.ptr, game->mlx.win_ptr, game->mlx.img.ptr, 0, 0);
}
