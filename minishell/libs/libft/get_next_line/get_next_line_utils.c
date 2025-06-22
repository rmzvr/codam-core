/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:50:19 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/22 14:18:57 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
