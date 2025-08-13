/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:57:18 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/12 12:02:46 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (haystack == NULL || needle == NULL)
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	if (needle_len == 0 || haystack == needle)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle[j] && j < needle_len && i + j < len)
			++j;
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		j = 0;
		++i;
	}
	return (NULL);
}

/* #include <assert.h>

void	assert_str_eq(char *s1, char *s2)
{
	assert(strcmp(s1, s2) == 0);
}

void	assert_addr_eq(void *c1, void *c2)
{
	assert(c1 == c2);
}

int	main()
{
	char	*result;
	char	*str;

	str = "Hello World";
	result = ft_strnstr(str, "World", 13);
	assert_str_eq(result, "World");
	assert_addr_eq(result, &str[6]); // str[6] = {'W', ...}

	// A needle that is not inside of the string we expect
	// to give back NULL.
	str = "A placeholder",
	result = ft_strnstr(str, "nothing", 20);
	assert(result == NULL);

	// For the following 3 tests, we expect it to give the
	// haystack.
	str = "Hello World";
	result = ft_strnstr(str, "", 13);
	assert_str_eq(result, "Hello World");
	assert_addr_eq(result, str);

	result = ft_strnstr(str, "", 0);
	assert_str_eq(result, "Hello World");
	assert_addr_eq(result, str);

	str = "";
	result = ft_strnstr(str, "", 0); // "", "", 0
	assert_str_eq(result, "");
	assert_addr_eq(result, str);

	// Both needle and haystack are pointing to the same
	// address.
	str = "Hello";
	result = ft_strnstr(str, str, 6);
	assert_str_eq(result, str);
	assert_addr_eq(result, str);

	// If the needle is empty or NULL we return the haystack.
	result = ft_strnstr(str, NULL, 0);
	assert_addr_eq(result, str);

	// If the haystack is NULL we expect it to return NULL
	// regardless of what the needle's value is.
	result = ft_strnstr(NULL, "", 0);
	assert(result == NULL);
} */
