/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 14:26:17 by bamarell      #+#    #+#                 */
/*   Updated: 2023/11/29 13:10:06 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "libft/io/get_next_line.h"
#include "libft/string.h"

// We want the whole line if we haven't hit a line break.
// With the assumption that we have read the whole buffer
// prior to calling this function.
static size_t	ft_get_line_width(const char *buffer)
{
	char	*ch;

	ch = ft_strchr(buffer, '\n');
	if (ch == NULL)
		return (ft_strlen(buffer));
	return ((ch - buffer) + 1);
}

static void	*free_buffer(char **buffer)
{
	if (*buffer != NULL)
		free(*buffer);
	*buffer = NULL;
	return (*buffer);
}

static char	*ft_get_line_swap(char **cached_buffer)
{
	char	*read_buffer;
	char	*swap_buffer;
	size_t	line_offset;
	size_t	line_width;

	line_offset = ft_get_line_width(*cached_buffer);
	read_buffer = ft_substr(*cached_buffer, 0, line_offset);
	if (read_buffer == NULL)
		return (free_buffer(cached_buffer));
	line_width = ft_strlen(*cached_buffer + line_offset);
	swap_buffer = *cached_buffer;
	*cached_buffer = ft_substr(*cached_buffer, line_offset, line_width);
	free(swap_buffer);
	if (*cached_buffer == NULL)
		return (free_buffer(&read_buffer));
	return (read_buffer);
}

static char	*ft_get_line(int fd, char **cached_buffer, char *read_buffer)
{
	char	*swap_buffer;
	ssize_t	bytes_read;

	if (ft_strchr(*cached_buffer, '\n') != NULL)
		return (free_buffer(&read_buffer), ft_get_line_swap(cached_buffer));
	while (ft_strchr(read_buffer, '\n') == NULL)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
			return (free_buffer(cached_buffer), free_buffer(&read_buffer));
		read_buffer[bytes_read] = '\0';
		swap_buffer = *cached_buffer;
		*cached_buffer = ft_strjoin(*cached_buffer, read_buffer);
		free_buffer(&swap_buffer);
		if (*cached_buffer == NULL)
			return (free_buffer(&read_buffer));
	}
	free_buffer(&read_buffer);
	if (**cached_buffer == '\0')
		return (free_buffer(cached_buffer));
	return (ft_get_line_swap(cached_buffer));
}

char	*get_next_line(int fd)
{
	static char	*cached_buffers[MAX_FD];
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD - 1)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	buffer[0] = '\0';
	if (cached_buffers[fd] == NULL)
		cached_buffers[fd] = ft_strdup("");
	if (cached_buffers[fd] == NULL)
		return (free_buffer(&buffer));
	return (ft_get_line(fd, &cached_buffers[fd], buffer));
}

/* #include <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*line;
	int		fds[MAX_FD];
	int		fd;
	size_t	i;

	i = 0;
	if (argc == 1)
	{
		printf("Missing arguments: ./a.out [...files]\n");
		return (1);
	}
	while ((argv + 1)[i])
	{
		fd = open((argv + 1)[i], O_RDONLY);
		if (fd < 0)
			return (1);
		fds[i] = fd;
		++i;
	}
	i = 0;
	while (1)
	{
		while (i < argc - 1)
		{
			fd = fds[i];
			line = get_next_line(fd);
			// We have read it's entire buffer or something
			// failed while we tried to.
			if (line == NULL)
			{
				++i;
				continue ;
			}
			printf("fd[%ld]: %s\n", i, line);
			++i;
		}
		i = 0;
	}
	while (i < argc - 1)
	{
		close(fds[i]);
		++i;
	}
	return (0);
} */
