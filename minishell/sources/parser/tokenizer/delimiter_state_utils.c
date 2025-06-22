/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiter_state_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:33:44 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/21 23:43:33 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/state.h"
#include "utils.h"
#include "parser/buffer_utils.h"
#include "parser/char_helpers.h"

t_state	handle_delimiter(
	char **buffer,
	char curr_char,
	char next_char,
	size_t *i
)
{
	t_state	state;

	state = DL;
	if (!is_delimiter(next_char))
	{
		state = T_DL;
	}
	if (add_char_to_buffer(buffer, curr_char) == EMALLOC)
	{
		return (ERROR);
	}
	*i += 1;
	return (state);
}
