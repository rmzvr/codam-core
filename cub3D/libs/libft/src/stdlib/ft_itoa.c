/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 15:20:05 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 12:19:22 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"
#include "libft/malloc.h"
#include "libft/string.h"

static size_t	ft_getdigits(int nb)
{
	size_t	i;

	i = 1;
	while (nb / 10)
	{
		nb /= 10;
		++i;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	digits;

	digits = ft_getdigits(n);
	if (n < 0)
		++digits;
	str = (char *)ft_calloc(digits + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[--digits] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (str);
}

/* #include <assert.h>
#include <limits.h>

void	assert_str_eq(char *s1, char *s2)
{
	assert(strcmp(s1, s2) == 0);
}

int	main()
{
	char	*text;

	text = ft_itoa(1234);
	assert_str_eq(text, "1234");

	text = ft_itoa(-1234);
	assert_str_eq(text, "-1234");

	text = ft_itoa(-0);
	assert_str_eq(text, "0");

	text = ft_itoa(INT_MIN);
	assert_str_eq(text, "-2147483648");

	text = ft_itoa(INT_MAX);
	assert_str_eq(text, "2147483647");
} */
