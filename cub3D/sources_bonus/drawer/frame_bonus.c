/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:01:46 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/24 13:47:07 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state_bonus.h"
#include "drawer_bonus.h"

static void	move_to_next_tile_side(
	t_ray *ray
)
{
	if (ray->total_length_x < ray->total_length_y)
	{
		ray->total_length_x += ray->current_length_x;
		ray->current_tile_x += ray->step_direction_x;
		ray->hit_side = VERTICAL;
	}
	else
	{
		ray->total_length_y += ray->current_length_y;
		ray->current_tile_y += ray->step_direction_y;
		ray->hit_side = HORIZONTAL;
	}
}

static void	check_wall_hit(
	t_ray *ray,
	t_player *player
)
{
	if (player->map->raw[ray->current_tile_y][ray->current_tile_x] == WALL)
	{
		ray->hit = TRUE;
	}
}

static void	trace_ray_to_wall(
	t_ray *ray,
	t_player *player
)
{
	while (ray->hit == FALSE)
	{
		move_to_next_tile_side(ray);
		check_wall_hit(ray, player);
	}
}

static void	set_texture(
	t_ray *ray,
	t_textures *textures
)
{
	if (ray->hit_side == VERTICAL)
	{
		if (ray->step_direction_x > 0)
		{
			textures->current = &textures->west;
		}
		else
		{
			textures->current = &textures->east;
		}
	}
	else
	{
		if (ray->step_direction_y > 0)
		{
			textures->current = &textures->south;
		}
		else
		{
			textures->current = &textures->north;
		}
	}
}

void	render_frame(
	t_game_state *state
)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		initialize_ray(x, &ray, &state->player);
		trace_ray_to_wall(&ray, &state->player);
		set_texture(&ray, &state->textures);
		draw_vertical_stripe(x, &ray, state);
		x++;
	}
	mlx_put_image_to_window(
		state->mlx.ptr, state->mlx.win_ptr, state->mlx.img.ptr, 0, 0);
}
