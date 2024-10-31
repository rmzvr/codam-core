/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:19:41 by rzvir             #+#    #+#             */
/*   Updated: 2024/11/06 18:09:33 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

// static void	*ft_write_to_line(char *line, char *buffer)
// {
// 	size_t	line_len;

// 	if (line == NULL)
// 		return ;
// 	line_len = ft_strlen(line);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined_str;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	size_t	joined_str_len;

	if (s1 == NULL || s1 == NULL)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_str_len = (s1_len + s2_len + 1) * sizeof(char);
	joined_str = (char *)malloc(joined_str_len);
	if (joined_str == NULL)
		return (NULL);
	while (i < joined_str_len - 1)
	{
		if (i < s1_len)
			joined_str[i] = s1[i];
		else
			joined_str[i] = s2[i - s1_len];
		i++;
	}
	joined_str[i] = '\0';
	free(s1);
	return (joined_str);
}

int	ft_count_char_after_new_line(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	if (str[i] == '\0')
		return (count);
	i++;
	while (str[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

void free_stash(char **stash) {
    if (*stash != NULL) {
        free(*stash);
        *stash = NULL;
    }
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static ssize_t		bytes_read;
	char		*line = NULL;
	static char	*stash;
	int			chars_after_new_line;

	if (stash == NULL)
	{
		stash = strndup("", 1);
	}
	bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == 0) {
        free(stash);
        stash = NULL;
        return (NULL);
    }
	while (bytes_read != 0)
	{
		stash = ft_strjoin(stash, buffer);
		if (strrchr(stash, '\n'))
		{
			chars_after_new_line = ft_count_char_after_new_line(buffer);
			line = strndup(stash, ft_strlen(stash) - chars_after_new_line);
			return (line);
		}
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
	free(line);
	return (line);
}

int	main(void)
{
	int	fd;
	char	*p;

	fd = open("test.txt", O_RDWR);
	p = get_next_line(fd);
	free(p);
	close(fd);
	return (0);
}
