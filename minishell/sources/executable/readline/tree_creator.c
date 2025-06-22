/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:29:15 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/24 20:33:29 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/scanner.h"
#include "parser/evaluator.h"
#include "exec_cmd/exec_cmd.h"

int	handle_parser_exit_code(
	int res,
	char **line,
	t_data *data
)
{
	if (res == EMALLOC || res == FAIL)
	{
		protected_free(line);
		(*line) = NULL;
		if (data->tree.type.command != NULL)
			cleanup_tree(&data->tree);
		data->tree.type.command = NULL;
		data->last_exit_code = 2;
		return (res);
	}
	return (0);
}

int	is_failure_exit_status(
	int exit_code,
	t_data *data
)
{
	if (exit_code == EMALLOC || exit_code == FAIL)
	{
		if (data->tokens != NULL)
			free_tokens(&data->tokens);
		return (exit_code);
	}
	return (OK);
}

int	assign_tree(
	char *input,
	t_data *data
)
{
	int	exit_code;

	exit_code = assign_tokens(&data->tokens, input);
	if (is_failure_exit_status(exit_code, data) != OK)
		return (exit_code);
	exit_code = evaluate_tokens(data);
	if (is_failure_exit_status(exit_code, data) != OK)
		return (exit_code);
	data->tree = create_syntax_tree(data->tokens);
	if (data->tree.kind == MERROR)
	{
		data->last_exit_code = 2;
		if (data->tokens != NULL)
			free_tokens(&data->tokens);
		protected_free(&input);
		ft_exit(data, TRUE);
	}
	if (data->tokens != NULL)
		free_tokens(&data->tokens);
	return (0);
}
