/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:14:25 by bamarell          #+#    #+#             */
/*   Updated: 2025/07/24 14:01:20 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser_bonus.h"

void	parser_skip_tokens(t_parser *parser, t_token_type type)
{
	t_token	*token;

	token = lexer_peek(parser->lexer);
	while (token != NULL && token->type == type)
	{
		lexer_pop(parser->lexer);
		token = lexer_peek(parser->lexer);
	}
}

void	parser_skip_spaces(t_parser *parser)
{
	t_token	*token;

	token = lexer_peek(parser->lexer);
	while (token != NULL && (token->type == T_SPACE
			|| token->type == T_NEWLINE))
	{
		lexer_pop(parser->lexer);
		token = lexer_peek(parser->lexer);
	}
}

bool	parser_is_line_empty(t_parser *parser)
{
	size_t	i;
	t_token	*token;

	i = 0;
	while (true)
	{
		token = lexer_peek_ahead(parser->lexer->current_token, i);
		if (token == NULL || token->type == T_NEWLINE)
			return (true);
		if (token->type != T_SPACE)
			return (false);
		++i;
	}
	return (true);
}

void	parser_skip_line_if_empty(t_parser *parser)
{
	t_token	*token;

	if (!parser_is_line_empty(parser))
		return ;
	token = lexer_peek(parser->lexer);
	while (token != NULL && token->type != T_NEWLINE)
	{
		lexer_pop(parser->lexer);
		token = lexer_peek(parser->lexer);
	}
	if (token != NULL && token->type == T_NEWLINE)
		lexer_pop(parser->lexer);
}
