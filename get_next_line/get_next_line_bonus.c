/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:50:15 by rzvir             #+#    #+#             */
/*   Updated: 2024/11/07 17:21:32 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_free(t_file **file, t_store *store, int fd, int remove_file)
{
	free(store->buffer);
	free(store->curr_file->stash);
	store->curr_file->stash = NULL;
	if (remove_file > 0)
		ft_file_remove(file, fd);
}

static int	ft_join_stash(t_file **file, t_store *store, int fd)
{
	t_join	join;

	store->buffer[store->bytes_read] = '\0';
	if (store->curr_file->stash == NULL || store->buffer == NULL)
		return (1);
	join.index = 0;
	join.stash_len = ft_strlen(store->curr_file->stash);
	join.full_len = join.stash_len + ft_strlen(store->buffer);
	join.str = malloc(join.full_len + 1);
	if (join.str == NULL)
		return (ft_free(file, store, fd, 1), 1);
	while (join.index < join.full_len)
	{
		if (join.index < join.stash_len)
			join.str[join.index] = store->curr_file->stash[join.index];
		else
			join.str[join.index] = store->buffer[join.index - join.stash_len];
		join.index++;
	}
	join.str[join.index] = '\0';
	free(store->curr_file->stash);
	store->curr_file->stash = NULL;
	store->curr_file->stash = join.str;
	return (0);
}

static char	*ft_put_line(t_file **file, t_store *store, int fd)
{
	char	*line;
	char	*nl_ptr;
	char	*temp_stash;
	size_t	len_to_nl;

	nl_ptr = ft_strchr(store->curr_file->stash, '\n');
	if (nl_ptr != NULL)
		len_to_nl = nl_ptr - store->curr_file->stash + 1;
	else
		len_to_nl = ft_strlen(store->curr_file->stash);
	line = ft_strndup(store->curr_file->stash, len_to_nl);
	if (line == NULL)
		return (ft_free(file, store, fd, 1), NULL);
	if (nl_ptr == NULL)
		return (ft_free(file, store, fd, 1), line);
	temp_stash = ft_strndup(nl_ptr + 1, ft_strlen(nl_ptr + 1));
	if (temp_stash == NULL)
		return (free(line), ft_free(file, store, fd, 1), NULL);
	ft_free(file, store, fd, 0);
	store->curr_file->stash = temp_stash;
	return (line);
}

static void	ft_init(t_file **file, t_store *store, int fd)
{
	t_file	*curr;

	curr = *file;
	if (*file == NULL)
	{
		store->curr_file = ft_file_create(fd);
		*file = store->curr_file;
		return ;
	}
	while (curr != NULL)
	{
		if (curr->fd == fd)
		{
			store->curr_file = curr;
			return ;
		}
		if (curr->next == NULL)
			break ;
		curr = curr->next;
	}
	store->curr_file = ft_file_create(fd);
	curr->next = store->curr_file;
}

char	*get_next_line(int fd)
{
	static t_file	*file;
	t_store			store;

	ft_init(&file, &store, fd);
	if (store.curr_file == NULL)
		return (ft_file_remove(&file, fd), NULL);
	if (store.curr_file->stash == NULL)
	{
		store.curr_file->stash = ft_strndup("", 0);
		if (store.curr_file->stash == NULL)
			return (ft_file_remove(&file, fd), NULL);
	}
	store.buffer = malloc(BUFFER_SIZE + 1);
	store.bytes_read = read(fd, store.buffer, BUFFER_SIZE);
	while (store.bytes_read > 0)
	{
		if (ft_join_stash(&file, &store, fd))
			return (NULL);
		if (ft_strchr(store.curr_file->stash, '\n'))
			return (ft_put_line(&file, &store, fd));
		store.bytes_read = read(fd, store.buffer, BUFFER_SIZE);
	}
	if (store.bytes_read == 0 && ft_strlen(store.curr_file->stash) > 0)
		return (ft_put_line(&file, &store, fd));
	return (ft_free(&file, &store, fd, 1), NULL);
}
