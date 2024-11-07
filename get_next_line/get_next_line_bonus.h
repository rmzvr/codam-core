/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:50:17 by rzvir             #+#    #+#             */
/*   Updated: 2024/11/07 17:28:30 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_file
{
	int				fd;
	char			*stash;
	struct s_file	*next;
}	t_file;

typedef struct s_store
{
	char	*buffer;
	t_file	*curr_file;
	ssize_t	bytes_read;
}	t_store;

typedef struct s_join
{
	char	*str;
	size_t	index;
	size_t	full_len;
	size_t	stash_len;
}	t_join;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *src, size_t n);
t_file	*ft_file_create(int fd);
void	ft_file_remove(t_file **lst, int fd);

#endif
