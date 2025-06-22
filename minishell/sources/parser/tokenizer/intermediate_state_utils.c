/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intermediate_state_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:40:31 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/21 23:41:19 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser/state.h"
#include "parser/scanner.h"
#include "parser/tokenizer.h"

int	handle_evaluator_intermediate_state(
	t_state *curr_state,
	char **buffer,
	size_t *i,
	char *input
)
{
	char	curr_char;
	char	next_char;

	curr_char = input[*i];
	next_char = input[*i + 1];
	if (*curr_state == S)
		*curr_state = handle_evaluator_start_state(curr_char);
	else if (*curr_state == STR)
		*curr_state = handle_evaluator_string(buffer, curr_char, next_char, i);
	else if (*curr_state == DL)
		*curr_state = handle_delimiter(buffer, curr_char, next_char, i);
	if (*curr_state == ERROR)
		return (EMALLOC);
	return (OK);
}

int	handle_heredoc_intermediate_state(
	t_state *curr_state,
	char **buffer,
	size_t *i,
	char *input
)
{
	char	curr_char;
	char	next_char;

	curr_char = input[*i];
	next_char = input[*i + 1];
	if (*curr_state == S)
		*curr_state = handle_heredoc_start_state(curr_char);
	else if (*curr_state == STR)
		*curr_state = handle_heredoc_string(buffer, curr_char, next_char, i);
	else if (*curr_state == DS)
		*curr_state = handle_dollar_symbol(buffer, curr_char, next_char, i);
	else if (*curr_state == EV)
		*curr_state = handle_env_variable(buffer, curr_char, next_char, i);
	if (*curr_state == ERROR)
		return (EMALLOC);
	return (OK);
}

int	handle_scanner_intermediate_state(
	t_state *curr_state,
	char **buffer,
	size_t *i,
	char *input
)
{
	if (*curr_state == S)
		*curr_state = handle_scanner_start_state(input[*i]);
	else if (*curr_state == P)
		*curr_state = handle_pipe_symbol(buffer, input[*i], i);
	else if (*curr_state == DQ)
		*curr_state = handle_double_quote(buffer, input[*i], i);
	else if (*curr_state == SQ)
		*curr_state = handle_single_quote(buffer, input[*i], i);
	else if (*curr_state == STR)
		*curr_state = handle_scanner_string(
				buffer, input[*i], input[*i + 1], i);
	else if (*curr_state == DL)
		*curr_state = handle_delimiter(buffer, input[*i], input[*i + 1], i);
	else if (*curr_state == LS)
		*curr_state = handle_less_symbol(buffer, input[*i], input[*i + 1], i);
	else if (*curr_state == GS)
		*curr_state = handle_great_symbol(buffer, input[*i], input[*i + 1], i);
	else if (*curr_state == DS)
		*curr_state = handle_dollar_symbol(buffer, input[*i], input[*i + 1], i);
	else if (*curr_state == EV)
		*curr_state = handle_env_variable(buffer, input[*i], input[*i + 1], i);
	if (*curr_state == ERROR)
		return (EMALLOC);
	return (OK);
}
