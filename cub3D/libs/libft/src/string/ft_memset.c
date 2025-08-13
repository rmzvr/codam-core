/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 12:44:08 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 14:02:54 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		++i;
	}
	return (s);
}

/* #include <assert.h>

void	assert_str_eq(char *s1, char *s2)
{
	assert(strcmp(s1, s2) == 0);
}

int	main()
{
	// We fill up the array with 'a' characters
	char str[] = {'H', 'e', 'l', 'l', 'o', '\0'};
	ft_memset(str, 'a', 5);
	assert_str_eq(str, "aaaaa");

	// Clear the string
	ft_memset(str, '\0', 5);
	// Try to fill the string with 'a' but 0
	// of them (so leave the string intact)
	ft_memset(str, 'a', 0);
	// Expect the string to still be empty
	assert_str_eq(str, "");
} */
