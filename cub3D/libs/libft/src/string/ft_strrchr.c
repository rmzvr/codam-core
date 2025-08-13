/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 13:41:22 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 11:45:43 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	str_len;

	str_len = ft_strlen(str);
	while (str_len >= 0)
	{
		if (str[str_len] == (char) ch)
			return ((char *)(str + str_len));
		--str_len;
	}
	return (NULL);
}

/* #include <assert.h>

// Are the two characters pointing to the
// same address?
void	assert_addr_eq(void *c1, void *c2)
{
	assert(c1 == c2);
}

// Opposite of the function above
void	assert_addr_not_eq(void *c1, void *c2)
{
	assert(c1 != c2);
}

int	main()
{
	char	*str;
	char	*m_str;

	str = "aba";
	m_str = ft_strrchr(str, 'a');
	// See if the libc implementation gives back the same value.
	assert_addr_eq(m_str, strrchr(str, 'a'));
	// We expect it to point to the 3rd character of the string
	// as illustrated above.
	assert_addr_eq(m_str, &str[2]);
	// We expect the first 'a' not to point to the
	// same address as the last 'a'
	assert_addr_not_eq(m_str, strchr(str, 'a'));

	// We look for a character that's not inside of the string.
	m_str = ft_strrchr(str, 'd');
	assert(m_str == NULL);
} */
