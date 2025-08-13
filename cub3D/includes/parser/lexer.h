/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/24 11:17:22 by bamarell      #+#    #+#                 */
/*   Updated: 2025/07/24 11:17:22 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"

# define ALLOWED_RAW_MAP_TOKENS "10NSEW"

typedef enum e_token_type
{
	// ` \t\v\f\r`
	T_SPACE,
	// ,
	T_COMMA,
	// \n
	T_NEWLINE,
	// NO
	T_TX_NO,
	// SO
	T_TX_SO,
	// WE
	T_TX_WE,
	// EA
	T_TX_EA,
	// F
	T_FC,
	// C
	T_CC,
	T_WORD,
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*raw;
}	t_token;

typedef struct s_lexer
{
	char	*buf;
	char	*error;
	size_t	pos;
	t_list	*tokens; /* t_token */
	t_list	*current_token; /* t_token */
}	t_lexer;

t_lexer	*lexer_create(const char *buf);
void	lexer_set_error(t_lexer *lexer, const char *message);
void	lexer_destroy(t_lexer *lexer);
bool	lexer_tokenize(t_lexer *lexer);

ssize_t	get_word_length(t_lexer *lexer);

bool	token_is_texture(t_token *token);
bool	token_is_color(t_token *token);
bool	token_is_map_token(t_token *token);

t_token	*lexer_peek(t_lexer *lexer);
t_token	*lexer_peek_ahead(t_list *raw_token, size_t offset);
t_token	*lexer_pop(t_lexer *lexer);

t_token	*lexer_create_token(char *raw);
t_token	*lexer_append_token(t_lexer *lexer, char *raw);
void	lexer_destroy_token(t_token *token);
t_token	*lexer_copy_token(t_token *token);
#endif
