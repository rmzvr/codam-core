/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:38:21 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/24 13:40:59 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

typedef struct s_minimap
{
	int	map_tile_x;
	int	map_tile_y;
	int	window_tile_x;
	int	window_tile_y;
}	t_minimap;

void	draw_tile(
			t_minimap *minimap,
			t_image *img,
			t_player *player
			);

void	draw_player(
			double position_x,
			double position_y,
			t_player *player,
			t_image *img
			);

void	draw_minimap(
			double position_x,
			double position_y,
			t_mlx *mlx,
			t_player *player
			);

#endif
