/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:01:26 by bamarell          #+#    #+#             */
/*   Updated: 2025/07/24 14:00:28 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "state_bonus.h"
#include "parser/parser_bonus.h"

static
char	*read_fd_buffer(int fd)
{
	char	*buffer;
	char	*line;

	buffer = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		buffer = ft_strjoin_s(buffer, line);
		if (buffer == NULL)
		{
			free(line);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	return (buffer);
}

char	*read_file(const char *path)
{
	const int	fd = open(path, O_RDONLY);
	char		*buffer;

	if (fd == -1)
		return (NULL);
	buffer = read_fd_buffer(fd);
	close(fd);
	return (buffer);
}
