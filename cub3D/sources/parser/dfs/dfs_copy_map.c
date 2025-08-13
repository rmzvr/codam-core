/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dfs_copy_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/24 11:14:20 by bamarell      #+#    #+#                 */
/*   Updated: 2025/07/24 11:14:20 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

static
char	*append_empty_line(char **new_str, size_t len, size_t index)
{
	new_str[index] = ft_calloc(1, (len + 2 + 1) * sizeof(char));
	if (new_str[index] == NULL)
		return (NULL);
	ft_memset(new_str[index], ' ', len + 2);
	return (new_str[index]);
}

static
char	**dfs_copy_map_lines(char **prev, char **new_str)
{
	size_t	i;
	size_t	x;
	size_t	len;

	i = 1;
	x = 0;
	while (prev[x] != NULL)
	{
		len = ft_strlen(prev[x]);
		new_str[i] = ft_calloc(1, (len + 2 + 1) * sizeof(char));
		if (new_str[i] == NULL)
		{
			ft_free2d((void **) new_str);
			return (NULL);
		}
		new_str[i][0] = ' ';
		new_str[i][len + 1] = ' ';
		ft_memcpy(new_str[i] + 1, prev[x], len * sizeof(char));
		++i;
		++x;
	}
	return (new_str);
}

// Make a copy of the two-dimensional map but surround it with spaces.
// We do this in order to check whether all edges are in fact surrounded
// by a wall.
char	**dfs_copy_map(char **str)
{
	size_t	i;
	char	**new_str;

	i = 0;
	if (str[0] == NULL)
		return (NULL);
	while (str[i] != NULL)
		++i;
	new_str = ft_calloc(i + 2 + 1, sizeof(char *));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != NULL)
		++i;
	if (append_empty_line(new_str, ft_strlen(str[0]), 0) == NULL
		|| dfs_copy_map_lines(str, new_str) == NULL
		|| append_empty_line(new_str, ft_strlen(str[0]), i + 1) == NULL)
	{
		ft_free2d((void **) new_str);
		return (NULL);
	}
	return (new_str);
}
