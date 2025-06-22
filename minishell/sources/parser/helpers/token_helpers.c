/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:45:17 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 23:40:41 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/token.h"
#include <stddef.h>

int	is_pipe_token(t_token *token)
{
	if (token != NULL && token->type == PIPE)
	{
		return (1);
	}
	return (0);
}

int	is_delimiter_token(t_token *token)
{
	if (token != NULL && token->type == DELIMITER)
	{
		return (1);
	}
	return (0);
}

int	is_string_token(t_token *token)
{
	if (token != NULL && token->type == STRING)
	{
		return (1);
	}
	return (0);
}

int	is_exit_status_token(t_token *token)
{
	if (token != NULL && token->type == EXIT_STATUS)
	{
		return (1);
	}
	return (0);
}

int	is_variable_token(t_token *token)
{
	if (token != NULL && token->type == VARIABLE)
	{
		return (1);
	}
	return (0);
}
