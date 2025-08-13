/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:02:02 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 12:40:27 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	src_len;

	src_len = ft_strlen(src);
	dest = (char *)ft_calloc(src_len + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, src, src_len + 1);
	return (dest);
}

/* #include <assert.h>

void	assert_addr_not_eq(void *c1, void *c2)
{
	assert(c1 != c2);
}

void	assert_str_eq(char *s1, char *s2)
{
	assert(strcmp(s1, s2) == 0);
}

int	main()
{
	char	*str;
	char	*s_dup;

	str = "Hello";
	s_dup = ft_strdup(str);
	// We expect the string to actually be a copy
	// and not point to the same address.
	assert_addr_not_eq(str, s_dup);

	// We expect both of the strings to match.
	assert_str_eq(s_dup, str);
} */
