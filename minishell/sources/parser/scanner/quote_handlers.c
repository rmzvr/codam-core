/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:31:26 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 23:42:45 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser/buffer_utils.h"

t_state	handle_single_quote(
	char **buffer,
	char curr_char,
	size_t *i
)
{
	t_state	state;

	state = T_SQ;
	if (add_char_to_buffer(buffer, curr_char) == EMALLOC)
	{
		return (ERROR);
	}
	*i += 1;
	return (state);
}

t_state	handle_double_quote(
	char **buffer,
	char curr_char,
	size_t *i
)
{
	t_state	state;

	state = T_DQ;
	if (add_char_to_buffer(buffer, curr_char) == EMALLOC)
	{
		return (ERROR);
	}
	*i += 1;
	return (state);
}
