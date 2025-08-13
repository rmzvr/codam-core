/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 00:00:00 by bamarell          #+#    #+#             */
/*   Updated: 2025/07/22 12:52:02 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H
# include <stddef.h>

struct s_split_section
{
	size_t	start;
	size_t	length;
	size_t	index;
};

typedef struct s_split_section	t_split_section;

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *ptr, int ch, size_t count);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_substr(const char *str, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strtrim(const char *str, const char *set);
char	*ft_strrchr(const char *str, int ch);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strmapi(const char *str, char (*f)(unsigned int, char));
char	*ft_strjoin(const char *s1, const char *s2);
void	ft_striteri(char *str, void (*f)(unsigned int, char *));
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *s, int c);
char	**ft_split(const char *str, char c);
int		ft_startswith(const char *str, const char *prefix);
int		ft_endswith(const char *str, const char *suffix);
void	*ft_memrchr(const void *ptr, int ch, size_t n);
void	ft_putpad(int pad, int len);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strchroc(const char *str, int c);
int		ft_isnumber(const char *str);
int		ft_isdigits(const char *str);
char	*ft_strjoin_s(char *s1, char *s2);
#endif
