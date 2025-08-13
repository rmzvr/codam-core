/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rzvir <rzvir@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/21 14:14:10 by rzvir         #+#    #+#                 */
/*   Updated: 2025/07/24 11:19:08 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "parser/ast.h"

typedef struct s_ray	t_ray;

typedef struct s_xpm
{
	char	*path;
	int		width;
	int		height;
}	t_xpm;

typedef struct s_texture
{
	t_xpm	xpm;
	t_image	img;
}	t_texture;
typedef struct s_textures
{
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	t_texture	*current;
}	t_textures;

t_bool	initialize_textures(
			t_root *root,
			t_textures *textures,
			t_mlx *mlx
			);

int		calc_texture_column_x(
			double hit_point_x,
			t_texture *texture,
			t_ray *ray
			);

double	get_texture_position(
			int wall_start,
			int wall_height,
			double pixels_in_line
			);

#endif
