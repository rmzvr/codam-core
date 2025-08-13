/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:11:54 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/22 17:54:45 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"
#include "drawer.h"

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

int	calc_texture_column_x(
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

double	get_texture_position(
	int wall_start,
	int wall_height,
	double pixels_in_line
)
{
	return (
		(wall_start - WINDOW_HEIGHT / 2 + wall_height / 2) * pixels_in_line
	);
}

static t_bool	load_texture_image(
	char *path,
	t_texture *texture,
	t_mlx *mlx
)
{
	texture->xpm.path = path;
	texture->img.ptr = mlx_xpm_file_to_image(
			mlx->ptr,
			texture->xpm.path,
			&texture->xpm.width,
			&texture->xpm.height
			);
	if (texture->img.ptr == NULL)
		return (FALSE);
	texture->img.pixels_addr = mlx_get_data_addr(
			texture->img.ptr,
			&texture->img.bytes_per_pixel,
			&texture->img.line_length,
			&texture->img.endian
			);
	return (TRUE);
}

t_bool	initialize_textures(
	t_root *root,
	t_textures *textures,
	t_mlx *mlx
)
{
	if (!load_texture_image(root->north_tx->path, &textures->north, mlx))
		return (FALSE);
	if (!load_texture_image(root->south_tx->path, &textures->south, mlx))
		return (FALSE);
	if (!load_texture_image(root->west_tx->path, &textures->west, mlx))
		return (FALSE);
	if (!load_texture_image(root->east_tx->path, &textures->east, mlx))
		return (FALSE);
	return (TRUE);
}
