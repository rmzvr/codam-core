/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stripe_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:08:24 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/24 13:47:14 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state_bonus.h"
#include "drawer_bonus.h"

void	draw_vertical_stripe(
	int x,
	t_ray *ray,
	t_game_state *state
)
{
	t_wall			wall;

	initialize_wall(&wall, ray, &state->player, &state->textures);
	draw_ceiling(x, wall.start, &state->mlx.img, state->ceiling);
	draw_wall(x, &wall, &state->mlx, &state->textures);
	draw_floor(x, wall.end, &state->mlx.img, state->floor);
}
