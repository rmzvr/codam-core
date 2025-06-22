/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:27:12 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/21 23:40:41 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/token.h"
#include "utils.h"
#include <stddef.h>

static int	is_heredoc_delimiter_token(t_token *token)
{
	if (token != NULL
		&& (token->type == NON_EXPANDABLE_HEREDOC_DELIMITER
			|| token->type == EXPANDABLE_HEREDOC_DELIMITER))
	{
		return (1);
	}
	return (0);
}

int	is_redirection_parameter(t_token *token)
{
	if (is_string_token(token) || is_heredoc_delimiter_token(token))
	{
		return (1);
	}
	return (0);
}

int	is_unexpected_token(t_token *token)
{
	if (is_redirection_token(token) || is_pipe_token(token))
	{
		return (1);
	}
	return (0);
}
