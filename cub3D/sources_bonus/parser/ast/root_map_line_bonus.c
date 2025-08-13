/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_map_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:14:33 by bamarell          #+#    #+#             */
/*   Updated: 2025/07/24 14:01:16 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser/parser_bonus.h"

bool	is_first_map_line(t_parser *parser)
{
	t_list	*raw_token;
	t_token	*token;

	raw_token = parser->lexer->current_token;
	if (raw_token == NULL)
		return (false);
	while (raw_token != NULL)
	{
		token = (t_token *) raw_token->content;
		if (token->type != T_SPACE && token->type != T_WORD)
			return (false);
		if (token->type == T_SPACE)
			raw_token = raw_token->next;
		else if (token->type == T_WORD)
		{
			if (token_is_map_token(token))
				return (true);
			parser_set_error(parser, "invalid token");
			return (false);
		}
		else
			break ;
	}
	return (false);
}

char	*consume_line_tokens(t_parser *parser)
{
	char	*line;
	t_token	*token;

	line = NULL;
	token = lexer_peek(parser->lexer);
	while (token != NULL && token->type != T_NEWLINE)
	{
		token = lexer_pop(parser->lexer);
		if ((token->type == T_SPACE && *token->raw != ' ')
			|| (token->type != T_SPACE && !token_is_map_token(token)))
		{
			parser_set_error(parser, "unexpected token in map");
			if (line)
				free(line);
			return (NULL);
		}
		line = ft_strjoin_s(line, ft_strdup(token->raw));
		if (line == NULL)
			return (NULL);
		token = lexer_peek(parser->lexer);
	}
	return (line);
}

bool	map_adjust_lines_width(t_map *map)
{
	char	*line;
	char	*new_line;
	size_t	line_width;
	size_t	diff;
	size_t	i;

	i = 0;
	if (map->raw == NULL)
		return (true);
	while (map->raw[i] != NULL)
	{
		line = map->raw[i];
		line_width = ft_strlen(line);
		diff = map->width - line_width;
		new_line = ft_calloc(line_width + diff + 1, sizeof(char));
		if (new_line == NULL)
			return (false);
		ft_strlcpy(new_line, line, line_width + 1);
		ft_memset(new_line + line_width, ' ', diff);
		free(line);
		map->raw[i] = new_line;
		++i;
	}
	return (true);
}

bool	map_add_line(t_parser *parser, t_map *map, char *line)
{
	if (line == NULL)
	{
		parser_set_error(parser, "failed to compose map");
		return (false);
	}
	map->width = ft_max(map->width, ft_strlen(line));
	map->raw = ft_realloc(map->raw,
			map->height * sizeof(char *),
			(map->height + 2) * sizeof(char *));
	map->raw[map->height] = line;
	map->raw[map->height + 1] = NULL;
	return (true);
}
