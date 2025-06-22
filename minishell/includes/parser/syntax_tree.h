/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:37:52 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 23:40:41 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_TREE_H
# define SYNTAX_TREE_H

# include "parser/token.h"

typedef struct s_command	t_command;
typedef struct s_options	t_options;
typedef struct s_pipeline	t_pipeline;

typedef union u_child_type
{
	t_command	*command;
	t_pipeline	*pipeline;
}	t_child_type;

typedef enum e_node_type
{
	PIPELINE,
	COMMAND,
	ARGUMENT,
	REDIRECTION,
	MERROR
}	t_node_type;

typedef struct s_options
{
	t_node_type		node_type;
	t_token_type	token_type;
	char			*content;
	t_options		*next;
}	t_options;

typedef struct s_command
{
	t_node_type	node_type;
	t_options	*arguments;
	t_options	*redirections;
}	t_command;

typedef struct s_child
{
	t_child_type	type;
	t_node_type		kind;
}	t_child;

typedef struct s_pipeline
{
	t_node_type	node_type;
	t_child		left_child;
	t_child		right_child;
}	t_pipeline;

typedef struct s_syntax_tree
{
	t_command	*command;
	t_pipeline	*pipeline;
	t_options	*arguments;
	t_options	*redirections;
	t_child		left_child;
	t_child		right_child;
}	t_syntax_tree;

t_command	*create_command(void);
t_child		create_command_branch(t_syntax_tree tree_data);
t_child		create_pipeline_branch(
				t_syntax_tree tree_data, t_token *tokens);
t_options	*create_option(t_token_type token_type,
				char *content, t_node_type node_type);
t_child		create_syntax_tree(t_token *tokens);
int			handle_options(t_options **options, t_token *token,
				t_options *(*creator)(t_token_type token_type,
					char *content, t_node_type node_type),
				t_node_type node_type);

t_child		free_data_and_return_merror_child(t_syntax_tree tree_data);

#endif