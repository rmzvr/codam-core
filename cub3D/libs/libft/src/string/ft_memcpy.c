/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 12:55:14 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/12 12:05:16 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL || src == NULL)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		++i;
	}
	return (dest);
}

/* #include <assert.h>

void	assert_str_eq(char *s1, char *s2)
{
	assert(strcmp(s1, s2) == 0);
}

int	main()
{
	char	*str;
	char	*dest;

	// We copy over the bytes at str to
	// dest and see if the string matches.
	str = "1234567890";
	dest = ft_calloc(11, sizeof(char));
	ft_memcpy(dest, str, strlen(str));
	assert_str_eq(dest, str);

	ft_memset(dest, '\0', 10); // Reset the string

	ft_memcpy(dest, str, 5); // We only copy the first 5 characters
	assert_str_eq(dest, "12345");

	ft_memset(dest, '\0', 10); // Reset the string

	// We copy no bytes and expect the string to remain empty.
	ft_memcpy(dest, str, 0);
	assert_str_eq(dest, "");
} */
