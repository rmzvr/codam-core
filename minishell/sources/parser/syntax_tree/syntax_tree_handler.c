/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tree_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:04:23 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 23:24:46 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	initialize_tree_data(
	t_syntax_tree *tree_data
)
{
	tree_data->command = NULL;
	tree_data->pipeline = NULL;
	tree_data->arguments = NULL;
	tree_data->redirections = NULL;
	tree_data->left_child.kind = COMMAND;
	tree_data->left_child.type.command = NULL;
	tree_data->right_child.kind = PIPELINE;
	tree_data->right_child.type.pipeline = NULL;
}

t_child	free_data_and_return_merror_child(
	t_syntax_tree tree_data
)
{
	if (tree_data.arguments != NULL)
	{
		free_options(&tree_data.arguments);
	}
	if (tree_data.redirections != NULL)
	{
		free_options(&tree_data.redirections);
	}
	tree_data.left_child.kind = MERROR;
	return (tree_data.left_child);
}

t_child	create_syntax_tree(
	t_token *tokens
)
{
	t_syntax_tree	tree_data;

	initialize_tree_data(&tree_data);
	while (tokens != NULL)
	{
		if (is_string_token(tokens))
		{
			if (handle_options(&tree_data.arguments, tokens,
					&create_option, ARGUMENT) == EMALLOC)
				return (free_data_and_return_merror_child(tree_data));
		}
		else if (is_redirection_token(tokens))
		{
			if (handle_options(&tree_data.redirections, tokens,
					&create_option, REDIRECTION) == EMALLOC)
				return (free_data_and_return_merror_child(tree_data));
		}
		if (tokens->next == NULL)
			return (create_command_branch(tree_data));
		else if (is_pipe_token(tokens))
			return (create_pipeline_branch(tree_data, tokens));
		tokens = tokens->next;
	}
	return (tree_data.left_child);
}
