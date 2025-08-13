/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:06:23 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/24 13:41:26 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_BONUS_H
# define STATE_BONUS_H

# include <math.h>
# include <stdio.h>
# include <X11/keysym.h>

# include "mlx.h"
# include "libft.h"

# include "window_bonus.h"
# include "player_bonus.h"
# include "texture_bonus.h"
# include "movement_bonus.h"
# include "parser/parser_bonus.h"

# define PROGRAM_NAME "cub3D"
# define FILENAME_EXTENSION ".cub"
# define TILE_SIZE 30
# define FOV 0.66
# define MINIMAP_RADIUS 6
# define SENSITIVITY 1.0
# define WINDOW_WIDTH 740
# define WINDOW_HEIGHT 740
# define CAMERA_PLANE_X 0.0
# define CAMERA_PLANE_Y 0.66
# define MOVE_TILE_PER_SECOND 3.0
# define ROTATE_RADIAN_PER_SECOND 3.0

typedef struct s_game_state
{
	t_mlx		mlx;
	t_player	player;
	t_move		move;
	t_rotate	rotate;
	t_textures	textures;
	double		time_since_last_frame;
	t_map		*map;
	t_color		*floor;
	t_color		*ceiling;
}	t_game_state;

void	initialize_hooks(t_game_state *state);
void	initialize_focus_hooks(t_game_state *state);

char	*read_file(const char *path);
#endif
