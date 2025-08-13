/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 16:01:26 by bamarell      #+#    #+#                 */
/*   Updated: 2025/07/23 10:34:51 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "state.h"
#include "parser/parser.h"

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
