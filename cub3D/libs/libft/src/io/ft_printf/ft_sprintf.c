/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 20:13:33 by bamarell      #+#    #+#                 */
/*   Updated: 2023/01/31 20:15:27 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft/io/ft_printf.h"

int	ft_sprintf(char *buf, const char *fmt, ...)
{
	va_list	args;
	size_t	bytes_written;

	va_start(args, fmt);
	bytes_written = ft_vsprintf(buf, fmt, args);
	va_end(args);
	return (bytes_written);
}
