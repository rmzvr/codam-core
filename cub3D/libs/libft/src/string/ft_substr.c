/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 15:21:22 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 11:33:35 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/malloc.h"
#include "libft/string.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*substr;

	str_len = ft_strlen(str);
	if (start > str_len)
		len = 0;
	if (len > str_len - start)
		len = str_len - start;
	substr = (char *)ft_calloc(len + 1, sizeof(char));
	if (substr == NULL)
		return (NULL);
	if (str_len >= start)
		ft_memcpy(substr, str + start, len);
	return (substr);
}

/* #include <assert.h>

void	assert_str_eq(char *s1, char *s2)
{
	assert(strcmp(s1, s2) == 0);
}

int	main()
{
	char	*str;

	str = "Hello World";
	assert_str_eq(ft_substr(str, 0, 5), "Hello"); // eq. "Hello"
	// Whenever the "len" parameter is beyond the length of the original
	// string we basically just clamp that value to the length of the string
	// so we don't attempt to copy more than the string.
	assert_str_eq(ft_substr(str, 0, 50), "Hello World"); // eq. "Hello World"
	assert_str_eq(ft_substr("abc123def", 3, 3), "123"); // eq. "123"
	assert_str_eq(ft_substr("", 0, 2), ""); // eq. ""
} */
