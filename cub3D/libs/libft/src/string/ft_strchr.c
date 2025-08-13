/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 13:04:06 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 12:38:28 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	str_len;

	str_len = ft_strlen(s);
	return ((char *)ft_memchr(s, c, str_len + 1));
}

/* #include <assert.h>

void	assert_addr_eq(void *c1, void *c2)
{
	assert(c1 == c2);
}

int	main()
{
	char	*str;
	char	*m_str;

	str = "abc123";
	m_str = ft_strchr(str, '1'); // => [..., 'b', 'c']['1', ...]
	// See if the libc implementation gives back the same value.
	assert_addr_eq(m_str, strchr(str, '1'));
	// We expect it to point to the 4th character of the string
	// as illustrated above.
	assert_addr_eq(m_str, &str[3]);

	// We iterate over the whole string, including the NUL
	// terminating character and see if the addresses match.
	m_str = ft_strchr(str, '\0');
	assert_addr_eq(m_str, &str[strlen(str)]);

	// We look for a character that's not inside of the string.
	m_str = ft_strchr(str, 'd');
	assert(m_str == NULL);
} */
