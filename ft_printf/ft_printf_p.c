/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:59:39 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/18 20:56:03 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthexbase(unsigned long l)
{
	char	*base;

	base = "0123456789abcdef";
	if (l >= 16)
	{
		ft_puthexbase(l / 16);
	}
	else
	{
		ft_putstr_fd("0x", 1);
	}
	ft_putchar_fd(base[l % 16], 1);
}

void	ft_printf_p(void *addr)
{
	unsigned long	l;

	l = (unsigned long)addr;
	ft_puthexbase(l);
}
