/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:24:12 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/24 13:41:14 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_BONUS_H
# define PLAYER_BONUS_H

# include "utils_bonus.h"
# include "parser/ast_bonus.h"

typedef t_vec2	t_plane;
typedef t_vec2	t_position;
typedef t_vec2	t_direction;

typedef struct s_player
{
	double		size;
	t_plane		plane;
	t_position	position;
	t_direction	direction;
	t_map		*map;
}	t_player;

void	initialize_player(t_player *player);

#endif