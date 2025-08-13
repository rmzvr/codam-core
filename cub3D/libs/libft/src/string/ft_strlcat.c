/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 15:13:57 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 12:50:51 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	offset;

	if (dst == NULL || src == NULL)
		return (0);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	offset = 0;
	if (size <= dst_len)
		return (size + src_len);
	while (src[offset] != '\0' && dst_len + offset < size - 1)
	{
		dst[dst_len + offset] = src[offset];
		++offset;
	}
	dst[dst_len + offset] = '\0';
	return (dst_len + src_len);
}

/* #include <assert.h>

void	assert_str_eq(char *s1, char *s2)
{
	assert(strcmp(s1, s2) == 0);
}

int	main()
{
	char *b = "world";
	char buf[50];
	int	result;
	ft_strlcpy(buf, "hello ", 7);

	result = ft_strlcat(buf, b, sizeof(buf));
	// We expect it to copy over the whole string
	assert(result == ft_strlen("hello world"));
	assert_str_eq(buf, "hello world");

	// Since the "size" parameter we passed
	// is smaller than the size of string
	// we're trying to concatenate another string
	// onto, we return with the length that the
	// string would be. Since there isn't enough
	// space for the dest string to hold itself.
	ft_strlcpy(buf, "hello ", 7);
	result = ft_strlcat(buf, b, 5);
	assert(result == ft_strlen(b) + 5);
	// We expect the string to not have changed
	assert_str_eq(buf, "hello ");
} */
