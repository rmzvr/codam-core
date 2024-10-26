/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:59:39 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/26 11:48:46 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_char(char c, int str_len)
{
	ft_putchar_fd(c, 1);
	str_len++;
	return (str_len);
}

static int	ft_print_str(va_list args, const char *format)
{
	int	str_len;

	str_len = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format >= '\a' && *format <= '\r')
			{
				str_len = ft_print_char('%', str_len);
				continue ;
			}
			str_len = ft_handle_conv_specs(args, *format, str_len);
		}
		else
		{
			str_len = ft_print_char(*format, str_len);
		}
		if (*format != '\0')
			format++;
	}
	return (str_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		str_len;

	va_start(args, format);
	str_len = ft_print_str(args, format);
	va_end(args);
	return (str_len);
}
