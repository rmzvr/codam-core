/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:19:41 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/31 16:28:45 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

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

int	ft_count_char_before(char *str)
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

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		buffer[BUFFER_SIZE];
	char		*line;
	static char	*stash;
	int			chars_before_count;

	if (stash == NULL)
	{
		stash = strndup("", 1);
	}
	bytes_read = read(fd, buffer, sizeof(buffer));
	if (ft_strlen(stash) != 0 && ft_strlen(stash) <= BUFFER_SIZE && bytes_read == 0)
	{
		line = strndup(stash, ft_strlen(stash));
		if (!line)
				return (NULL);
		stash = strndup("", 1);
		if (!stash)
				return (NULL);
		return (line);
	}
	while (bytes_read != 0 || ft_strlen(stash) != 0)
	{
		if (bytes_read != 0)
		{
			ft_strlcpy(buffer, buffer, bytes_read + 1);
		}
		if (bytes_read != 0)
		{
			stash = ft_strjoin(stash, buffer);
			if (!stash)
				return (NULL);
		}
		if (strchr(stash, '\n') || bytes_read == 0)
		{
			chars_before_count = ft_count_char_before(buffer);
			line = strndup(stash, ft_strlen(stash) - chars_before_count);
			if (bytes_read != 0)
				stash = ft_strchr(stash, '\n') + 1;
			return (line);
		}
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
	return (NULL);
}

int	main(void)
{
	int	fd = open("test.txt", O_RDWR);
	char *r = get_next_line(fd);
	char *r1 = get_next_line(fd);
	printf("%s", r);
	printf("%s", r1);
	free(r);
	free(r1);
	return (0);
}