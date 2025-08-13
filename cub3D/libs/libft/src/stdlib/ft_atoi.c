/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 13:09:15 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 12:07:55 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ctype.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] != '\0' && ft_isspace(str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	while (ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		++i;
	}
	return (result * sign);
}

/* #include <assert.h>
#include <limits.h>

int	main()
{
	assert(ft_atoi("1234") == 1234);
	assert(ft_atoi("-1234") == -1234);
	assert(ft_atoi("   +123") == 123);
	// Since we have more than 1 sign, we consider
	// the string to be invalid and return 0.
	assert(ft_atoi(" --++123") == 0);
	// We expect atoi to only parse the initial part
	// of the string that represent numbers.
	assert(ft_atoi("  123abc") == 123);
	assert(ft_atoi("2147483647") == INT_MAX);
	assert(ft_atoi("-2147483648") == INT_MIN);

	assert(ft_atoi("     ") == 0);
} */
