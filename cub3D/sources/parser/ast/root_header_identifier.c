/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   root_header_identifier.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/24 11:14:44 by bamarell      #+#    #+#                 */
/*   Updated: 2025/07/24 11:14:44 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

static
bool	root_assign_node(t_node **node, t_node *value, bool override)
{
	if (*node != NULL && !override)
		return (false);
	*node = value;
	return (true);
}

bool	root_assign_color(t_parser *parser, t_root *root, t_color *color)
{
	t_color	**prop;

	if (color == NULL)
		return (false);
	if (color->type == T_CC)
		prop = &root->ceiling_c;
	else if (color->type == T_FC)
		prop = &root->floor_c;
	else
		return (false);
	if (*prop && ALLOW_ELEMENT_OVERRIDE)
		parser_destroy_color(*prop);
	if (!root_assign_node((t_node **) prop,
			(t_node *) color, ALLOW_ELEMENT_OVERRIDE))
	{
		parser_set_error(parser, "multiple color assignments");
		parser_destroy_color(color);
		return (false);
	}
	return (true);
}

bool	root_assign_texture(t_parser *parser, t_root *root,
	t_ast_texture *texture)
{
	t_ast_texture	**prop;

	if (texture == NULL)
		return (false);
	if (texture->type == T_TX_NO)
		prop = &root->north_tx;
	else if (texture->type == T_TX_SO)
		prop = &root->south_tx;
	else if (texture->type == T_TX_WE)
		prop = &root->west_tx;
	else if (texture->type == T_TX_EA)
		prop = &root->east_tx;
	else
		return (false);
	if (*prop && ALLOW_ELEMENT_OVERRIDE)
		parser_destroy_texture(*prop);
	if (!root_assign_node((t_node **) prop,
			(t_node *) texture, ALLOW_ELEMENT_OVERRIDE))
	{
		parser_set_error(parser, "multiple texture assignments");
		parser_destroy_texture(texture);
		return (false);
	}
	return (true);
}
