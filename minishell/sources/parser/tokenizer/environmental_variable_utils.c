/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environmental_variable_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:56:30 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/21 23:43:33 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser/state.h"
#include "parser/buffer_utils.h"
#include "parser/char_helpers.h"

t_state	handle_env_variable(
	char **buffer,
	char curr_char,
	char next_char,
	size_t *i
)
{
	t_state	state;

	state = EV;
	if (is_metacharacter(next_char)
		|| is_delimiter(next_char)
		|| is_null_terminator(next_char)
		|| (!is_valid_char(next_char) && !ft_isdigit(next_char))
	)
	{
		state = T_EV;
	}
	if (add_char_to_buffer(buffer, curr_char) == EMALLOC)
	{
		return (ERROR);
	}
	*i += 1;
	return (state);
}
