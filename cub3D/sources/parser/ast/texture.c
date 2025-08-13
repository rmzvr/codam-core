/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/24 11:14:22 by bamarell      #+#    #+#                 */
/*   Updated: 2025/07/24 11:14:23 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "parser/parser.h"

static
char	*parser_parse_texture_path(t_parser *parser)
{
	char	*name;
	t_token	*token;

	name = NULL;
	token = lexer_peek(parser->lexer);
	while (token != NULL && token->type != T_SPACE
		&& token->type != T_NEWLINE)
	{
		token = lexer_pop(parser->lexer);
		name = ft_strjoin_s(name, ft_strdup(token->raw));
		if (name == NULL)
			return (NULL);
		token = lexer_peek(parser->lexer);
	}
	return (name);
}

static
t_ast_texture	*parser_texture_value(t_parser *parser, t_ast_texture *texture)
{
	t_token		*token;

	token = lexer_peek(parser->lexer);
	if (token == NULL || token->type == T_NEWLINE)
	{
		parser_destroy_texture(texture);
		return (NULL);
	}
	texture->path = parser_parse_texture_path(parser);
	if (texture->path == NULL)
	{
		parser_destroy_texture(texture);
		return (NULL);
	}
	return (texture);
}

t_ast_texture	*parser_parse_texture(t_parser *parser)
{
	t_ast_texture	*texture;
	t_token			*token;

	texture = ft_calloc(1, sizeof(t_ast_texture));
	if (texture == NULL)
		return (NULL);
	texture->node_type = T_TEXTURE;
	token = lexer_pop(parser->lexer);
	texture->type = token->type;
	parser_skip_tokens(parser, T_SPACE);
	return (parser_texture_value(parser, texture));
}

void	parser_destroy_texture(t_ast_texture *texture)
{
	if (texture == NULL)
		return ;
	if (texture->path != NULL)
		free(texture->path);
	free(texture);
}
