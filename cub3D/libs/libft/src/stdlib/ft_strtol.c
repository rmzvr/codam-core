/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strol.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 00:00:00 by bamarell      #+#    #+#                 */
/*   Updated: 2024/02/02 00:00:00 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ctype.h"

static int	ft_isdigit_inbase(int c, int base)
{
	if (base <= 0)
		return (0);
	if (base <= 10)
		return (c >= '0' && c <= '0' + base);
	return (ft_isdigit(c)
		|| (c >= 'a' && c < 'a' + base - 10)
		|| (c >= 'A' && c < 'A' + base - 10));
}

static long	ft_ctol(int c)
{
	long	result;

	if (ft_isdigit(c))
		result = c - '0';
	else if (ft_islower(c))
		result = (c - 'a') + 10;
	else
		result = (c - 'A') + 10;
	return (result);
}

long	ft_strtol(const char *str, char **endptr, int base)
{
	size_t	i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	while (ft_isdigit_inbase(str[i], base))
	{
		result *= base;
		result += ft_ctol(str[i]);
		++i;
	}
	if (endptr != NULL)
		*endptr = (char *) str + i;
	return (result * sign);
}
