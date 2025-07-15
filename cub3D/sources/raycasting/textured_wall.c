/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textured_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:51:33 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/15 14:45:23 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static double	calc_hit_point_of_wall(t_ray *ray, t_game *game)
{
	double	hit_offset;
	double	hit_point_x;

	if (ray->hit_side == VERTICAL)
	{
		hit_offset = ray->length_to_wall * ray->direction_y;
		hit_point_x = game->position_y + hit_offset;
	}
	else
	{
		hit_offset = ray->length_to_wall * ray->direction_x;
		hit_point_x = game->position_x + hit_offset;
	}
	hit_point_x -= floor(hit_point_x);
	return (hit_point_x);
}

static int	calc_texture_flipped_value(
	int texture_column_x,
	int texture_width,
	t_ray *ray
)
{
	if ((ray->hit_side == VERTICAL && ray->direction_x > 0)
		|| (ray->hit_side == HORIZONTAL && ray->direction_y < 0))
	{
		texture_column_x = texture_width - texture_column_x - 1;
	}
	return (texture_column_x);
}

static int	calc_texture_column_x(
	double hit_point_x,
	t_texture *texture,
	t_ray *ray
)
{
	int	texture_column_x;

	texture_column_x = (int)(hit_point_x * (double)texture->xpm.width);
	texture_column_x = calc_texture_flipped_value(
			texture_column_x,
			texture->xpm.width,
			ray
			);
	return (texture_column_x);
}

static double	get_texture_position(
	int wall_start,
	int wall_height,
	double pixels_in_line
)
{
	return ((wall_start - WINDOW_Y_CENTER + wall_height / 2) * pixels_in_line);
}

void	initialize_textured_wall(
	t_textured_wall	*data,
	t_ray *ray,
	t_wall *wall,
	t_game *game
)
{
	data->hit_point_x = calc_hit_point_of_wall(ray, game);
	data->texture_column_x = calc_texture_column_x(
			data->hit_point_x, game->texture_data, ray);
	data->pixels_in_line = 1.0 * game->texture_data->xpm.height / wall->height;
	data->texture_position = get_texture_position(
			wall->start, wall->height, data->pixels_in_line);
}
