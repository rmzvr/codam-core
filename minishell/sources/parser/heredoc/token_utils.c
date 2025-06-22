/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:53:01 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 23:40:41 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/token.h"
#include "utils.h"

static int	is_heredoc_token(t_token *token)
{
	if (token->type == DLESS
		|| token->type == EXPANDABLE_HEREDOC
		|| token->type == NON_EXPANDABLE_HEREDOC)
	{
		return (1);
	}
	return (0);
}

t_token	*find_heredoc_token(t_token *token)
{
	while (token != NULL)
	{
		if (is_heredoc_token(token))
		{
			return (token);
		}
		token = token->next;
	}
	return (NULL);
}
