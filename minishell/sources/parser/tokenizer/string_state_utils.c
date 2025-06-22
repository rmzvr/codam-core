/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_state_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:22:32 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/21 23:43:33 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser/state.h"
#include "parser/buffer_utils.h"
#include "parser/char_helpers.h"

t_state	handle_evaluator_string(
	char **buffer,
	char curr_char,
	char next_char,
	size_t *i
)
{
	t_state	state;

	if (is_delimiter(next_char) || is_null_terminator(next_char))
	{
		state = T_STR;
	}
	else
	{
		state = STR;
	}
	if (add_char_to_buffer(buffer, curr_char) == EMALLOC)
	{
		return (ERROR);
	}
	*i += 1;
	return (state);
}

t_state	handle_heredoc_string(
	char **buffer,
	char curr_char,
	char next_char,
	size_t *i
)
{
	t_state	state;

	if (next_char == '$' || is_null_terminator(next_char))
	{
		state = T_STR;
	}
	else
	{
		state = STR;
	}
	if (add_char_to_buffer(buffer, curr_char) == EMALLOC)
	{
		return (ERROR);
	}
	*i += 1;
	return (state);
}

t_state	handle_scanner_string(
	char **buffer,
	char curr_char,
	char next_char,
	size_t *i
)
{
	t_state	state;

	if (is_delimiter(next_char)
		|| is_metacharacter(next_char)
		|| is_null_terminator(next_char))
	{
		state = T_STR;
	}
	else
	{
		state = STR;
	}
	if (add_char_to_buffer(buffer, curr_char) == EMALLOC)
	{
		return (ERROR);
	}
	*i += 1;
	return (state);
}
