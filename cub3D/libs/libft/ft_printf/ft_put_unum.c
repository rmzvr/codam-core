/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:51:35 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/30 11:36:19 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unum(unsigned long n, char *base, size_t base_len)
{
	int		count;

	count = 0;
	if (n >= base_len)
	{
		count += ft_put_unum(n / base_len, base, base_len);
	}
	ft_putchar_fd(base[n % base_len], 1);
	count++;
	return (count);
}
