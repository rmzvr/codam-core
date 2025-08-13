/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_visit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:14:17 by bamarell          #+#    #+#             */
/*   Updated: 2025/07/24 13:43:48 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/dfs.h"
#include "parser/parser_bonus.h"
#include "parser/cub_dfs_bonus.h"

static
bool	dfs_map_predicate(char **raw, t_vec2 pos)
{
	return (raw[(int) pos.y][(int) pos.x] != '1');
}

bool	dfs_cub_visit_zero(t_dfs *dfs, char **raw)
{
	t_vec2	pos;

	pos = find_set_pos(raw, "0");
	if (pos.x == -1 && pos.y == -1)
		return (is_any_of_visited(dfs, raw, SPAWN_CHARSET));
	dfs_visit(dfs, pos, (bool (*)(void *, t_vec2)) dfs_map_predicate, raw);
	if (is_any_of_visited(dfs, raw, " "))
		return (false);
	fill_visited_walls(dfs, raw, '1');
	return (dfs_cub_visit_zero(dfs, raw));
}

// Only visit from spawn point and ignore all zeroes.
// As long as the routes relative to the player spawn do NOT reach a place
// outside of its walls, it's considered valid.
bool	dfs_cub_visit_spawn(t_dfs *dfs, char **raw)
{
	t_vec2	pos;

	pos = find_set_pos(raw, SPAWN_CHARSET);
	if (pos.x == -1 || pos.y == -1)
		return (false);
	dfs_visit(dfs, pos, (bool (*)(void *, t_vec2)) dfs_map_predicate, raw);
	if (is_any_of_visited(dfs, raw, " "))
		return (false);
	fill_visited_walls(dfs, raw, '1');
	return (true);
}

bool	dfs_cub_visit(t_dfs *dfs, char **raw)
{
	return (dfs_cub_visit_spawn(dfs, raw) && dfs_cub_visit_zero(dfs, raw));
}
