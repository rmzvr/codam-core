/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:59:39 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/19 18:05:52 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthexbase(unsigned int i)
{
	char	*base;

	base = "0123456789abcdef";
	if (i >= 16)
	{
		ft_puthexbase(i / 16);
	}
	ft_putchar_fd(base[i % 16], 1);
}

void	ft_printf_x(unsigned int i)
{
	ft_puthexbase(i);
}
