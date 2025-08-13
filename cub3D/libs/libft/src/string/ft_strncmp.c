/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:19:15 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 12:01:55 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' || s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		++i;
	}
	return (0);
}

/* #include <assert.h>

void	assert_str_eq(char *s1, char *s2)
{
	assert(strcmp(s1, s2) == 0);
}

int	main()
{
	char	*str;

	str = "abc123";
	assert(ft_strncmp(str, "abc", 3) == 0);
	assert(ft_strncmp(str, "Hello Not World", 20) != 0);
	// We only check 1 character and they match in an empty string.
	assert(ft_strncmp("", "", 1) == 0);
	// If the parameter "n" or "size" is sent as a value
	// holding a zero (0), we say the string is the same.
	assert(ft_strncmp("", "", 0) == 0);
} */
