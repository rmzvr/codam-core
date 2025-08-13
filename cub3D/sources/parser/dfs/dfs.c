/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/24 11:14:14 by bamarell      #+#    #+#                 */
/*   Updated: 2025/07/24 11:17:47 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/dfs.h"
#include "parser/parser.h"
#include "parser/cub_dfs.h"

t_vec2	find_set_pos(char **raw, char *charset)
{
	size_t	y;
	size_t	x;

	x = 0;
	y = 0;
	while (raw[y] != NULL)
	{
		while (raw[y][x] != '\0')
		{
			if (ft_strchr(charset, raw[y][x]) != NULL)
				return ((t_vec2){.x = x, .y = y});
			++x;
		}
		++y;
		x = 0;
	}
	return ((t_vec2){.x = -1, .y = -1});
}

bool	is_any_of_visited(t_dfs *dfs, char **raw, char *charset)
{
	size_t	y;
	size_t	x;

	x = 0;
	y = 0;
	while (raw[y] != NULL)
	{
		while (raw[y][x] != '\0')
		{
			if (dfs->visited[y][x] && ft_strchr(charset, raw[y][x]) != NULL)
				return (true);
			++x;
		}
		++y;
		x = 0;
	}
	return (false);
}

void	fill_visited_walls(t_dfs *dfs, char **raw, int ch)
{
	size_t	y;
	size_t	x;

	x = 0;
	y = 0;
	while (raw[y] != NULL)
	{
		while (raw[y][x] != '\0')
		{
			if (dfs->visited[y][x]
					&& ft_strchr(SPAWN_CHARSET, raw[y][x]) == NULL)
				raw[y][x] = ch;
			++x;
		}
		++y;
		x = 0;
	}
}

bool	is_map_bordered(t_map *map)
{
	t_dfs	*dfs;
	char	**raw_copy;
	bool	is_valid;

	dfs = dfs_init(map->width + 2, map->height + 2);
	if (dfs == NULL)
		return (false);
	raw_copy = dfs_copy_map(map->raw);
	if (raw_copy == NULL)
	{
		dfs_destroy(dfs);
		return (false);
	}
	is_valid = dfs_cub_visit(dfs, raw_copy);
	ft_free2d((void **) raw_copy);
	dfs_destroy(dfs);
	return (is_valid);
}
