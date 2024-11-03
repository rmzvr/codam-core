/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:19:41 by rzvir             #+#    #+#             */
/*   Updated: 2024/11/06 18:10:24 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strndup(const char *src, size_t n)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(n + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = *src++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined_str;
	size_t	i;
	size_t	s1_len;

	if (s1 == NULL || s1 == NULL)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1);
	joined_str = malloc((s1_len + ft_strlen(s2)) + 1);
	if (joined_str == NULL)
	{
		free(s1);
		return (NULL);
	}
	while (i < (s1_len + ft_strlen(s2)))
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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
	{
		return (src_len);
	}
	while (src[i] != '\0' && i < size - 1 && size != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;
	unsigned char	*str;

	chr = (unsigned char) c;
	str = (unsigned char *) s;
	while (*str != '\0')
	{
		if (*str == chr)
			return ((char *)str);
		str++;
	}
	if (chr == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}

static int	ft_get_len_after_nl(char *str)
{
	int	count;

	count = 0;
	while (*str != '\n' && *str != '\0')
		str++;
	if (*str == '\0')
		return (count);
	str++;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
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

// static void	ft_free(char **buffer, char **stash)
// {
// 	free(*buffer);
// 	free(*stash);
// 	*stash = NULL;
// }

static char	*ft_put_line(char **buffer, char **stash)
{
	char		*line;
	int			chars_after_new_line;

	chars_after_new_line = ft_get_len_after_nl(*stash);
	line = ft_strndup(*stash, ft_strlen(*stash) - chars_after_new_line);
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

// static int	ft_is_stash_or_buffer_invalid(char **buffer, char **stash)
// {
// 	if (*stash == NULL)
// 	{
// 		*stash = ft_strndup("", 1);
// 		if (*stash == NULL)
// 		{
// 			return (1);
// 		}
// 	}
// 	*buffer = malloc(BUFFER_SIZE + 1);
// 	if (*buffer == NULL)
// 	{
// 		free(*stash);
// 		*stash = NULL;
// 		return (1);
// 	}
// 	return (0);
// }

static char	*ft_join_stash(ssize_t bytes_read, char **stash, char **buffer)
{
	if (bytes_read > 0)
	{
		(*buffer)[bytes_read] = '\0';
		*stash = ft_strjoin(*stash, *buffer);
		if (*stash == NULL)
		{
			free(*buffer);
			return (NULL);
		}
	}
	return (*stash);
}

char	*get_next_line(int fd)
{
	ssize_t		bytes_read;
	char		*buffer;
	static char	*stash;
	int			done;

	if (stash == NULL)
	{
		stash = ft_strndup("", 0);
		if (stash == NULL)
			return (NULL);
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	done = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (!done)
	{
		stash = ft_join_stash(bytes_read, &stash, &buffer);
		if (stash == NULL)
			return (NULL);
		if ((bytes_read > 0 && ft_strchr(buffer, '\n'))
			|| (bytes_read == 0 && ft_strlen(stash) > 0))
			return (ft_put_line(&buffer, &stash));
		if (bytes_read > 0)
			bytes_read = read(fd, buffer, BUFFER_SIZE);
		else
			done = 1;
	}
	free(buffer);
	free(stash);
	stash = NULL;
	return (NULL);
}

/* int	main(void)
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
} */
