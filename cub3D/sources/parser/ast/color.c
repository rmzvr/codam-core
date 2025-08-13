/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/24 11:14:49 by bamarell      #+#    #+#                 */
/*   Updated: 2025/07/24 11:14:50 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/stdlib.h"

#include "parser/parser.h"

static
bool	parse_raw_token_color(t_token *token, uint8_t *node_color)
{
	char		*endptr;
	const int	color = ft_strtol(token->raw, &endptr, 10);

	if (!ft_isdigits(token->raw))
		return (false);
	if (*endptr != '\0')
		return (false);
	if (color < 0 || color > 255)
		return (false);
	*node_color = color;
	return (true);
}

static
uint8_t	*color_from_index(t_color *color, size_t index)
{
	if (index == 0)
		return (&color->r);
	else if (index == 1)
		return (&color->g);
	else if (index == 2)
		return (&color->b);
	return (NULL);
}

static
bool	parser_parse_color_colors(t_parser *parser, t_color *color)
{
	t_token	*token;
	size_t	i;

	token = lexer_peek(parser->lexer);
	i = 0;
	while (token != NULL && token->type != T_NEWLINE && i < 3)
	{
		parser_skip_tokens(parser, T_SPACE);
		token = lexer_pop(parser->lexer);
		if (token == NULL || token->type != T_WORD)
			return (false);
		if (!parse_raw_token_color(token, color_from_index(color, i)))
			return (false);
		parser_skip_tokens(parser, T_SPACE);
		token = lexer_peek(parser->lexer);
		if (i < 2 && token != NULL && token->type != T_COMMA)
			return (false);
		if (i < 2 && token != NULL && token->type == T_COMMA)
			lexer_pop(parser->lexer);
		i++;
		token = lexer_peek(parser->lexer);
	}
	return (token != NULL);
}

t_color	*parser_parse_color(t_parser *parser)
{
	t_color	*color;
	t_token	*token;

	color = ft_calloc(1, sizeof(t_color));
	if (color == NULL)
		return (NULL);
	color->node_type = T_COLOR;
	token = lexer_pop(parser->lexer);
	color->type = token->type;
	if (!parser_parse_color_colors(parser, color))
	{
		parser_set_error(parser, "failed to parse color");
		parser_destroy_color(color);
		return (NULL);
	}
	return (color);
}

void	parser_destroy_color(t_color *color)
{
	if (color == NULL)
		return ;
	free(color);
}
