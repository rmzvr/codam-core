/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:57:50 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 23:43:33 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser/buffer_utils.h"
#include "parser/char_helpers.h"

t_state	handle_pipe_symbol(
	char **buffer,
	char curr_char,
	size_t *i
)
{
	t_state	state;

	state = T_P;
	if (add_char_to_buffer(buffer, curr_char) == EMALLOC)
	{
		return (ERROR);
	}
	*i += 1;
	return (state);
}

t_state	handle_less_symbol(
	char **buffer,
	char curr_char,
	char next_char,
	size_t *i
)
{
	t_state	state;

	if (add_char_to_buffer(buffer, curr_char) == EMALLOC)
	{
		return (ERROR);
	}
	if (next_char == '<')
	{
		state = T_DLS;
		if (add_char_to_buffer(buffer, next_char) == EMALLOC)
		{
			return (ERROR);
		}
		*i += 2;
	}
	else
	{
		state = T_LS;
		*i += 1;
	}
	return (state);
}

t_state	handle_great_symbol(
	char **buffer,
	char curr_char,
	char next_char,
	size_t *i
)
{
	t_state	state;

	if (add_char_to_buffer(buffer, curr_char) == EMALLOC)
	{
		return (ERROR);
	}
	if (next_char == '>')
	{
		state = T_DGS;
		if (add_char_to_buffer(buffer, next_char) == EMALLOC)
		{
			return (ERROR);
		}
		*i += 2;
	}
	else
	{
		state = T_GS;
		*i += 1;
	}
	return (state);
}

t_state	handle_dollar_symbol(
	char **buffer,
	char curr_char,
	char next_char,
	size_t *i
)
{
	t_state	state;

	if (add_char_to_buffer(buffer, curr_char) == EMALLOC)
	{
		return (ERROR);
	}
	*i += 1;
	if (next_char == '?')
	{
		state = T_ES;
		if (add_char_to_buffer(buffer, next_char) == EMALLOC)
		{
			return (ERROR);
		}
		*i += 1;
	}
	else if (is_null_terminator(next_char))
		state = T_STR;
	else if (is_metacharacter(next_char))
		state = T_EV;
	else if (is_valid_char(next_char) && !ft_isdigit(next_char))
		state = EV;
	else
		state = STR;
	return (state);
}
