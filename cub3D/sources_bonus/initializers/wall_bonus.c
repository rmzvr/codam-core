/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:18:15 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/24 13:47:28 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state_bonus.h"
#include "drawer_bonus.h"

static void	set_distance_to_wall(
	t_ray *ray
)
{
	if (ray->hit_side == VERTICAL)
	{
		ray->length_to_wall = (ray->total_length_x - ray->current_length_x);
	}
	else
	{
		ray->length_to_wall = (ray->total_length_y - ray->current_length_y);
	}
}

static void	set_wall_color(
	t_side hit_side,
	int step_direction_x,
	int step_direction_y,
	t_wall *wall
)
{
	if (hit_side == VERTICAL)
	{
		if (step_direction_x == 1)
			wall->color = 0xFF0000;
		else
			wall->color = 0x00FF00;
	}
	else
	{
		if (step_direction_y == 1)
			wall->color = 0x0000FF;
		else
			wall->color = 0xFFFF00;
	}
}

static void	set_wall_height(
	t_wall *wall,
	double length_to_wall
)
{
	wall->height = (int)(WINDOW_HEIGHT / length_to_wall);
	wall->start = -wall->height / 2 + WINDOW_HEIGHT / 2;
	if (wall->start < 0)
	{
		wall->start = 0;
	}
	wall->end = wall->height / 2 + WINDOW_HEIGHT / 2;
	if (wall->end >= WINDOW_HEIGHT)
	{
		wall->end = WINDOW_HEIGHT - 1;
	}
}

static double	calc_hit_point_of_wall(t_ray *ray, t_player *player)
{
	double	hit_offset;
	double	hit_point_x;

	if (ray->hit_side == VERTICAL)
	{
		hit_offset = ray->length_to_wall * ray->direction_y;
		hit_point_x = player->position.y + hit_offset;
	}
	else
	{
		hit_offset = ray->length_to_wall * ray->direction_x;
		hit_point_x = player->position.x + hit_offset;
	}
	hit_point_x -= floor(hit_point_x);
	return (hit_point_x);
}

void	initialize_wall(
	t_wall *wall,
	t_ray *ray,
	t_player *player,
	t_textures *textures
)
{
	wall->start = 0;
	wall->end = 0;
	wall->color = 0x000000;
	wall->height = 0;
	set_distance_to_wall(ray);
	set_wall_height(wall, ray->length_to_wall);
	set_wall_color(
		ray->hit_side,
		ray->step_direction_x,
		ray->step_direction_y,
		wall
		);
	wall->hit_point_x = calc_hit_point_of_wall(ray, player);
	wall->texture_column_x = calc_texture_column_x(
			wall->hit_point_x, textures->current, ray);
	wall->pixels_in_line = 1.0 * textures->current->xpm.height / wall->height;
	wall->texture_position = get_texture_position(
			wall->start, wall->height, wall->pixels_in_line);
}
