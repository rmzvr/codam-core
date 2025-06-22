/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:04:06 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/21 23:40:41 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/token.h"

t_token_type	get_token_type(t_state state)
{
	if (state == T_STR)
		return (STRING);
	else if (state == T_EV)
		return (VARIABLE);
	else if (state == T_ES)
		return (EXIT_STATUS);
	else if (state == T_SQ)
		return (SINGLE_QUOTE);
	else if (state == T_DQ)
		return (DOUBLE_QUOTE);
	else if (state == T_GS)
		return (GREAT);
	else if (state == T_DGS)
		return (DGREAT);
	else if (state == T_LS)
		return (LESS);
	else if (state == T_DLS)
		return (DLESS);
	else if (state == T_P)
		return (PIPE);
	else if (state == T_DL)
		return (DELIMITER);
	return (NONE);
}

int	is_redirection_token(t_token *token)
{
	if (token->type == LESS
		|| token->type == DLESS
		|| token->type == GREAT
		|| token->type == DGREAT)
	{
		return (1);
	}
	return (0);
}

int	is_quote_token(t_token *token)
{
	if (token != NULL
		&& (token->type == SINGLE_QUOTE || token->type == DOUBLE_QUOTE))
	{
		return (1);
	}
	return (0);
}

int	is_concatenable_token(t_token *token)
{
	if (is_string_token(token)
		|| is_quote_token(token)
		|| is_variable_token(token)
		|| is_exit_status_token(token))
	{
		return (1);
	}
	return (0);
}
