/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/15 14:19:56 by bamarell      #+#    #+#                 */
/*   Updated: 2025/07/24 10:20:50 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/malloc.h"
#include "libft/lst.h"
#include "libft/dfs.h"

/**
 * DFS or Depth-First-Search implementation
 *
 * An example implementation (from so_long) is shown below.
 *
 * ```
 * #include "dfs/dfs.h"
 * #include "so_long/map.h"
 *
 * static int	dfs_map_predicate(t_map *map, t_vec2 position)
 * {
 * 	size_t	index;
 *
 * 	index = position.x + (position.y * map->size.width) + position.y;
 * 	if (position.x < 0 || position.y < 0)
 * 		return (0);
 * 	if (index >= map->raw_len)
 * 		return (0);
 * 	return (!is_map_pos_of(map, position, SL_MAP_WALL));
 * }
 *
 * static int	is_path_to_pos(t_dfs *dfs, t_vec2 *pos)
 * {
 * 	return (dfs->visited[pos->y][pos->x]);
 * }
 *
 * static int	is_path_to_collectibles(t_map *map, t_dfs *dfs)
 * {
 * 	t_entity	*current_entity;
 * 	t_list		*current_entity_entry;
 *
 * 	current_entity_entry = map->entities;
 * 	while (current_entity_entry != NULL)
 * 	{
 * 		current_entity = (t_entity *)current_entity_entry->content;
 * 		if (current_entity->kind == EK_COLLECTIBLE
 * 			&& !is_path_to_pos(dfs, current_entity->position))
 * 			return (0);
 * 		current_entity_entry = current_entity_entry->next;
 * 	}
 * 	return (1);
 * }
 *
 * int	is_path_in_map(t_map *map)
 * {
 * 	t_dfs	*dfs;
 * 	int		is_valid_path;
 *
 * 	dfs = dfs_init(map->size.width, map->size.height);
 * 	if (dfs == NULL)
 * 		return (0);
 * 	dfs_visit(dfs, *map->start,
 * 		(int (*)(void *, t_vec2)) dfs_map_predicate, map);
 * 	is_valid_path = is_path_to_pos(dfs, map->exit)
 * 		&& is_path_to_collectibles(map, dfs);
 * 	dfs_destroy(dfs);
 * 	return (is_valid_path);
 * }
 * ```
*/
t_dfs	*dfs_init(size_t width, size_t height)
{
	t_dfs	*dfs;
	size_t	index;

	index = 0;
	dfs = malloc(sizeof(t_dfs));
	if (dfs == NULL)
		return (NULL);
	dfs->width = width;
	dfs->height = height;
	dfs->visited = ft_calloc(height, sizeof(int *));
	if (dfs->visited == NULL)
		return (dfs_destroy(dfs), NULL);
	while (index < height)
	{
		dfs->visited[index] = ft_calloc(width, sizeof(int));
		if (dfs->visited[index] == NULL)
			return (dfs_destroy(dfs), NULL);
		++index;
	}
	return (dfs);
}

static
bool	dfs_check_adjacent(t_dfs *dfs, t_vec2 pos,
	t_dfs_predicate test, void *ptr)
{
	t_vec2	*vec;
	t_list	*item;

	if (pos.x >= 0 && pos.y >= 0
		&& pos.x < dfs->width && pos.y < dfs->height
		&& !dfs->visited[(int) pos.y][(int) pos.x]
		&& test(ptr, pos))
	{
		vec = ft_vec2(pos.x, pos.y);
		if (vec == NULL)
			return (false);
		item = ft_lstnew(vec);
		if (item == NULL)
		{
			free(vec);
			return (false);
		}
		ft_lstadd_front(&dfs->stack, item);
	}
	return (true);
}

static
bool	dfs_visit_adjacent(t_dfs *dfs, t_vec2 pos,
	t_dfs_predicate test, void *ptr)
{
	size_t				index;
	t_vec2				offset;
	static const t_vec2	g_offsets[] = {
	{.x = 0, .y = -1},
	{.x = 1, .y = 0},
	{.x = 0, .y = 1},
	{.x = -1, .y = 0}
	};

	index = 0;
	while (index < 4)
	{
		offset = (t_vec2){.x = pos.x + g_offsets[index].x,
			.y = pos.y + g_offsets[index].y};
		if (!dfs_check_adjacent(dfs, offset, test, ptr))
			return (false);
		++index;
	}
	return (true);
}

bool	dfs_visit(t_dfs *dfs, t_vec2 pos, t_dfs_predicate test, void *ptr)
{
	t_list	*item;
	t_vec2	*vec;
	t_vec2	*new_pos;

	vec = ft_vec2(pos.x, pos.y);
	if (vec == NULL)
		return (false);
	dfs->stack = ft_lstnew(vec);
	if (dfs->stack == NULL)
		return (false);
	while (dfs->stack != NULL)
	{
		item = ft_lstpop_front(&dfs->stack);
		new_pos = (t_vec2 *) item->content;
		dfs->visited[(int) new_pos->y][(int) new_pos->x] = 1;
		if (!dfs_visit_adjacent(dfs, *new_pos, test, ptr))
		{
			ft_lstdelone(item, free);
			return (false);
		}
		ft_lstdelone(item, free);
	}
	return (true);
}

void	dfs_destroy(t_dfs *dfs)
{
	size_t	index;

	index = 0;
	if (dfs->visited != NULL)
	{
		while (index < dfs->height)
		{
			if (dfs->visited[index] != NULL)
				free(dfs->visited[index]);
			++index;
		}
		free(dfs->visited);
	}
	if (dfs->stack != NULL)
		ft_lstclear(&dfs->stack, free);
	free(dfs);
}
