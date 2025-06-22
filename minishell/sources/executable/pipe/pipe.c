/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:57:28 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/24 20:32:21 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd/exec_cmd.h"

static int	ft_get_pipeline_count(
	t_child root
)
{
	t_child	curr;
	size_t	count;

	count = 0;
	curr = root;
	while (curr.type.pipeline != NULL && curr.kind == PIPELINE)
	{
		count++;
		curr = curr.type.pipeline->right_child;
	}
	return (count);
}

static int	**ft_create_pipes(
	int count_pipes
)
{
	int	**pipes_fd;
	int	i;

	pipes_fd = malloc(count_pipes * sizeof(int *));
	if (pipes_fd == NULL)
	{
		ft_putendl_fd(MEMERR, STDERR_FILENO);
		return (NULL);
	}
	i = 0;
	while (i < count_pipes)
	{
		pipes_fd[i] = malloc(2 * sizeof(int));
		if (pipes_fd[i] == NULL)
		{
			ft_putendl_fd(MEMERR, STDERR_FILENO);
			return (NULL);
		}
		if (pipe(pipes_fd[i]) == -1)
			return (ft_free_double_int_pointer(&pipes_fd, i), NULL);
		i++;
	}
	return (pipes_fd);
}

static t_pipe	initialize_pipes(
	t_data *data
)
{
	t_pipe		pipes;

	pipes.current_pipe_index = 0;
	pipes.count_pipes = ft_get_pipeline_count(data->tree);
	pipes.pipe_fds = ft_create_pipes(pipes.count_pipes);
	return (pipes);
}

static int	ft_handle_pipeline(
	t_data *data
)
{
	int			exit_code;
	t_child		curr_child;
	t_command	*curr_cmd;
	t_pipe		pipes;

	pipes = initialize_pipes(data);
	if (pipes.pipe_fds == NULL)
		return (ft_putendl_fd(MEMERR, STDERR_FILENO), EMALLOC);
	curr_child = data->tree;
	while (curr_child.type.command != NULL)
	{
		if (curr_child.kind == PIPELINE)
			curr_cmd = curr_child.type.pipeline->left_child.type.command;
		else if (curr_child.kind == COMMAND)
			curr_cmd = curr_child.type.command;
		exit_code = exec_cmd(curr_cmd, &pipes, data);
		if (exit_code == EMALLOC || curr_child.kind == COMMAND)
			break ;
		curr_child = curr_child.type.pipeline->right_child;
		pipes.current_pipe_index += 1;
	}
	ft_close_fds(pipes.count_pipes, pipes.pipe_fds);
	ft_free_double_int_pointer(&pipes.pipe_fds, pipes.count_pipes);
	return (exit_code);
}

int	ft_tokens_actionizer(
	t_data *data
)
{
	t_child	curr_child;
	int		exit_code;
	int		last_pid;

	exit_code = 0;
	last_pid = 0;
	if (data->tree.type.command == NULL
		|| (data->tree.type.command->arguments == NULL
			&& data->tree.type.command->redirections == NULL))
		return (0);
	curr_child = data->tree;
	if (curr_child.kind == PIPELINE && curr_child.type.pipeline != NULL)
	{
		last_pid = ft_handle_pipeline(data);
		if (last_pid == EMALLOC)
			return (EMALLOC);
	}
	else if (curr_child.kind == COMMAND && curr_child.type.command != NULL)
	{
		last_pid = exec_cmd(curr_child.type.command, NULL, data);
		if (last_pid == EMALLOC)
			return (EMALLOC);
	}
	exit_code = wait_for_child(last_pid);
	return (exit_code);
}
