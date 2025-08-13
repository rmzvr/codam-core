/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/28 11:04:02 by bamarell      #+#    #+#                 */
/*   Updated: 2023/11/28 11:04:02 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft/io/ft_printf.h"

int	ft_fprintf(t_stream *stream, const char *fmt, ...)
{
	int		bytes_written;
	va_list	args;

	va_start(args, fmt);
	bytes_written = ft_vfprintf(stream, fmt, args);
	va_end(args);
	return (bytes_written);
}
