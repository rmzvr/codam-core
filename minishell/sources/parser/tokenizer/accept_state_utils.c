/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accept_state_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:47:15 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/21 23:42:45 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser/state.h"
#include "parser/token.h"
#include "parser/buffer_utils.h"

void	reset_state_to_start(
	t_state *state
)
{
	*state = S;
}

int	is_evaluator_accept_state(
	t_state state
)
{
	if (state == T_STR || state == T_DL)
	{
		return (1);
	}
	return (0);
}

int	is_heredoc_accept_state(
	t_state state
)
{
	if (
		state == T_STR
		|| state == T_EV
		|| state == T_ES
	)
		return (1);
	return (0);
}

int	is_scanner_accept_state(
	t_state state
)
{
	if (state == T_STR
		|| state == T_EV
		|| state == T_ES
		|| state == T_SQ
		|| state == T_DQ
		|| state == T_GS
		|| state == T_DGS
		|| state == T_LS
		|| state == T_DLS
		|| state == T_P
		|| state == T_DL)
		return (1);
	return (0);
}

int	handle_accept_state(
	t_state *curr_state,
	char **buffer,
	t_token **tokens
)
{
	if (add_token_to_list(tokens, *curr_state, *buffer) == EMALLOC)
	{
		return (EMALLOC);
	}
	if (clean_buffer(buffer) == EMALLOC)
	{
		return (EMALLOC);
	}
	reset_state_to_start(curr_state);
	return (OK);
}
