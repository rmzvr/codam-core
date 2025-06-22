/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:37:22 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/18 15:09:04 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections/redirections.h"

static int	proceed_redirection(
	int fd1,
	int fd2
)
{
	int	dup_status;

	dup_status = dup2(fd1, fd2);
	if (dup_status == -1)
	{
		if (close(fd1) == -1)
		{
			return (1);
		}
		return (1);
	}
	if (close(fd1) == -1)
	{
		return (1);
	}
	return (0);
}

int	redirect_input(
	const char *filename,
	int fd2
)
{
	int	in_fd;

	in_fd = open(filename, O_RDONLY);
	if (in_fd == -1)
	{
		handle_error_file(filename);
		return (1);
	}
	if (proceed_redirection(in_fd, fd2))
	{
		handle_error_file(filename);
		return (1);
	}
	return (0);
}

int	redirect_heredoc(
	const char *filename,
	int fd2
)
{
	int	in_fd;

	if (ft_check_num(filename) == FALSE)
		return (1);
	in_fd = ft_atoi(filename);
	if (in_fd == -1)
	{
		handle_error_file(filename);
		return (1);
	}
	if (proceed_redirection(in_fd, fd2))
	{
		handle_error_file(filename);
		return (1);
	}
	return (0);
}

int	redirect_output_mode(
	const char *filename,
	int fd2,
	int mode
)
{
	int	out_fd;

	out_fd = open(filename, O_CREAT | O_WRONLY | mode, 0666);
	if (out_fd == -1)
	{
		handle_error_file(filename);
		return (1);
	}
	if (proceed_redirection(out_fd, fd2))
	{
		handle_error_file(filename);
		return (1);
	}
	return (0);
}

int	redirect(
	t_options *redirections,
	t_bool heredoc
)
{
	t_options	*curr;

	curr = redirections;
	while (curr != NULL)
	{
		if (curr->token_type == GREAT || curr->token_type == DGREAT)
		{
			if (handle_redirect_output(curr->token_type, curr->content))
			{
				return (1);
			}
		}
		else if (curr->token_type == LESS || curr->token_type == DLESS)
		{
			if (handle_redirect_input(
					curr->token_type, &curr->content, heredoc))
			{
				return (1);
			}
		}
		curr = curr->next;
	}
	return (0);
}
