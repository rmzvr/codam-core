/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/28 11:04:05 by bamarell      #+#    #+#                 */
/*   Updated: 2023/11/28 11:21:41 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/ft_printf.h"

int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list		args;
	int			bytes_written;

	va_start(args, fmt);
	bytes_written = ft_vdprintf(fd, fmt, args);
	va_end(args);
	return (bytes_written);
}
