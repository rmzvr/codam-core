/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   word.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/24 11:15:07 by bamarell      #+#    #+#                 */
/*   Updated: 2025/07/24 11:15:07 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser/lexer.h"

ssize_t	get_word_length(t_lexer *lexer)
{
	char	*buf;
	size_t	i;

	i = 0;
	buf = lexer->buf + lexer->pos;
	while (buf[i] != '\0')
	{
		if (ft_isspace(buf[i]) || buf[i] == ',')
			break ;
		++i;
	}
	return (i);
}

bool	token_is_texture(t_token *token)
{
	if (token == NULL)
		return (false);
	return (token->type == T_TX_NO
		|| token->type == T_TX_SO
		|| token->type == T_TX_WE
		|| token->type == T_TX_EA);
}

bool	token_is_color(t_token *token)
{
	if (token == NULL)
		return (false);
	return (token->type == T_FC || token->type == T_CC);
}

static
bool	is_map_string(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(ALLOWED_RAW_MAP_TOKENS, str[i]) == NULL)
			return (false);
		++i;
	}
	return (true);
}

bool	token_is_map_token(t_token *token)
{
	if (token == NULL || token->type != T_WORD)
		return (false);
	return (is_map_string(token->raw));
}
