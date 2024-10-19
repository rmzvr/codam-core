/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:59:39 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/19 16:42:42 by rzvir            ###   ########.fr       */
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
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				unsigned char c = (unsigned char)va_arg(args, int);
				// ft_putstr_fd("ft_printf %c: ", 1);
				ft_printf_c(c);
				// printf("printf %c", c);
				// ft_putchar_fd('\n', 1);
			}
			// else if (*format == 's')
			// {
			// 	char *str = va_arg(args, char *);
			// 	// ft_putstr_fd("ft_printf %s: ", 1);
			// 	ft_printf_s(str);
			// 	// printf("printf %s", str);
			// 	// ft_putchar_fd('\n', 1);
			// }
			// else if (*format == 'p')
			// {
			// 	void *addr = va_arg(args, void *);
			// 	// ft_putstr_fd("ft_printf %p: ", 1);
			// 	ft_printf_p(addr);
			// 	// printf("printf %p", addr);
			// 	// ft_putchar_fd('\n', 1);
			// }
			// else if (*format == 'd' || *format == 'i')
			// {
			// 	int i = va_arg(args, int);
			// 	// ft_putstr_fd("ft_printf %d || %i: ", 1);
			// 	ft_printf_d(i);
			// 	// printf("printf %d", i);
			// 	// ft_putchar_fd('\n', 1);
			// }
			// else if (*format == 'u')
			// {
			// 	unsigned int u = va_arg(args, unsigned int);
			// 	// ft_putstr_fd("ft_printf %u: ", 1);
			// 	ft_printf_u(u);
			// 	// printf("printf %u", u);
			// 	// ft_putchar_fd('\n', 1);
			// }
			// else if (*format == 'x')
			// {
			// 	unsigned int x = va_arg(args, unsigned int);
			// 	// ft_putstr_fd("ft_printf %x: ", 1);
			// ft_printf_x(x);
			// 	// printf("printf %x", x);
			// 	// ft_putchar_fd('\n', 1);
			// }
			// else if (*format == 'X')
			// {
			// 	unsigned int upper_x = va_arg(args, unsigned int);
			// 	// ft_putstr_fd("ft_printf %X: ", 1);
			// 	ft_printf_upper_x(upper_x);
			// 	// printf("printf %X", upper_x);
			// 	// ft_putchar_fd('\n', 1);
			// }
			// else if (*format == '%')
			// {
			// 	// ft_putstr_fd("ft_printf %%: ", 1);
			// 	ft_putchar_fd('%', 1);
			// 	// printf("printf ");
			// 	// ft_putchar_fd('\n', 1);
			// }
		}
		else
		{
			ft_printf_c(*format);
		}
		format++;
	}
	va_end(args);
	return (1);
}

/* int	main(void)
{
	char *str;

	str = "Hello!";
	// ft_printf("%c %s %p %d %u %x %X %%", 'c', "Aa", &str, 1, 4294967295, 195, 195);
	ft_printf("%c", '0');
	printf("\n");
	printf("%c", '0');

	// printf("\n");
	// printf("\n");
	// ft_printf(" %%%% ");
	// printf("\n");
	// printf(" %%%% ");

	// printf("\n");
	// printf("\n");
	// ft_printf(" %% %% %% ");
	// printf("\n");
	// printf(" %% %% %% ");
	return (0);
} */
