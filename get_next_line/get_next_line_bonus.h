/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:50:17 by rzvir             #+#    #+#             */
/*   Updated: 2024/11/06 17:53:56 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// read
# include <unistd.h>
// malloc
# include <stdlib.h>
//! open
# include <fcntl.h>
//! printf
# include <stdio.h>
//! time
# include <time.h>

// # include "get_next_line.h"

typedef struct s_file
{
	int				fd;
	char			*stash;
	struct s_file	*next;
}	t_file;

// t_file	*ft_file_create(int fd);
// t_file	*ft_file_find(t_file *lst, int fd);
// void	ft_file_remove(t_file **lst, int fd);
// void	ft_file_append_end(t_file **lst, t_file *new);

#endif
