/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:50:19 by rzvir             #+#    #+#             */
/*   Updated: 2024/11/07 17:15:08 by rzvir            ###   ########.fr       */
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

t_file	*ft_file_create(int fd)
{
	t_file	*list_item;

	list_item = malloc(sizeof(t_file));
	if (list_item == NULL)
		return (NULL);
	list_item->fd = fd;
	list_item->stash = NULL;
	list_item->next = NULL;
	return (list_item);
}

void	ft_file_remove(t_file **lst, int fd)
{
	t_file	*curr;
	t_file	*lst_to_delete;

	if (lst == NULL || *lst == NULL)
		return ;
	curr = *lst;
	if ((*lst)->fd == fd)
	{
		lst_to_delete = *lst;
		*lst = (*lst)->next;
		free(lst_to_delete);
		return ;
	}
	while (curr->next != NULL)
	{
		if (curr->next->fd == fd)
		{
			lst_to_delete = curr->next;
			curr->next = curr->next->next;
			free(lst_to_delete);
			return ;
		}
		curr = curr->next;
	}
}
