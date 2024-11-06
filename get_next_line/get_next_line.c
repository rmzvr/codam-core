/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:19:41 by rzvir             #+#    #+#             */
/*   Updated: 2024/11/06 18:04:01 by rzvir            ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	int		i;
	char	*copy;
	int		s_len;

	i = 0;
	s_len = ft_strlen(s);
	copy = (char *)malloc((s_len + 1) * sizeof(char));
	if (copy == NULL)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t			s_len;
	unsigned char	*str;
	unsigned char	chr;

	s_len = ft_strlen(s);
	chr = (unsigned char) c;
	str = (unsigned char *) s + s_len;
	while (str != (unsigned char *)s)
	{
		if (*str == chr)
		{
			return ((char *)str);
		}
		str--;
	}
	if (*str == chr)
	{
		return ((char *)str);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (joined_str);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	limit;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dst == NULL && size == 0)
		return (size + src_len);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
	{
		return (size + src_len);
	}
	limit = size - dst_len - 1;
	while (src[i] != '\0' && i < limit && 0 < limit)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	buffer[3];
	char		*line;
	char		*save_new_line;

	line = ft_strdup("");
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read != 0)
	{
		line = ft_strjoin(line, buffer);
		save_new_line = ft_strrchr(buffer, '\n');
		if (save_new_line != NULL)
		{
			save_new_line = save_new_line + 1;
			size_t len = ft_strlen(save_new_line);
			write(1, line, ft_strlen(line));
			return (NULL);
		}
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
	return (NULL);
}

// int	ft_run(void)
// {
// 	int		fd;
// 	char	*p;

// 	fd = open("test.txt", O_RDONLY);
// 	p = get_next_line(fd);
// 	while (p != NULL)
// 	{
// 		printf("%s", p);
// 		free(p);
// 		p = get_next_line(fd);
// 	}
// 	printf("%s", p);
// 	return (0);
// }

// int	main(void)
// {
// 	clock_t	s_time;
// 	clock_t	e_time;
// 	double	t_taken;

// 	s_time = clock();
// 	ft_run();
// 	e_time = clock();
// 	t_taken = ((double)(e_time - s_time) / CLOCKS_PER_SEC) * 1000.0;
// 	printf("\nExecution time: %.3f ms\n", t_taken);
// 	return (0);
// }
