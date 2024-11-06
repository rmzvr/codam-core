/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:50:15 by rzvir             #+#    #+#             */
/*   Updated: 2024/11/06 17:59:08 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_lstclear(t_file **lst, void (*del)(void*))
{
	t_file	*lst_to_delete;
	t_file	*curr;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		lst_to_delete = curr;
		curr = curr->next;
		del(lst_to_delete->stash);
		free(lst_to_delete);
	}
	*lst = NULL;
}

void	ft_lstremove(t_file **lst, int fd)
{
	t_file	*lst_to_delete;
	t_file	*curr;

	if (lst == NULL || *lst == NULL)
		return ;
	curr = *lst;

	if ((*lst)->fd == fd)
	{
		lst_to_delete = *lst;
		*lst = (*lst)->next;
		free(lst_to_delete->stash);
		lst_to_delete->stash = NULL;
		free(lst_to_delete);
		return ;
	}

	while (curr->next != NULL)
	{
		if (curr->next->fd == fd)
		{
			lst_to_delete = curr->next;
			curr->next = curr->next->next;
			free(lst_to_delete->stash);
			lst_to_delete->stash = NULL;
			free(lst_to_delete);
			return ;
		}
		curr = curr->next;
	}
}

t_file	*ft_lstnew(int fd)
{
	t_file	*list_item;

	list_item = malloc(sizeof(t_file));
	if (list_item == NULL)
	{
		return (NULL);
	}
	list_item->fd = fd;
	list_item->stash = NULL;
	list_item->next = NULL;
	return (list_item);
}

void	ft_lstadd_back(t_file **lst, t_file *new)
{
	t_file	*curr;

	curr = *lst;
	if (lst == NULL)
	{
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new;
}

t_file	*ft_find_file(t_file *lst, int fd)
{
	if (lst == NULL)
	{
		return (NULL);
	}
	while (lst->next != NULL)
	{
		if (lst->fd == fd)
		{
			return (lst);
		}
		lst = lst->next;
	}
	if (lst->fd == fd)
	{
		return (lst);
	}
	return (NULL);
}

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

static int	ft_init_stash_and_buffer(char **buffer, char **stash)
{
	if (*stash == NULL)
	{
		*stash = ft_strndup("", 1);
		if (*stash == NULL)
			return (1);
	}
	*buffer = malloc(BUFFER_SIZE + 1);
	if (*buffer == NULL)
	{
		free(*stash);
		*stash = NULL;
		return (1);
	}
	return (0);
}

static char	*ft_join_stash(ssize_t bytes_read, char **stash, char **buffer)
{
	char		*temp_stash;

	(*buffer)[bytes_read] = '\0';
	temp_stash = ft_strjoin(*stash, *buffer);
	free(*stash);
	*stash = NULL;
	if (temp_stash == NULL)
	{
		free(*buffer);
		return (NULL);
	}
	return (temp_stash);
}

static char	*ft_trim_stash(char **stash)
{
	char	*s;
	char	*copy;
	size_t	s_len;

	s = ft_strchr(*stash, '\n');
	if (s == NULL)
	{
		free(*stash);
		return (NULL);
	}
	s_len = ft_strlen(s);
	if (s_len == 1)
	{
		free(*stash);
		return (NULL);
	}
	copy = malloc(s_len + 1);
	if (copy == NULL)
	{
		free(*stash);
		return (NULL);
	}
	ft_strlcpy(copy, s + 1, s_len + 1);
	free(*stash);
	return (copy);
}

static char	*ft_put_line(char **buffer, char **stash, t_file **file, int fd)
{
	char		*line;
	size_t		len_to_nl;
	char		*nl_ptr;

	nl_ptr = ft_strchr(*stash, '\n');
	if (nl_ptr != NULL)
		len_to_nl = nl_ptr - *stash + 1;
	else
		len_to_nl = ft_strlen(*stash);
	line = ft_strndup(*stash, len_to_nl);
	if (line == NULL)
	{
		free(*buffer);
		free(*stash);
		*stash = NULL;
		ft_lstremove(file, fd);
		return (NULL);
	}
	*stash = ft_trim_stash(stash);
	free(*buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_file	*file;
	char			*buffer;
	ssize_t			bytes_read;
	t_file			*curr_file;

	if (file == NULL)
	{
		curr_file = ft_lstnew(fd);
		file = curr_file;
	}
	else
	{
		curr_file = ft_find_file(file, fd);
		if (curr_file == NULL)
		{
			curr_file = ft_lstnew(fd);
			ft_lstadd_back(&file, curr_file);
		}
	}
	if (curr_file == NULL || ft_init_stash_and_buffer(&buffer, &(curr_file->stash)))
	{
		ft_lstremove(&file, fd);
		return (NULL);
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		(curr_file->stash) = ft_join_stash(bytes_read, &(curr_file->stash), &buffer);
		if (curr_file->stash == NULL)
		{
			ft_lstremove(&file, fd);
			return (NULL);
		}
		if (ft_strchr(curr_file->stash, '\n'))
			return (ft_put_line(&buffer, &curr_file->stash, &file, fd));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == 0 && ft_strlen(curr_file->stash) > 0)
		return (ft_put_line(&buffer, &curr_file->stash, &file, fd));
	free(buffer);
	free(curr_file->stash);
	curr_file->stash = NULL;
	ft_lstremove(&file, fd);
	return (NULL);
}

// int	ft_run(void)
// {
// 	char	*p;

// 	// int	read_error = open("read_error", O_RDONLY);
// 	// int	lines_around_10 = open("lines_around_10", O_RDONLY);
// 	int	with_nl_41 = open("41_with_nl", O_RDONLY);
// 	// int	with_nl_42 = open("42_with_nl", O_RDONLY);
// 	// int	with_nl_43 = open("43_with_nl", O_RDONLY);
// 	// p = get_next_line(1000);
// 	// printf("1. %s\n", p);
// 	// free(p);
// 	p = get_next_line(with_nl_41);
// 	printf("2. %s\n", p);
// 	free(p);
// 	p = get_next_line(with_nl_41);
// 	printf("2. %s\n", p);
// 	free(p);
// 	p = get_next_line(with_nl_41);
// 	printf("2. %s\n", p);
// 	free(p);
// 	close(with_nl_41);
// 	// p = get_next_line(1001);
// 	// printf("3. %s\n", p);
// 	// free(p);
// 	// p = get_next_line(with_nl_42);
// 	// printf("4. %s\n", p);
// 	// free(p);
// 	// p = get_next_line(1002);
// 	// printf("5. %s\n", p);
// 	// free(p);
// 	// p = get_next_line(with_nl_43);
// 	// printf("6. %s\n", p);
// 	// free(p);
// 	// p = get_next_line(1003);
// 	// printf("7. %s\n", p);
// 	// free(p);
// 	// p = get_next_line(with_nl_41);
// 	// printf("8. %s\n", p);
// 	// free(p);
// 	// p = get_next_line(read_error);
// 	// printf("1. %s\n", p);
// 	// free(p);
// 	// p = get_next_line(read_error);
// 	// printf("2. %s\n", p);
// 	// free(p);
// 	// p = get_next_line(read_error);
// 	// printf("3. %s\n", p);
// 	// free(p);
// 	// p = get_next_line(read_error);
// 	// printf("4. %s\n", p);
// 	// free(p);
// 	// p = get_next_line(read_error);
// 	// printf("5. %s\n", p);
// 	// free(p);
// 	return (0);
// }

// int	main(void)
// {
// 	// clock_t	s_time;
// 	// clock_t	e_time;
// 	// double	t_taken;

// 	// s_time = clock();
// 	ft_run();
// 	// e_time = clock();
// 	// t_taken = ((double)(e_time - s_time) / CLOCKS_PER_SEC) * 1000.0;
// 	// printf("\nExecution time: %.3f ms\n", t_taken);
// 	return (0);
// }