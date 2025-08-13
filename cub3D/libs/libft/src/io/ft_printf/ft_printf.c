/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 14:12:37 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/16 13:14:32 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	bytes_written;

	va_start(args, format);
	bytes_written = ft_vprintf(format, args);
	va_end(args);
	return (bytes_written);
}
