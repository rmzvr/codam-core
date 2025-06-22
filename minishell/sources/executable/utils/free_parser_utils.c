/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:10:02 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/18 20:06:42 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd/exec_cmd.h"

void	free_tokens(t_token **tokens)
{
	t_token	*curr;
	t_token	*next;

	curr = *tokens;
	while (curr != NULL)
	{
		next = curr->next;
		if (curr != NULL)
		{
			protected_free(&curr->content);
			free(curr);
			curr = NULL;
		}
		curr = next;
	}
	*tokens = NULL;
}

void	free_options(t_options **options)
{
	t_options	*curr;
	t_options	*next;

	curr = *options;
	while (curr != NULL)
	{
		next = curr->next;
		protected_free(&curr->content);
		if (curr != NULL)
		{
			free(curr);
			curr = NULL;
		}
		curr = next;
	}
	*options = NULL;
}

void	free_ast(t_child node)
{
	if (node.kind == COMMAND)
	{
		if (node.type.command->arguments != NULL)
		{
			free_options(&node.type.command->arguments);
		}
		if (node.type.command->redirections != NULL)
		{
			free_options(&node.type.command->redirections);
		}
		if (node.type.command != NULL)
		{
			free(node.type.command);
			node.type.command = NULL;
		}
		return ;
	}
	free_ast(node.type.pipeline->left_child);
	free_ast(node.type.pipeline->right_child);
	if (node.kind != MERROR && node.type.pipeline != NULL)
	{
		free(node.type.pipeline);
		node.type.pipeline = NULL;
	}
}

void	cleanup_tree(t_child *tree)
{
	close_all_heredoc_fds(*tree);
	if (tree->type.command != NULL)
	{
		free_ast((*tree));
		tree->type.command = NULL;
	}
}
