/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:48:07 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/22 22:00:12 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt/prompt.h"

int	get_file_descriptor(
	char *str
)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		handle_error_file(str);
		return (-1);
	}
	return (fd);
}

int	compare_uid(
	char **line,
	long uid
)
{
	size_t	i;
	char	*colon_pos;

	i = 1;
	while (i < 3)
	{
		if (i == 1)
		{
			colon_pos = ft_strchr((*line), ':');
		}
		else
		{
			colon_pos = ft_strchr(colon_pos, ':');
		}
		if (colon_pos == NULL)
		{
			protected_free(line);
			return (CONTINUE);
		}
		colon_pos++;
		i++;
	}
	return (ft_atol(colon_pos) == uid);
}

int	assign_line(
	char **line,
	int fd
)
{
	if ((*line) != NULL)
	{
		protected_free(line);
	}
	(*line) = get_next_line(fd);
	if (errno == ENOMEM)
	{
		close(fd);
		get_next_line(fd);
		return (print_merror_and_return_code(EMALLOC));
	}
	return (OK);
}

static int	get_username_from_file(
	char **line,
	int fd,
	char **username
)
{
	char	*colon_pos;

	colon_pos = ft_strchr((*line), ':');
	if (colon_pos == NULL)
	{
		return (CONTINUE);
	}
	(*username) = ft_strndup((*line), colon_pos - (*line));
	if ((*username) == NULL)
	{
		close(fd);
		protected_free(line);
		get_next_line(fd);
		return (print_merror_and_return_code(EMALLOC));
	}
	return (OK);
}

int	assign_username(
	char **line,
	int fd,
	char **username
)
{
	int	result;

	result = get_username_from_file(line, fd, username);
	if (result == EMALLOC)
	{
		return (EMALLOC);
	}
	if (result == CONTINUE)
	{
		result = assign_line(line, fd);
		if (result == EMALLOC)
		{
			return (EMALLOC);
		}
	}
	return (result);
}
