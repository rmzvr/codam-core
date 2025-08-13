/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 13:00:11 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 13:00:34 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	offset;

	if (dst == NULL || src == NULL)
		return (0);
	src_len = ft_strlen(src);
	offset = 0;
	if (size == 0)
		return (src_len);
	while (offset < size - 1 && src[offset] != '\0')
	{
		dst[offset] = src[offset];
		++offset;
	}
	dst[offset] = '\0';
	return (src_len);
}

/* #include <assert.h>

void	assert_str_eq(char *s1, char *s2)
{
	assert(strcmp(s1, s2) == 0);
}

int	main()
{
	char	*dst;
	size_t	size_copied;
	size_t	size;

	size_copied = 3;
	dst = calloc(20, sizeof(char));
	size = ft_strlcpy(dst, "hello world", size_copied);
	// Since we don't have enough space to hold the whole string
	// the function returns how much it would have copied if it did.
	// We can then compare it to the size that we sent, to see if the
	// string was made shorter to fit into it.
	assert(size > size_copied);

	// It only has "he" since we only copy up until "size - 1"
	assert_str_eq(dst, "he");

	ft_memset(dst, '\0', 20); // Reset the dst

	// Here we try to copy 0 bytes
	size_copied = 0;
	size = ft_strlcpy(dst, "hello world", size_copied);
	// It gives us back the size of the string it would have been.
	// We can then compare and see if the string was fully copied.
	assert(size > size_copied);

	ft_memset(dst, '\0', 20); // Reset the dst

	// Here we try to copy the whole string
	// In this example, we purposefully try to copy a bigger number
	// than the string (src) actually holds. It will however, only
	// copy up until "size - 1" OR in this case, the src length.
	size_copied = 15;
	size = ft_strlcpy(dst, "hello world", size_copied);
	assert(size == ft_strlen("hello world"));
} */
