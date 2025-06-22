/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:51:54 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 23:40:41 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser/token.h"
#include <unistd.h>

t_command	*create_command(void)
{
	t_command	*command;

	command = malloc(sizeof(t_command));
	if (command == NULL)
	{
		return (ft_putendl_fd(MEMERR, STDERR_FILENO), NULL);
	}
	command->node_type = COMMAND;
	command->arguments = NULL;
	command->redirections = NULL;
	return (command);
}

t_child	create_command_branch(
	t_syntax_tree tree_data
)
{
	tree_data.command = create_command();
	if (tree_data.command == NULL)
	{
		tree_data.left_child.kind = MERROR;
		free_options(&tree_data.arguments);
		free_options(&tree_data.redirections);
		return (tree_data.left_child);
	}
	tree_data.command->arguments = tree_data.arguments;
	tree_data.command->redirections = tree_data.redirections;
	tree_data.left_child.kind = COMMAND;
	tree_data.left_child.type.command = tree_data.command;
	return (tree_data.left_child);
}
