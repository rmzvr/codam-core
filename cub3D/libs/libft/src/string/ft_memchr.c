/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 13:30:58 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 12:36:25 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (((unsigned char *)ptr)[i] == (unsigned char) ch)
			return ((unsigned char *)(ptr + i));
		++i;
	}
	return (NULL);
}

/* #include <assert.h>

void	assert_addr_eq(void *c1, void *c2)
{
	assert(c1 == c2);
}

int	main()
{
	char	*str;
	void	*addr;

	// We expect it to point to the first "l" or
	// third character in the string He[l]lo
	str = "Hello";
	addr = ft_memchr(str, 'l', 6);
	assert_addr_eq(addr, &str[2]);

	// We iterate over 0 characters and find none
	// so we expect a NUL back.
	addr = memchr(str, 'l', 0);
	assert_addr_eq(addr, NULL);

	str = "";
	addr = ft_memchr(str, '\0', 0);
	assert_addr_eq(addr, NULL);

	// Here we iterate over the whole string including
	// the NUL terminating character and compare the two
	// addresses to see if they match.
	str = "Hello";
	addr = ft_memchr(str, '\0', strlen(str));
	assert_addr_eq(addr, str[strlen(str)]);
} */
