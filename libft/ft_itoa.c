/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:06:08 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/11 18:26:12 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	long	long_num;
	size_t	nbr_length;

	long_num = n;
	nbr_length = 0;
	if (long_num < 0)
	{
		long_num = long_num * -1;
	}
	while (long_num >= 10)
	{
		nbr_length++;
		long_num = long_num / 10;
	}
	nbr_length++;
	return (nbr_length);
}

char	*ft_itoa(int n)
{
	long	long_num;
	char	*digit_str;
	size_t	nbr_length;

	long_num = n;
	nbr_length = ft_nbrlen(n);
	if (n < 0)
	{
		nbr_length++;
		long_num = long_num * -1;
	}
	digit_str = (char *)malloc((nbr_length + 1) * sizeof(char));
	digit_str[nbr_length] = '\0';
	while (nbr_length > 0)
	{
		nbr_length--;
		digit_str[nbr_length] = long_num % 10 + '0';
		long_num = long_num / 10;
	}
	if (n < 0)
	{
		digit_str[0] = '-';
	}
	return (digit_str);
}
