/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_mem_specs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:34:51 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/26 11:35:05 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex(unsigned long l, int to_upper)
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

static int	ft_print_p_spec(va_list args, int str_len)
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
		str_len += ft_strlen(null_pointer_str);
	}
	else
	{
		ft_putstr_fd(hex_prefix_str, 1);
		str_len += ft_strlen(hex_prefix_str);
		str_len += ft_puthex(addr, 0);
	}
	return (str_len);
}

static int	ft_print_x_spec(va_list args, int str_len)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	str_len += ft_puthex(i, 0);
	return (str_len);
}

static int	ft_print_ux_spec(va_list args, int str_len)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	str_len += ft_puthex(i, 1);
	return (str_len);
}

int	ft_handle_mem_specs(va_list args, char conv_spec, int str_len)
{
	if (conv_spec == 'p')
	{
		str_len = ft_print_p_spec(args, str_len);
	}
	else if (conv_spec == 'x')
	{
		str_len = ft_print_x_spec(args, str_len);
	}
	else if (conv_spec == 'X')
	{
		str_len = ft_print_ux_spec(args, str_len);
	}
	return (str_len);
}
