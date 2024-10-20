/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_spec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:34:40 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/20 17:18:00 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p_spec(va_list args, int char_count)
{
	unsigned long	addr;
	char			*hex_prefix_str;
	char			*null_pointer_str;

	hex_prefix_str = "0x";
	null_pointer_str = "(nil)";
	addr = va_arg(args, unsigned long);
	if (addr == 0)
	{
		ft_putstr_fd(null_pointer_str, 1);
		char_count += ft_strlen(null_pointer_str);
	}
	else
	{
		ft_putstr_fd(hex_prefix_str, 1);
		char_count += ft_strlen(hex_prefix_str);
		char_count += ft_puthex(addr, 0);
	}
	return (char_count);
}
