/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fmtc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 12:14:41 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/24 13:44:01 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/ft_printf.h"

//
// Handle the format of the specifier: c
//
size_t	ft_fmtc(t_stream *stream, t_format format, va_list args)
{
	size_t	bytes_written;
	char	value;

	bytes_written = 0;
	value = (char) va_arg(args, int);
	if (~format.flags & FLAGS_LEFT_JUSTIFY)
		bytes_written += ft_write_pad(stream, ' ', format.width - 1);
	bytes_written += stream->callback(stream, &value, 1);
	if (format.flags & FLAGS_LEFT_JUSTIFY)
		bytes_written += ft_write_pad(stream, ' ', format.width - 1);
	return (bytes_written);
}
