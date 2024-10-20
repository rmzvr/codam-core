/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:35:29 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/20 17:37:06 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int i)
{
	char	digit;
	int		count;

	count = 0;
	if (i > 9)
	{
		count += ft_putunbr(i / 10);
	}
	digit = i % 10 + '0';
	write(1, &digit, 1);
	count++;
	return (count);
}
