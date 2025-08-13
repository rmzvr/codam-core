/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ast.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/24 11:17:26 by bamarell      #+#    #+#                 */
/*   Updated: 2025/07/24 11:17:27 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include <stdint.h>

# include "libft/math/vec2.h"
# include "parser/lexer.h"

typedef enum e_node_type
{
	T_ROOT,
	T_TEXTURE,
	T_COLOR,
	T_MAP,
}	t_node_type;

typedef struct s_node
{
	t_node_type	node_type;
}	t_node;

typedef struct s_ast_texture
{
	t_node_type		node_type; /* T_TEXTURE */
	t_token_type	type; /* T_TX_NO, T_TX_SO, T_TX_WE, T_TX_EA */
	char			*path;
}	t_ast_texture;

typedef struct s_color
{
	t_node_type		node_type; /* T_COLOR */
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
	t_token_type	type; /* T_FC, T_CC */
}	t_color;

typedef struct s_map
{
	size_t	width;
	size_t	height;
	t_vec2	spawn;
	char	spawn_dir; /* N, S, W, E */
	char	**raw;
}	t_map;

typedef struct s_root
{
	t_node_type		node_type;
	t_map			*map;
	t_ast_texture	*north_tx;
	t_ast_texture	*east_tx;
	t_ast_texture	*south_tx;
	t_ast_texture	*west_tx;
	t_color			*floor_c;
	t_color			*ceiling_c;
}	t_root;
#endif
