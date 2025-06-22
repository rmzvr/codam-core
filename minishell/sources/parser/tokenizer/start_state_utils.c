/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_state_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:08:46 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/21 23:43:33 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/state.h"
#include "parser/char_helpers.h"

t_state	handle_evaluator_start_state(
	char curr_char
)
{
	t_state	state;

	if (is_delimiter(curr_char))
	{
		state = DL;
	}
	else
	{
		state = STR;
	}
	return (state);
}

t_state	handle_scanner_start_state(
	char curr_char
)
{
	t_state	state;

	if (is_delimiter(curr_char))
		state = DL;
	else if (curr_char == '|')
		state = P;
	else if (curr_char == '<')
		state = LS;
	else if (curr_char == '>')
		state = GS;
	else if (curr_char == '$')
		state = DS;
	else if (curr_char == '\'')
		state = SQ;
	else if (curr_char == '\"')
		state = DQ;
	else
		state = STR;
	return (state);
}

t_state	handle_heredoc_start_state(
	char curr_char
)
{
	t_state	state;

	if (curr_char == '$')
	{
		state = DS;
	}
	else
	{
		state = STR;
	}
	return (state);
}
