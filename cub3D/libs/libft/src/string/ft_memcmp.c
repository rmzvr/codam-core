/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 13:21:29 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 12:29:57 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		++i;
	}
	return (0);
}

/* #include <assert.h>

int	main()
{
	assert(ft_memcmp("", "", 0) == 0);
	assert(ft_memcmp("", "", 1) == 0);
	assert(ft_memcmp("Hello", "Hello", 5) == 0);
	// We still only match the first 5 characters.
	assert(ft_memcmp("Hello World", "Hello", 5) == 0);

	// Here we expect the strings to not be equal.
	assert(ft_memcmp("Hello World", "Hello Not World", 10) != 0);
} */
