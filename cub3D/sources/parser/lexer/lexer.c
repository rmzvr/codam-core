/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/24 11:14:58 by bamarell      #+#    #+#                 */
/*   Updated: 2025/07/24 11:14:58 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser/lexer.h"

t_lexer	*lexer_create(const char *str)
{
	t_lexer	*lexer;

	lexer = ft_calloc(1, sizeof(t_lexer));
	if (lexer == NULL)
		return (NULL);
	lexer->buf = ft_strdup(str);
	if (lexer->buf == NULL)
	{
		lexer_destroy(lexer);
		return (NULL);
	}
	return (lexer);
}

void	lexer_destroy(t_lexer *lexer)
{
	if (lexer == NULL)
		return ;
	if (lexer->buf != NULL)
		free(lexer->buf);
	if (lexer->tokens != NULL)
		ft_lstclear(&lexer->tokens,
			(void (*)(void *)) lexer_destroy_token);
	if (lexer->error != NULL)
		free(lexer->error);
	free(lexer);
}

static
ssize_t	get_token_length(t_lexer *lexer)
{
	char	*buf;

	buf = lexer->buf + lexer->pos;
	if (!ft_strncmp(buf, "NO", 2) || !ft_strncmp(buf, "SO", 2)
		|| !ft_strncmp(buf, "WE", 2) || !ft_strncmp(buf, "EA", 2))
		return (2);
	if (!ft_strncmp(buf, " ", 1) || !ft_strncmp(buf, "\t", 1)
		|| !ft_strncmp(buf, "\r", 1) || !ft_strncmp(buf, "\v", 1)
		|| !ft_strncmp(buf, "\f", 1) || !ft_strncmp(buf, "\n", 1)
		|| !ft_strncmp(buf, "C", 1) || !ft_strncmp(buf, "F", 1)
		|| !ft_strncmp(buf, ",", 1))
		return (1);
	return (get_word_length(lexer));
}

void	lexer_set_error(t_lexer *lexer, const char *message)
{
	if (message != NULL && lexer->error == NULL)
		lexer->error = ft_strdup(message);
	else if (message == NULL)
	{
		if (lexer->error != NULL)
			free(lexer->error);
		lexer->error = NULL;
	}
}

bool	lexer_tokenize(t_lexer *lexer)
{
	ssize_t		token_length;
	char		*sub;

	token_length = 0;
	while (lexer->buf[lexer->pos] != '\0')
	{
		token_length = get_token_length(lexer);
		if (token_length == -1)
			return (false);
		if (token_length > 0)
		{
			sub = ft_substr(lexer->buf, lexer->pos, token_length);
			if (sub == NULL || !lexer_append_token(lexer, sub))
				return (false);
			lexer->pos += token_length;
		}
		else
			++lexer->pos;
	}
	lexer->current_token = lexer->tokens;
	return (lexer->error == NULL);
}
