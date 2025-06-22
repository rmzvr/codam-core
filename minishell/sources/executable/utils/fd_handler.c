/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:09:49 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/16 11:30:50 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd/exec_cmd.h"

void	ft_close_fds(int count_pipes, int **pipes_fd)
{
	int	j;
	int	k;

	j = 0;
	while (j < count_pipes)
	{
		k = 0;
		while (k < 2)
		{
			close(pipes_fd[j][k]);
			k++;
		}
		j++;
	}
}

static int	restore_fd(int saved_in, int saved_out, t_bool *saved)
{
	int	dup_status;

	dup_status = dup2(saved_in, STDIN_FILENO);
	if (dup_status == -1)
	{
		perror("minishell: dup");
		(*saved) = FALSE;
		close(saved_in);
		close(saved_out);
		return (-1);
	}
	close(saved_in);
	dup_status = dup2(saved_out, STDOUT_FILENO);
	if (dup_status == -1)
	{
		perror("minishell: dup");
		(*saved) = FALSE;
		close(saved_out);
		return (-1);
	}
	close(saved_out);
	(*saved) = FALSE;
	return (0);
}

int	save_and_reset_dup(t_bool do_reset)
{
	static t_bool	saved;
	static int		saved_in;
	static int		saved_out;

	if (do_reset == FALSE && saved == FALSE)
	{
		saved_in = dup(STDIN_FILENO);
		if (saved_in == -1)
		{
			return (perror("minishell: dup"), -1);
		}
		saved_out = dup(STDOUT_FILENO);
		if (saved_out == -1)
		{
			close(saved_in);
			return (perror("minishell: dup"), -1);
		}
		saved = TRUE;
	}
	if (saved == TRUE && do_reset == TRUE)
	{
		restore_fd(saved_in, saved_out, &saved);
	}
	return (0);
}

void	iterate_redirect(t_options *redir_head)
{
	t_options	*curr_redir;
	int			fd_to_close;

	curr_redir = redir_head;
	while (curr_redir != NULL)
	{
		if (curr_redir->token_type == DLESS && curr_redir->content != NULL)
		{
			fd_to_close = ft_atoi(curr_redir->content);
			if (ft_check_num(curr_redir->content) == FALSE
				|| fd_to_close == -1)
			{
				curr_redir = curr_redir->next;
				continue ;
			}
			if (close(fd_to_close) == -1)
			{
				curr_redir = curr_redir->next;
				handle_error_file("close");
				continue ;
			}
		}
		curr_redir = curr_redir->next;
	}
}

void	close_all_heredoc_fds(t_child tree)
{
	t_child		curr_node;
	t_options	*redir_head;

	curr_node = tree;
	while (curr_node.type.command != NULL)
	{
		if (curr_node.kind == PIPELINE)
		{
			redir_head = curr_node.type.pipeline
				->left_child.type.command->redirections;
			iterate_redirect(redir_head);
		}
		else if (curr_node.kind == COMMAND)
		{
			redir_head = curr_node.type.command->redirections;
			iterate_redirect(redir_head);
			break ;
		}
		curr_node = curr_node.type.pipeline->right_child;
	}
}
