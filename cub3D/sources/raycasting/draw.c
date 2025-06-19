/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:08:24 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/19 17:14:35 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	draw_ceiling(
	int x,
	double wall_start,
	t_game *game
)
{
	if (wall_start > 0)
	{
		draw_line(game, x, 0, x, wall_start, 0x87CEEB);
	}
}

static void	draw_floor(
	int x,
	double wall_end,
	t_game *game
)
{
	if (wall_end < WINDOW_WIDTH)
	{
		draw_line(game, x, wall_end, x, WINDOW_WIDTH, 0x4B3621);
	}
}

double	calc_hit_point_of_wall(t_ray *ray, t_game *game)
{
	double hit_point_x;

	if (ray->hit_side == VERTICAL)
		hit_point_x = game->pos_y + ray->length_to_wall * ray->direction_y;
	else
		hit_point_x = game->pos_x + ray->length_to_wall * ray->direction_x;
	hit_point_x -= floor(hit_point_x);
	return (hit_point_x);
}

int	calc_texture_flipped_value(int texture_column_x, int texture_width, t_ray *ray)
{
	if ((ray->hit_side == VERTICAL && ray->direction_x > 0)
		|| (ray->hit_side == HORIZONTAL && ray->direction_y < 0))
	{
		texture_column_x = texture_width - texture_column_x - 1;
	}
	return (texture_column_x);
}

int	calc_texture_column_x(double hit_point_x, t_texture *texture, t_ray *ray)
{
	int	texture_column_x;

	texture_column_x = (int)(hit_point_x * (double)texture->xpm.width);
	texture_column_x = calc_texture_flipped_value(texture_column_x, texture->xpm.width, ray);
	return (texture_column_x);
}

unsigned int	get_color_from_texture(int  texture_column_x, int tex_y, t_texture *texture_data)
{
	unsigned int color;

	color = *(unsigned int *)(texture_data->img.pixels_addr + (tex_y * texture_data->img.line_length + texture_column_x * (texture_data->img.bytes_per_pixel / 8)));
	return (color);
}

void	draw_textured_wall(
	int x,
	t_ray *ray,
	t_wall *wall,
	t_game *game,
	t_texture *texture_data
)
{
	int				y;
	double			hit_point_x;
	int				texture_column_x;
	double			count_of_texture_pixels_in_line_pixels;
	double			texture_position;
	int				tex_y;
	unsigned int	color;

	y = wall->start;
	hit_point_x = calc_hit_point_of_wall(ray, game);
	texture_column_x = calc_texture_column_x(hit_point_x, texture_data, ray);
	count_of_texture_pixels_in_line_pixels = 1.0 * texture_data->xpm.height / wall->height;
	texture_position = (wall->start - WINDOW_HEIGHT / 2 + wall->height / 2) * count_of_texture_pixels_in_line_pixels;
	while (y < wall->end)
	{
		tex_y = (int)texture_position & (texture_data->xpm.height - 1);
		texture_position += count_of_texture_pixels_in_line_pixels;
		color = get_color_from_texture(texture_column_x, tex_y, texture_data);

		my_mlx_pixel_put(&game->mlx.img, x, y, color);
		y++;
	}
}


static void	draw_wall(
	int x,
	t_ray *ray,
	t_wall *wall,
	t_game *game,
	t_texture *texture_data
)
{
	draw_textured_wall(x, ray, wall, game, texture_data);
}

void	draw_vertical_stripe(
	int x,
	t_ray *ray,
	t_wall *wall,
	t_game *game,
	t_texture *texture_data
)
{
	calc_distance_to_wall(ray);
	calc_wall_height(wall, ray->length_to_wall);
	calc_wall_color(ray->hit_side, ray->step_direction_x, ray->step_direction_y, wall);
	draw_ceiling(x, wall->start, game);
	draw_wall(x, ray, wall, game, texture_data);
	draw_floor(x, wall->end, game);
}
