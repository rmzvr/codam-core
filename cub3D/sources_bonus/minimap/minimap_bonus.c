/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:55:10 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/24 13:47:36 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state_bonus.h"
#include "minimap_bonus.h"

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
	double position_x,
	double position_y,
	t_minimap *minimap
)
{
	minimap->window_tile_x = 0;
	minimap->window_tile_y = 0;
	set_start_tile(&minimap->map_tile_y, position_y);
	set_start_tile(&minimap->map_tile_x, position_x);
}

void	draw_minimap(
	double position_x,
	double position_y,
	t_mlx *mlx,
	t_player *player
)
{
	t_minimap	minimap;

	initialize_minimap_data(position_x, position_y, &minimap);
	while (minimap.map_tile_y < position_y + MINIMAP_RADIUS)
	{
		minimap.window_tile_x = 0;
		set_start_tile(&minimap.map_tile_x, position_x);
		while (minimap.map_tile_x < position_x + MINIMAP_RADIUS)
		{
			draw_tile(&minimap, &mlx->img, player);
			minimap.map_tile_x += 1;
			minimap.window_tile_x += 1;
		}
		minimap.map_tile_y += 1;
		minimap.window_tile_y += 1;
	}
	draw_player(position_x, position_y, player, &mlx->img);
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
}
