/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_mem_specs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:34:51 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/30 11:35:39 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_p_spec(va_list args, int str_len)
{
	unsigned long	addr;
	char			*hex_prefix_str;
	char			*null_pointer_str;
	char			*base;
	size_t			base_len;

	hex_prefix_str = "0x";
	null_pointer_str = "(nil)";
	base = "0123456789abcdef";
	base_len = ft_strlen(base);
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
		str_len += ft_put_unum(addr, base, base_len);
	}
	return (str_len);
}

static int	ft_print_x_spec(va_list args, int str_len)
{
	unsigned int	i;
	char			*base;
	size_t			base_len;

	base = "0123456789abcdef";
	base_len = ft_strlen(base);
	i = va_arg(args, unsigned int);
	str_len += ft_put_unum(i, base, base_len);
	return (str_len);
}

static int	ft_print_ux_spec(va_list args, int str_len)
{
	unsigned int	i;
	char			*base;
	size_t			base_len;

	base = "0123456789ABCDEF";
	base_len = ft_strlen(base);
	i = va_arg(args, unsigned int);
	str_len += ft_put_unum(i, base, base_len);
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
