/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:03:29 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 23:53:58 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "parser/state.h"

typedef struct s_token	t_token;

typedef enum e_token_type
{
	STRING,
	LESS,
	GREAT,
	DLESS,
	DGREAT,
	PIPE,
	VARIABLE,
	EXIT_STATUS,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	DELIMITER,
	HEREDOC,
	EXPANDABLE_HEREDOC,
	NON_EXPANDABLE_HEREDOC,
	EXPANDABLE_HEREDOC_DELIMITER,
	NON_EXPANDABLE_HEREDOC_DELIMITER,
	NONE
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*content;
	t_token			*next;
}	t_token;

int				is_pipe_token(t_token *token);
int				is_quote_token(t_token *token);
int				is_string_token(t_token *token);
int				is_variable_token(t_token *token);
int				is_delimiter_token(t_token *token);
int				is_exit_status_token(t_token *token);
int				is_redirection_token(t_token *token);
int				is_concatenable_token(t_token *token);

t_token_type	get_token_type(t_state state);
void			delete_next_token(t_token *token);
void			append_next_token(t_token *current_token, t_token *new_token);
int				add_token_to_list(t_token **list, t_state state, char *buffer);

#endif