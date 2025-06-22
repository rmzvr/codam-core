/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:48:47 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/21 23:41:22 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "parser/state.h"

void	initialize_tokenizer(t_state_data *tokenizer);

void	reset_state_to_start(t_state *state);

int		is_evaluator_accept_state(t_state state);

int		is_heredoc_accept_state(t_state state);

int		is_scanner_accept_state(t_state state);

int		handle_accept_state(
			t_state *curr_state, char **buffer, t_token **tokens);

t_state	handle_evaluator_start_state(char curr_char);

t_state	handle_scanner_start_state(char curr_char);

t_state	handle_heredoc_start_state(char curr_char);

int		handle_evaluator_intermediate_state(
			t_state *curr_state, char **buffer, size_t *i, char *input);

int		handle_heredoc_intermediate_state(
			t_state *curr_state, char **buffer, size_t *i, char *input);

int		handle_scanner_intermediate_state(
			t_state *curr_state, char **buffer, size_t *i, char *input);

t_state	handle_env_variable(
			char **buffer, char curr_char, char next_char, size_t *i);

t_state	handle_evaluator_string(
			char **buffer, char curr_char, char next_char, size_t *i);

t_state	handle_heredoc_string(
			char **buffer, char curr_char, char next_char, size_t *i);

t_state	handle_scanner_string(
			char **buffer, char curr_char, char next_char, size_t *i);

t_state	handle_delimiter(
			char **buffer, char curr_char, char next_char, size_t *i);

#endif