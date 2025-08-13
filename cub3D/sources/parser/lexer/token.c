/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/24 11:15:03 by bamarell      #+#    #+#                 */
/*   Updated: 2025/07/24 11:15:03 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser/lexer.h"

static
t_token_type	get_token_type(const char *raw)
{
	if (!ft_strcmp(raw, "NO"))
		return (T_TX_NO);
	if (!ft_strcmp(raw, "SO"))
		return (T_TX_SO);
	if (!ft_strcmp(raw, "WE"))
		return (T_TX_WE);
	if (!ft_strcmp(raw, "EA"))
		return (T_TX_EA);
	if (!ft_strcmp(raw, "\n"))
		return (T_NEWLINE);
	if (!ft_strcmp(raw, "F"))
		return (T_FC);
	if (!ft_strcmp(raw, "C"))
		return (T_CC);
	if (!ft_strcmp(raw, ","))
		return (T_COMMA);
	if (!ft_strcmp(raw, " ") || !ft_strcmp(raw, "\t") || !ft_strcmp(raw, "\v")
		|| !ft_strcmp(raw, "\f") || !ft_strcmp(raw, "\r"))
		return (T_SPACE);
	return (T_WORD);
}

t_token	*lexer_create_token(char *raw)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->type = get_token_type(raw);
	token->raw = raw;
	return (token);
}

t_token	*lexer_append_token(t_lexer *lexer, char *raw)
{
	t_token	*token;
	t_list	*node;

	token = lexer_create_token(raw);
	if (token == NULL)
		return (NULL);
	node = ft_lstnew(token);
	if (node == NULL)
	{
		lexer_destroy_token(token);
		return (NULL);
	}
	ft_lstadd_back(&lexer->tokens, node);
	return (token);
}

void	lexer_destroy_token(t_token *token)
{
	if (token == NULL)
		return ;
	if (token->raw != NULL)
		free(token->raw);
	free(token);
}
