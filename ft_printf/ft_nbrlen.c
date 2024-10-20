/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 10:53:00 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/20 17:37:06 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(int n)
{
	long	long_num;
	size_t	nbr_length;

	long_num = n;
	nbr_length = 0;
	if (long_num < 0)
	{
		long_num = long_num * -1;
		nbr_length++;
	}
	while (long_num >= 10)
	{
		nbr_length++;
		long_num = long_num / 10;
	}
	nbr_length++;
	return (nbr_length);
}
