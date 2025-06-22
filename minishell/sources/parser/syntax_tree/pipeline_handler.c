/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:53:38 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 23:40:41 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser/token.h"
#include <unistd.h>

static t_pipeline	*create_pipeline(t_child right_child)
{
	t_pipeline	*pipeline;

	pipeline = malloc(sizeof(t_pipeline));
	if (pipeline == NULL)
	{
		return (ft_putendl_fd(MEMERR, STDERR_FILENO), NULL);
	}
	pipeline->node_type = PIPELINE;
	pipeline->left_child.kind = COMMAND;
	pipeline->left_child.type.command = NULL;
	pipeline->right_child.kind = right_child.kind;
	if (right_child.kind == COMMAND)
	{
		pipeline->right_child.type.command = right_child.type.command;
	}
	else if (right_child.kind == PIPELINE)
	{
		pipeline->right_child.type.pipeline = right_child.type.pipeline;
	}
	return (pipeline);
}

static t_child	free_command_and_return_merror_child(
	t_syntax_tree tree_data
)
{
	free_options(&tree_data.command->arguments);
	free_options(&tree_data.command->redirections);
	free(tree_data.command);
	tree_data.left_child.kind = MERROR;
	return (tree_data.left_child);
}

t_child	create_pipeline_branch(
	t_syntax_tree tree_data,
	t_token *tokens
)
{
	tree_data.command = create_command();
	if (tree_data.command == NULL)
	{
		return (free_data_and_return_merror_child(tree_data));
	}
	tree_data.command->arguments = tree_data.arguments;
	tree_data.command->redirections = tree_data.redirections;
	tree_data.right_child = create_syntax_tree(tokens->next);
	if (tree_data.right_child.kind == MERROR)
	{
		return (free_command_and_return_merror_child(tree_data));
	}
	tree_data.pipeline = create_pipeline(tree_data.right_child);
	if (tree_data.pipeline == NULL)
	{
		free_ast(tree_data.right_child);
		return (free_command_and_return_merror_child(tree_data));
	}
	tree_data.pipeline->left_child.kind = COMMAND;
	tree_data.pipeline->left_child.type.command = tree_data.command;
	tree_data.left_child.kind = PIPELINE;
	tree_data.left_child.type.pipeline = tree_data.pipeline;
	return (tree_data.left_child);
}
