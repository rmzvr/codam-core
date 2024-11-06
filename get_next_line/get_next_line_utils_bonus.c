/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:50:19 by rzvir             #+#    #+#             */
/*   Updated: 2024/11/06 17:55:11 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

// t_file	*ft_file_create(int fd)
// {
// 	t_file	*list_item;

// 	list_item = malloc(sizeof(t_file));
// 	if (list_item == NULL)
// 	{
// 		return (NULL);
// 	}
// 	list_item->fd = fd;
// 	list_item->stash = NULL;
// 	list_item->next = NULL;
// 	return (list_item);
// }

// void	ft_file_append_end(t_file **lst, t_file *new)
// {
// 	t_file	*curr;

// 	curr = *lst;
// 	if (lst == NULL)
// 	{
// 		return ;
// 	}
// 	if (*lst == NULL)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	while (curr->next != NULL)
// 	{
// 		curr = curr->next;
// 	}
// 	curr->next = new;
// }

// t_file	*ft_file_find(t_file *lst, int fd)
// {
// 	if (lst == NULL)
// 	{
// 		return (NULL);
// 	}
// 	while (lst->next != NULL)
// 	{
// 		if (lst->fd == fd)
// 		{
// 			return (lst);
// 		}
// 		lst = lst->next;
// 	}
// 	if (lst->fd == fd)
// 	{
// 		return (lst);
// 	}
// 	return (NULL);
// }

// static void	ft_file_free(t_file *file)
// {
// 	t_file	*lst_to_delete;

// 	lst_to_delete = file;
// 	file = (file)->next;
// 	free(lst_to_delete->stash);
// 	lst_to_delete->stash = NULL;
// 	free(lst_to_delete);
// }

// void	ft_file_remove(t_file **lst, int fd)
// {
// 	t_file	*curr;

// 	if (lst == NULL || *lst == NULL)
// 		return ;
// 	curr = *lst;
// 	if ((*lst)->fd == fd)
// 	{
// 		ft_file_free(*lst);
// 		return ;
// 	}
// 	while (curr->next != NULL)
// 	{
// 		if (curr->next->fd == fd)
// 		{
// 			ft_file_free(curr->next);
// 			return ;
// 		}
// 		curr = curr->next;
// 	}
// }
