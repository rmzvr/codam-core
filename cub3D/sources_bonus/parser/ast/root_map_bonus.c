/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:14:29 by bamarell          #+#    #+#             */
/*   Updated: 2025/07/24 14:01:14 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser_bonus.h"

static
t_map	*parse_map_finalize(t_parser *parser, t_map *map)
{
	if (!map_adjust_lines_width(map))
	{
		parser_set_error(parser, "failed to adjust map line width");
		parser_destroy_map(map);
		return (NULL);
	}
	return (map);
}

static
t_map	*parse_map(t_parser *parser)
{
	t_map	*map;
	t_token	*token;
	char	*line;

	map = ft_calloc(1, sizeof(t_map));
	if (map == NULL)
		return (NULL);
	token = lexer_peek(parser->lexer);
	while (token != NULL)
	{
		if (parser_is_line_empty(parser))
			break ;
		line = consume_line_tokens(parser);
		if (!map_add_line(parser, map, line))
		{
			parser_destroy_map(map);
			return (NULL);
		}
		map->height++;
		lexer_pop(parser->lexer);
		token = lexer_peek(parser->lexer);
	}
	return (parse_map_finalize(parser, map));
}

bool	parse_root_map(t_parser *parser, t_root *root)
{
	t_token	*token;

	if (!is_first_map_line(parser))
		return (false);
	if (!is_root_header_complete(root))
	{
		parser_set_error(parser, "map is not at the end of the file");
		return (false);
	}
	root->map = parse_map(parser);
	if (!parse_map_positions(parser, root))
	{
		parser_set_error(parser, "failed to parse map positions");
		return (false);
	}
	parser_skip_spaces(parser);
	token = lexer_peek(parser->lexer);
	if (token != NULL)
	{
		parser_set_error(parser, "unexpected tokens after map");
		return (false);
	}
	return (root->map != NULL);
}

bool	is_root_map_complete(t_root *root)
{
	return (root->map != NULL
		&& root->map->raw != NULL
		&& root->map->width > MIN_MAP_WIDTH
		&& root->map->height > MIN_MAP_HEIGHT
		&& root->map->spawn_dir != '\0'
		&& is_map_bordered(root->map));
}

void	parser_destroy_map(t_map *map)
{
	if (map == NULL)
		return ;
	if (map->raw != NULL)
		ft_free2d((void **) map->raw);
	free(map);
}
