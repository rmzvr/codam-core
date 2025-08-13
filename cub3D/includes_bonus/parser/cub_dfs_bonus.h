/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_dfs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:17:24 by bamarell          #+#    #+#             */
/*   Updated: 2025/07/24 13:40:44 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_DFS_BONUS_H
# define CUB_DFS_BONUS_H

# include "parser/ast_bonus.h"

bool	is_map_bordered(t_map *map);
t_vec2	find_set_pos(char **raw, char *charset);
bool	is_any_of_visited(t_dfs *dfs, char **raw, char *charset);
void	fill_visited_walls(t_dfs *dfs, char **raw, int ch);

bool	dfs_cub_visit(t_dfs *dfs, char **raw);
char	**dfs_copy_map(char **str);
#endif
