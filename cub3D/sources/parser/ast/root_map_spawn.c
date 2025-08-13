/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   root_map_spawn.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/24 11:14:31 by bamarell      #+#    #+#                 */
/*   Updated: 2025/07/24 11:17:02 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"
#include "libft/math/vec2.h"

static
bool	root_update_spawn(t_parser *parser, t_root *root,
	t_vec2 vec2, int ch)
{
	if (root->map->spawn_dir != '\0' && !ALLOW_SPAWN_OVERRIDE)
	{
		parser_set_error(parser, "multiple spawn locations");
		return (false);
	}
	root->map->spawn_dir = ch;
	root->map->spawn = vec2;
	return (true);
}

bool	parse_map_positions(t_parser *parser, t_root *root)
{
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;
	if (root->map == NULL)
		return (false);
	while (root->map->raw[y] != NULL)
	{
		while (root->map->raw[y][x] != '\0')
		{
			if (ft_strchr(SPAWN_CHARSET, root->map->raw[y][x]) != NULL)
			{
				if (!root_update_spawn(parser, root,
						(t_vec2){x, y}, root->map->raw[y][x]))
					return (false);
			}
			++x;
		}
		x = 0;
		++y;
	}
	return (true);
}
