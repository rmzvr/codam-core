/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:14:41 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/21 23:39:55 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVALUATOR_H
# define EVALUATOR_H

# include "data.h"

int		concatenate_tokens(t_data *data);
int		evaluate_redirection_tokens(t_token *token);
char	*get_exit_code(t_token **current_token, t_data *data);
char	*get_expanded_variable(t_token **current_token, t_data *data);

int		is_unexpected_token(t_token *token);
int		is_redirection_parameter(t_token *token);

char	*append_exit_code_to_buffer(
			t_token *token, char **buffer, t_data *data);

char	*append_variable_to_buffer(
			t_token *token, char **buffer, t_data *data);

char	*append_quoted_token_to_buffer(
			t_token *token, char **buffer, t_data *data);

int		process_environment_variable(t_token *token, int is_next, t_data *data);

int		process_quotes(t_token *token, int is_next, t_data *data);

int		process_exit_code(t_token *token, int is_next, t_data *data);

char	*concatenate_non_expandable_tokens(
			t_token *token, int tokens_count, t_data *data);

int		handle_quoted_tokens(t_token **tokens, char *(*concatenator)(
				t_token *token,
				int tokens_count,
				t_data *data
				), char **buffer, t_data *data);

int		handle_unclosed_quotes_heredoc(char **buffer, t_token *token);
char	*handle_empty_quotes(t_token *token);
int		check_tokens_count(t_token *token, char **buffer, int tokens_count);
int		handle_unclosed_quotes_heredoc(char **buffer, t_token *token);

int		evaluate_tokens(t_data *data);

int		validate_syntax(t_token *token);

#endif