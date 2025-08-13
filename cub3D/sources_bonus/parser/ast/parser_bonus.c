/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:14:47 by bamarell          #+#    #+#             */
/*   Updated: 2025/07/24 14:01:04 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser_bonus.h"

t_parser	*parser_create(t_lexer *lexer)
{
	t_parser	*parser;

	parser = ft_calloc(1, sizeof(t_parser));
	if (parser == NULL)
		return (NULL);
	parser->lexer = lexer;
	return (parser);
}

t_root	*parser_parse(t_parser *parser)
{
	return (parser_parse_root(parser));
}

void	parser_set_error(t_parser *parser, const char *message)
{
	if (message != NULL && parser->error == NULL)
		parser->error = ft_strdup(message);
	else if (message == NULL)
	{
		if (parser->error != NULL)
			free(parser->error);
		parser->error = NULL;
	}
}

void	parser_destroy(t_parser *parser)
{
	if (parser == NULL)
		return ;
	if (parser->error != NULL)
		free(parser->error);
	free(parser);
}
