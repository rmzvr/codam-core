/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 12:19:23 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 11:38:22 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

static int	ft_isinset(const char ch, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (ch == set[i])
			return (1);
		++i;
	}
	return (0);
}

static int	ft_startswith2(const char *str, const char *set)
{
	return (ft_isinset(str[0], set));
}

char	*ft_strtrim(const char *str, const char *set)
{
	size_t	start_offset;
	size_t	end_offset;
	size_t	str_len;
	size_t	total_length;

	start_offset = 0;
	end_offset = 0;
	str_len = ft_strlen(str);
	while (ft_startswith2(str + start_offset, set))
		++start_offset;
	while (str_len > 0 && str_len > start_offset)
	{
		if (!ft_isinset(str[str_len - 1], set))
			break ;
		++end_offset;
		--str_len;
	}
	total_length = ft_strlen(str) - start_offset - end_offset;
	return (ft_substr(str, start_offset, total_length));
}

/* #include <assert.h>

void	assert_str_eq(char *s1, char *s2)
{
	assert(strcmp(s1, s2) == 0);
}

int	main()
{
	assert_str_eq(
		ft_strtrim("   +hello --- abc +  ", " +"),
		"hello --- abc"
	);
	assert_str_eq(
		ft_strtrim("   +++   +", " +"),
		""
	);
	assert_str_eq(
		ft_strtrim("", "+"),
		""
	);
	assert_str_eq(
		ft_strtrim("abc", ""),
		"abc"
	);
	// Whenever the string is not on the sides
	// but rather in the middle
	assert_str_eq(
		ft_strtrim("123abc321", "abc"),
		"123abc321"
	);
} */
