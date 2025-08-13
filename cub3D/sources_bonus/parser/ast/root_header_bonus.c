/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_header_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:14:37 by bamarell          #+#    #+#             */
/*   Updated: 2025/07/24 14:01:09 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser_bonus.h"

bool	is_root_header_complete(t_root *root)
{
	if (root == NULL)
		return (false);
	if (root->ceiling_c == NULL || root->floor_c == NULL)
		return (false);
	if (root->north_tx == NULL || root->east_tx == NULL
		|| root->south_tx == NULL || root->west_tx == NULL)
		return (false);
	return (true);
}

bool	is_line_with_texture_or_color(t_parser *parser)
{
	size_t	i;
	t_token	*token;
	t_token	*token_ahead;

	i = 0;
	token = lexer_peek(parser->lexer);
	while (token != NULL && token->type != T_NEWLINE)
	{
		token_ahead = lexer_peek_ahead(parser->lexer->current_token, i);
		if (token_ahead == NULL || token->type == T_NEWLINE)
			return (false);
		if (token_is_texture(token_ahead) || token_is_color(token_ahead))
			return (true);
		++i;
	}
	return (false);
}

static
bool	parse_root_header_identifier(t_parser *parser, t_root *root,
	t_token *token)
{
	if (token_is_texture(token) && !root_assign_texture(parser, root,
			parser_parse_texture(parser)))
	{
		parser_set_error(parser, "invalid texture token");
		return (false);
	}
	if (token_is_color(token) && !root_assign_color(parser, root,
			parser_parse_color(parser)))
	{
		parser_set_error(parser, "invalid color token");
		return (false);
	}
	if (!parser_is_line_empty(parser))
	{
		parser_set_error(parser, "unexpected tokens after identifier");
		return (false);
	}
	return (true);
}

bool	parse_root_header(t_parser *parser, t_root *root)
{
	t_token	*token;

	if (!is_line_with_texture_or_color(parser))
		return (true);
	parser_skip_tokens(parser, T_SPACE);
	token = lexer_peek(parser->lexer);
	if (token == NULL || token->type == T_WORD)
		return (false);
	return (parse_root_header_identifier(parser, root, token));
}
