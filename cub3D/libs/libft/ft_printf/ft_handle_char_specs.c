/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char_specs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:35:00 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/26 11:35:05 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_c_spec(va_list args, int str_len)
{
	unsigned char	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	str_len++;
	return (str_len);
}

static int	ft_print_s_spec(va_list args, int str_len)
{
	char	*str;
	char	*null_str;

	null_str = "(null)";
	str = va_arg(args, char *);
	if (str == NULL)
	{
		ft_putstr_fd(null_str, 1);
		str_len += ft_strlen(null_str);
	}
	else
	{
		str_len += ft_strlen(str);
		ft_putstr_fd(str, 1);
	}
	return (str_len);
}

static int	ft_print_percent_spec(int str_len)
{
	ft_putchar_fd('%', 1);
	str_len++;
	return (str_len);
}

int	ft_handle_char_specs(va_list args, char conv_spec, int str_len)
{
	if (conv_spec == 'c')
	{
		str_len = ft_print_c_spec(args, str_len);
	}
	else if (conv_spec == 's')
	{
		str_len = ft_print_s_spec(args, str_len);
	}
	else if (conv_spec == '%')
	{
		str_len = ft_print_percent_spec(str_len);
	}
	return (str_len);
}
