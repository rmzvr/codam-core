/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:50:17 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/22 12:44:23 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include "../libft.h"

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
t_file	*ft_create_file(int fd);
void	ft_remove_file(t_file **lst, int fd);

#endif
