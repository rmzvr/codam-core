/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   root.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/24 11:14:27 by bamarell      #+#    #+#                 */
/*   Updated: 2025/07/24 11:14:27 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

t_root	*parser_parse_root(t_parser *parser)
{
	t_root	*root;
	t_token	*token;

	root = ft_calloc(1, sizeof(t_root));
	if (root == NULL)
		return (NULL);
	root->node_type = T_ROOT;
	token = lexer_peek(parser->lexer);
	while (token != NULL && parser->error == NULL)
	{
		parse_root_header(parser, root);
		if (parse_root_map(parser, root))
			break ;
		parser_skip_line_if_empty(parser);
		token = lexer_peek(parser->lexer);
	}
	return (root);
}

bool	parser_validate_root(t_parser *parser, t_root *root)
{
	if (parser->error != NULL)
		return (false);
	if (!is_root_header_complete(root))
		parser_set_error(parser, "map header is incomplete");
	else if (root->map == NULL || root->map->raw == NULL)
		parser_set_error(parser, "failed to parse map");
	else if (root->map->width <= MIN_MAP_WIDTH
		&& root->map->height <= MIN_MAP_HEIGHT)
		parser_set_error(parser, "invalid map dimensions");
	else if (root->map->spawn_dir == '\0')
		parser_set_error(parser, "missing spawn");
	else if (!is_map_bordered(root->map))
		parser_set_error(parser, "invalid walls");
	else
		return (true);
	return (false);
}

void	parser_destroy_root(t_root *root)
{
	if (root == NULL)
		return ;
	if (root->ceiling_c != NULL)
		parser_destroy_color(root->ceiling_c);
	if (root->floor_c != NULL)
		parser_destroy_color(root->floor_c);
	if (root->north_tx != NULL)
		parser_destroy_texture(root->north_tx);
	if (root->east_tx != NULL)
		parser_destroy_texture(root->east_tx);
	if (root->south_tx != NULL)
		parser_destroy_texture(root->south_tx);
	if (root->west_tx != NULL)
		parser_destroy_texture(root->west_tx);
	if (root->map != NULL)
		parser_destroy_map(root->map);
	free(root);
}
