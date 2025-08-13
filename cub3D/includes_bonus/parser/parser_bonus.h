/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:17:20 by bamarell          #+#    #+#             */
/*   Updated: 2025/07/24 13:40:38 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_BONUS_H
# define PARSER_BONUS_H

# include "parser/ast_bonus.h"

/* Allow the overriding of texture / color elements */
# define ALLOW_ELEMENT_OVERRIDE false
/* Allow the overriding of spawn, the last token will take priority */
# define ALLOW_SPAWN_OVERRIDE false

# define SPAWN_CHARSET "NSEW"

# define MIN_MAP_WIDTH 2
# define MIN_MAP_HEIGHT 2

typedef struct s_parser
{
	t_lexer	*lexer;
	char	*error;
}	t_parser;

t_parser		*parser_create(t_lexer *lexer);
t_root			*parser_parse(t_parser *parser);
void			parser_set_error(t_parser *parser, const char *message);
void			parser_destroy(t_parser *parser);

t_root			*parser_parse_root(t_parser *parser);
void			parser_destroy_root(t_root *root);
bool			parser_validate_root(t_parser *parser, t_root *root);

bool			parse_root_header(t_parser *parser, t_root *root);
bool			is_root_header_complete(t_root *root);

bool			root_assign_texture(t_parser *parser, t_root *root,
					t_ast_texture *texture);
bool			root_assign_color(t_parser *parser, t_root *root,
					t_color *color);

bool			parse_root_map(t_parser *parser, t_root *root);
void			parser_destroy_map(t_map *map);
bool			is_root_map_complete(t_root *root);

bool			is_first_map_line(t_parser *parser);
char			*consume_line_tokens(t_parser *parser);
bool			map_adjust_lines_width(t_map *map);
bool			map_add_line(t_parser *parser, t_map *map, char *line);

bool			parse_map_positions(t_parser *parser, t_root *root);

t_ast_texture	*parser_parse_texture(t_parser *parser);
void			parser_destroy_texture(t_ast_texture *texture);

t_color			*parser_parse_color(t_parser *parser);
void			parser_destroy_color(t_color *color);

void			parser_skip_spaces(t_parser *parser);
void			parser_skip_tokens(t_parser *parser, t_token_type type);
bool			parser_is_line_empty(t_parser *parser);
void			parser_skip_line_if_empty(t_parser *parser);

bool			is_map_bordered(t_map *map);
#endif
