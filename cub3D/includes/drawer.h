/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawer.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rzvir <rzvir@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/18 18:37:26 by rzvir         #+#    #+#                 */
/*   Updated: 2025/07/24 11:26:00 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWER_H
# define DRAWER_H

# include "state.h"
# include "utils.h"
# include "texture.h"

typedef enum e_side
{
	VERTICAL,
	HORIZONTAL,
}	t_side;

typedef struct s_axis
{
	int	start;
	int	end;
	int	delta;
}	t_axis;

typedef struct s_wall
{
	int		start;
	int		end;
	int		color;
	int		height;
	int		texture_column_x;
	double	hit_point_x;
	double	pixels_in_line;
	double	texture_position;
}	t_wall;

typedef struct s_ray
{
	t_bool		hit;
	t_side		hit_side;

	int			current_tile_x;
	int			current_tile_y;

	double		direction_x;
	double		direction_y;

	int			step_direction_x;
	int			step_direction_y;

	double		current_length_x;
	double		current_length_y;

	double		total_length_x;
	double		total_length_y;

	double		length_to_wall;
}	t_ray;

void	initialize_ray(
			int x,
			t_ray *ray,
			t_player *player
			);
void	initialize_wall(
			t_wall *wall,
			t_ray *ray,
			t_player *player,
			t_textures *textures
			);

void	render_frame(
			t_game_state *state
			);

void	draw_vertical_stripe(
			int x,
			t_ray *ray,
			t_game_state *state
			);
void	draw_line(
			t_axis *x_axis,
			t_axis *y_axis,
			int color,
			t_image *img
			);

void	draw_floor(
			int x,
			double wall_end,
			t_image *img,
			t_color *color
			);
void	draw_ceiling(
			int x,
			double wall_start,
			t_image *img,
			t_color *color
			);
void	draw_wall(
			int x,
			t_wall *wall,
			t_mlx *mlx,
			t_textures *textures
			);

#endif
