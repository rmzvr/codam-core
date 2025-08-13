/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub_dfs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/24 11:17:24 by bamarell      #+#    #+#                 */
/*   Updated: 2025/07/24 11:17:24 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_DFS_H
# define CUB_DFS_H

# include "parser/ast.h"

bool	is_map_bordered(t_map *map);
t_vec2	find_set_pos(char **raw, char *charset);
bool	is_any_of_visited(t_dfs *dfs, char **raw, char *charset);
void	fill_visited_walls(t_dfs *dfs, char **raw, int ch);

bool	dfs_cub_visit(t_dfs *dfs, char **raw);
char	**dfs_copy_map(char **str);
#endif
