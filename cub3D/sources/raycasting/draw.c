/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:08:24 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/15 14:01:40 by rzvir            ###   ########.fr       */
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

static unsigned int	get_color_from_texture(
	int texture_column_x,
	int tex_y,
	t_texture *texture_data
)
{
	unsigned int	color;
	int				x_offset;
	int				y_offset;
	char			*pixel_address;

	x_offset = texture_column_x * (texture_data->img.bytes_per_pixel / 8);
	y_offset = tex_y * texture_data->img.line_length;
	pixel_address = texture_data->img.pixels_addr + x_offset + y_offset;
	color = *(unsigned int *)pixel_address;
	return (color);
}

static void	draw_textured_wall(
	int x,
	t_ray *ray,
	t_wall *wall,
	t_game *game
)
{
	int				y;
	int				tex_y;
	unsigned int	color;
	int				texture_height;
	t_textured_wall	texture_data;

	y = wall->start;
	tex_y = 0;
	color = 0;
	texture_height = game->texture_data->xpm.height - 1;
	initialize_textured_wall(&texture_data, ray, wall, game);
	while (y < wall->end)
	{
		tex_y = (int)texture_data.texture_position & texture_height;
		texture_data.texture_position += texture_data.pixels_in_line;
		color = get_color_from_texture(
				texture_data.texture_column_x, tex_y, game->texture_data);
		my_mlx_pixel_put(&game->mlx.img, x, y, color);
		y++;
	}
}

void	draw_vertical_stripe(
	int x,
	t_ray *ray,
	t_wall *wall,
	t_game *game
)
{
	calc_distance_to_wall(ray);
	calc_wall_height(wall, ray->length_to_wall);
	calc_wall_color(
		ray->hit_side,
		ray->step_direction_x,
		ray->step_direction_y,
		wall
		);
	draw_ceiling(x, wall->start, game);
	draw_textured_wall(x, ray, wall, game);
	draw_floor(x, wall->end, game);
}
