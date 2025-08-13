/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:53:34 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/24 13:47:03 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state_bonus.h"
#include "drawer_bonus.h"

static unsigned int	get_color_from_texture(
	int texture_column_x,
	int tex_y,
	t_texture *current_texture
)
{
	unsigned int	color;
	int				x_offset;
	int				y_offset;
	char			*pixel_address;

	x_offset = texture_column_x * (current_texture->img.bytes_per_pixel / 8);
	y_offset = tex_y * current_texture->img.line_length;
	pixel_address = current_texture->img.pixels_addr + x_offset + y_offset;
	color = *(unsigned int *)pixel_address;
	return (color);
}

void	draw_wall(
	int x,
	t_wall *wall,
	t_mlx *mlx,
	t_textures *textures
)
{
	int				tex_y;
	unsigned int	color;
	int				texture_height;

	tex_y = 0;
	color = 0;
	texture_height = textures->current->xpm.height - 1;
	while (wall->start < wall->end)
	{
		tex_y = (int)wall->texture_position & texture_height;
		wall->texture_position += wall->pixels_in_line;
		color = get_color_from_texture(
				wall->texture_column_x, tex_y, textures->current);
		put_pixel(&mlx->img, x, wall->start, color);
		wall->start++;
	}
}

void	draw_ceiling(
	int x,
	double wall_start,
	t_image *img,
	t_color *color
)
{
	t_axis	x_axis;
	t_axis	y_axis;

	x_axis.start = x;
	x_axis.end = x;
	y_axis.start = 0;
	y_axis.end = wall_start;
	if (wall_start > 0)
	{
		draw_line(
			&x_axis,
			&y_axis,
			(color->r << 16) + (color->g << 8) + color->b,
			img
			);
	}
}

void	draw_floor(
	int x,
	double wall_end,
	t_image *img,
	t_color *color
)
{
	t_axis	x_axis;
	t_axis	y_axis;

	x_axis.start = x;
	x_axis.end = x;
	y_axis.start = wall_end;
	y_axis.end = WINDOW_HEIGHT;
	if (wall_end < WINDOW_HEIGHT)
	{
		draw_line(
			&x_axis,
			&y_axis,
			(color->r << 16) + (color->g << 8) + color->b,
			img
			);
	}
}
