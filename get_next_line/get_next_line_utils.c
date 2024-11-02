/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:21:54 by rzvir             #+#    #+#             */
/*   Updated: 2024/11/02 18:48:23 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_strndup(const char *src, size_t n)
// {
// 	char	*dest;
// 	size_t	i;

// 	dest = (char *)malloc(n + 1);
// 	if (dest == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < n)
// 	{
// 		dest[i] = *src++;
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*joined_str;
// 	size_t	i;
// 	size_t	s1_len;

// 	if (s1 == NULL || s1 == NULL)
// 		return (NULL);
// 	i = 0;
// 	s1_len = ft_strlen(s1);
// 	joined_str = malloc((s1_len + ft_strlen(s2)) + 1);
// 	if (joined_str == NULL)
// 	{
// 		free(s1);
// 		return (NULL);
// 	}
// 	while (i < (s1_len + ft_strlen(s2)))
// 	{
// 		if (i < s1_len)
// 			joined_str[i] = s1[i];
// 		else
// 			joined_str[i] = s2[i - s1_len];
// 		i++;
// 	}
// 	joined_str[i] = '\0';
// 	free(s1);
// 	return (joined_str);
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	i;
// 	size_t	src_len;

// 	i = 0;
// 	src_len = ft_strlen(src);
// 	if (size == 0)
// 	{
// 		return (src_len);
// 	}
// 	while (src[i] != '\0' && i < size - 1 && size != 0)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (src_len);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	unsigned char	chr;
// 	unsigned char	*str;

// 	chr = (unsigned char) c;
// 	str = (unsigned char *) s;
// 	while (*str != '\0')
// 	{
// 		if (*str == chr)
// 			return ((char *)str);
// 		str++;
// 	}
// 	if (chr == '\0')
// 	{
// 		return ((char *)str);
// 	}
// 	return (NULL);
// }
