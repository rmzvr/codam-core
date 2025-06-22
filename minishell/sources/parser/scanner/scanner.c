/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:04 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 23:41:19 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser/scanner.h"
#include "parser/tokenizer.h"

int	assign_tokens(
	t_token **tokens,
	char *input
)
{
	size_t			str_len;
	t_state_data	tokenizer;

	str_len = ft_strlen(input);
	initialize_tokenizer(&tokenizer);
	if (str_len > 0)
	{
		tokenizer.buffer = ft_strdup("");
		if (tokenizer.buffer == NULL)
			return (print_merror_and_return_code(EMALLOC));
	}
	while (tokenizer.i < str_len)
	{
		if (handle_scanner_intermediate_state(&tokenizer.state,
				&tokenizer.buffer, &tokenizer.i, input) == EMALLOC)
			return (free_and_return_code(&tokenizer.buffer, EMALLOC));
		if (is_scanner_accept_state(tokenizer.state))
		{
			if (handle_accept_state(
					&tokenizer.state, &tokenizer.buffer, tokens) == EMALLOC)
				return (free_and_return_code(&tokenizer.buffer, EMALLOC));
		}
	}
	return (free_and_return_code(&tokenizer.buffer, OK));
}
