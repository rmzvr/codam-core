/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:19:41 by rzvir             #+#    #+#             */
/*   Updated: 2024/11/05 21:52:01 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_init_stash_and_buffer(char **buffer, char **stash)
{
	if (*stash == NULL)
	{
		*stash = ft_strndup("", 1);
		if (*stash == NULL)
			return (1);
	}
	*buffer = malloc(BUFFER_SIZE + 1);
	if (*buffer == NULL)
	{
		free(*stash);
		*stash = NULL;
		return (1);
	}
	return (0);
}

static char	*ft_join_stash(ssize_t bytes_read, char **stash, char **buffer)
{
	char		*temp_stash;

	(*buffer)[bytes_read] = '\0';
	temp_stash = ft_strjoin(*stash, *buffer);
	free(*stash);
	*stash = NULL;
	if (temp_stash == NULL)
	{
		free(*buffer);
		return (NULL);
	}
	return (temp_stash);
}

static char	*ft_trim_stash(char *stash)
{
	char	*s;
	char	*copy;
	size_t	s_len;

	s = ft_strchr(stash, '\n');
	if (s == NULL)
	{
		free(stash);
		return (NULL);
	}
	s_len = ft_strlen(s);
	if (s_len == 1)
	{
		free(stash);
		return (NULL);
	}
	copy = malloc(s_len + 1);
	if (copy == NULL)
	{
		free(stash);
		return (NULL);
	}
	ft_strlcpy(copy, s + 1, s_len + 1);
	free(stash);
	return (copy);
}

static char	*ft_put_line(char **buffer, char **stash)
{
	char		*line;
	size_t		len_to_nl;
	char		*nl_ptr;

	nl_ptr = ft_strchr(*stash, '\n');
	if (nl_ptr != NULL)
		len_to_nl = nl_ptr - *stash + 1;
	else
		len_to_nl = ft_strlen(*stash);
	line = ft_strndup(*stash, len_to_nl);
	if (line == NULL)
	{
		free(*buffer);
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	*stash = ft_trim_stash(*stash);
	free(*buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	ssize_t		bytes_read;
	static char	*stash;
	char		*buffer;

	if (ft_init_stash_and_buffer(&buffer, &stash))
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		stash = ft_join_stash(bytes_read, &stash, &buffer);
		if (stash == NULL)
			return (NULL);
		if (ft_strchr(stash, '\n'))
			return (ft_put_line(&buffer, &stash));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == 0 && ft_strlen(stash) > 0)
		return (ft_put_line(&buffer, &stash));
	free(buffer);
	free(stash);
	stash = NULL;
	return (NULL);
}

int	ft_run(void)
{
	int		fd;
	char	*p;

	fd = open("test.txt", O_RDONLY);
	p = get_next_line(fd);
	while (p != NULL)
	{
		printf("%s", p);
		free(p);
		p = get_next_line(fd);
	}
	printf("%s", p);
	return (0);
}

// int main() {
//     // Start time
//     clock_t start_time = clock();

//     // Code to measure
// 	ft_run();

//     // End time
//     clock_t end_time = clock();

//     // Calculate the elapsed time in milliseconds
//     double time_taken = ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000.0;

//     printf("\nExecution time: %.3f ms\n", time_taken);

//     return 0;
// }
