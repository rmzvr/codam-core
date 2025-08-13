/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 21:09:11 by bamarell      #+#    #+#                 */
/*   Updated: 2024/02/06 21:11:34 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ctype.h"

long long	ft_atoll(const char *str)
{
	size_t		i;
	long long	result;
	int			sign;

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
