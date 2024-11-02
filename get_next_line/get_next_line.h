/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:21:05 by rzvir             #+#    #+#             */
/*   Updated: 2024/11/06 18:09:57 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// read
# include <unistd.h>
// malloc
# include <stdlib.h>
//! open
# include <fcntl.h>
//! printf
# include <stdio.h>

char	*get_next_line(int fd);
// char	*ft_strjoin(char *s1, char *s2);
// size_t	ft_strlen(const char *s);
// char	*ft_strchr(const char *s, int c);
// char	*ft_strndup(const char *src, size_t n);
// size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
