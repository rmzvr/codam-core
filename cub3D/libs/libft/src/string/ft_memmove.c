/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 12:57:59 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/12 12:05:25 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

// memcpy reversed
static void	*ft_memrcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL || src == NULL)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[n - i - 1] = ((unsigned char *)src)[n - i - 1];
		++i;
	}
	return (dest);
}

// if the source is ahead of dest you
// start reading from the end (backwards)
// otherwise we just use the "normal"
// way of copying over.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == NULL || src == NULL)
		return (dest);
	if (src == dest)
		return (dest);
	if (src < dest && src + n >= dest)
		ft_memrcpy(dest, src, n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/* #include <assert.h>

void	assert_str_eq(char *s1, char *s2)
{
	assert(strcmp(s1, s2) == 0);
}

int	main()
{
	// copies from [4, 5, 6] to [5, 6, 7]
	char str[] = "1234567890";
	ft_memmove(str + 4, str + 3, 3);
	assert_str_eq(str, "1234456890");

	// Non overlapping memory should be copied normally
	char	*n_str = "Hello World";
	char	dest[15];
	ft_memset(dest, '\0', 15);
	ft_memmove(dest, n_str, ft_strlen(n_str));
	assert_str_eq(dest, n_str);
} */
