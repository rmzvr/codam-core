/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:19:36 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 23:40:41 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCANNER_H
# define SCANNER_H

# include "parser/state.h"
# include "parser/token.h"

typedef struct s_scanner
{
	size_t	i;
	t_state	state;
	char	*buffer;
}	t_scanner;

t_state	handle_single_quote(char **buffer, char curr_char, size_t *i);

t_state	handle_double_quote(char **buffer, char curr_char, size_t *i);

t_state	handle_pipe_symbol(char **buffer, char curr_char, size_t *i);

t_state	handle_less_symbol(
			char **buffer, char curr_char, char next_char, size_t *i);

t_state	handle_great_symbol(
			char **buffer, char curr_char, char next_char, size_t *i);

t_state	handle_dollar_symbol(
			char **buffer, char curr_char, char next_char, size_t *i);

int		assign_tokens(t_token **tokens, char *str);

#endif