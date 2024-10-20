/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 10:28:14 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/20 17:37:06 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long l, int to_upper)
{
	int		count;
	char	*hex_base;

	if (to_upper > 0)
		hex_base = "0123456789ABCDEF";
	else
		hex_base = "0123456789abcdef";
	count = 0;
	if (l >= 16)
	{
		count += ft_puthex(l / 16, to_upper);
	}
	ft_putchar_fd(hex_base[l % 16], 1);
	count++;
	return (count);
}
