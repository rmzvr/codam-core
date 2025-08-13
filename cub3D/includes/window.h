/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rzvir <rzvir@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/21 09:58:17 by rmzvr         #+#    #+#                 */
/*   Updated: 2025/07/23 12:24:39 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "utils.h"
# include "state.h"

typedef struct s_game_state	t_game_state;

typedef struct s_image
{
	void	*ptr;
	char	*pixels_addr;
	int		bytes_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_mlx
{
	void	*ptr;
	void	*win_ptr;
	t_image	img;
	t_bool	is_focused;
}	t_mlx;

t_bool	initialize_window_and_image(t_mlx *mlx);

void	cleanup_game_state(t_game_state *state);

void	put_pixel(t_image *data, int x, int y, int color);

#endif