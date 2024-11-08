/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:50:19 by rzvir             #+#    #+#             */
/*   Updated: 2024/11/08 12:24:28 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
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

t_file	*ft_create_file(int fd)
{
	t_file	*file;

	file = malloc(sizeof(t_file));
	if (file == NULL)
		return (NULL);
	file->fd = fd;
	file->next = NULL;
	file->stash = ft_strndup("", 0);
	if (file->stash == NULL)
	{
		free(file);
		return (NULL);
	}
	return (file);
}

void	ft_remove_file(t_file **list, int fd)
{
	t_file	*curr;
	t_file	*file_to_delete;

	if (list == NULL || *list == NULL)
		return ;
	curr = *list;
	if ((*list)->fd == fd)
	{
		file_to_delete = *list;
		*list = (*list)->next;
		free(file_to_delete);
		return ;
	}
	while (curr->next != NULL)
	{
		if (curr->next->fd == fd)
		{
			file_to_delete = curr->next;
			curr->next = curr->next->next;
			free(file_to_delete);
			return ;
		}
		curr = curr->next;
	}
}
