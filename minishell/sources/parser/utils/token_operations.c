/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:55:43 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 23:49:55 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "data.h"
#include "utils.h"
#include "libft.h"
#include "parser/token.h"

static t_token	*create_token(t_token_type token_type, char *content)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
	{
		ft_putendl_fd(MEMERR, STDERR_FILENO);
		return (NULL);
	}
	token->content = ft_strdup(content);
	if (token->content == NULL)
	{
		free(token);
		token = NULL;
		ft_putendl_fd(MEMERR, STDERR_FILENO);
		return (NULL);
	}
	token->type = token_type;
	token->next = NULL;
	return (token);
}

int	add_token_to_list(t_token **list, t_state state, char *buffer)
{
	t_token	*curr;
	t_token	*new_node;

	curr = NULL;
	new_node = create_token(get_token_type(state), buffer);
	if (new_node == NULL)
		return (EMALLOC);
	if (*list == NULL)
		*list = new_node;
	else
	{
		curr = *list;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = new_node;
	}
	return (OK);
}

void	delete_next_token(t_token *token)
{
	t_token	*curr;
	t_token	*next;

	curr = token;
	next = token->next;
	if (curr == NULL || next == NULL)
	{
		return ;
	}
	curr->next = next->next;
	protected_free(&next->content);
	free(next);
	next = NULL;
}

void	append_next_token(
	t_token *current_token,
	t_token *new_token
)
{
	t_token	*next_token;

	if (current_token == NULL)
	{
		return ;
	}
	next_token = current_token->next;
	new_token = create_token(new_token->type, new_token->content);
	if (new_token == NULL)
	{
		return ;
	}
	current_token->next = new_token;
	new_token->next = next_token;
}
