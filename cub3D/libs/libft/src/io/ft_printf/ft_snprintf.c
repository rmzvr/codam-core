/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_snprintf.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 20:15:30 by bamarell      #+#    #+#                 */
/*   Updated: 2023/01/31 20:16:45 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft/io/ft_printf.h"

int	ft_snprintf(char *buf, size_t n, const char *fmt, ...)
{
	va_list	args;
	size_t	bytes_written;

	va_start(args, fmt);
	bytes_written = ft_vsnprintf(buf, n, fmt, args);
	va_end(args);
	return (bytes_written);
}
