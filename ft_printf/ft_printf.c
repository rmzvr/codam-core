/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:59:39 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/18 22:02:11 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
	
	while (*format)
	{
		printf("*format: %c\n", *format);
		printf("va_arg: %s", va_arg(args, char *));
		format++;
		// if (*format == '%')
		// {
		// 	format++;
			
            // if (*format == 'd') {
            //     int i = va_arg(args, int);  // Get the next integer argument
            //     printf("Integer: %d\n", i);
            // } else if (*format == 'c') {
            //     char c = (char) va_arg(args, int);  // Get the next char argument (promoted to int)
            //     printf("Char: %c\n", c);
            // }
		// }
		// va_arg(args, char *);
		// format++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	// unsigned int	num;

	// num = 4294967291;
	ft_printf("%", "Aa");
	// ft_printf_upper_x(num);
	return (0);
}
