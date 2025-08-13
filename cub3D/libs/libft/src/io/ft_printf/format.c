/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/14 14:51:41 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/25 12:02:03 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/ft_printf.h"

//
// Initialize and setup the base of a "format".
//
// "Specifier" defaults back to a '0' character because it's easy to
// identify. We can then easily validate whether a valid specifier was
// found and applied (e.g. `format.specifier == '0'`).
//
// We set precision to "-1" because 0 is not a viable default value.
// A precision of value "0" can be set and implies that the max width
// is "0" even though it might not have been set. Therefore we set
// precision to "-1" easily tell whether it was set intentionally.
//
// "Pad" defaults to a space because that should be the default padding
// character that is used to pad a string. It can optionally can be
// changed to a "0" using the `FLAGS_PAD_ZERO` flag ("0").
//
void	init_format(t_format *format)
{
	format->specifier = '0';
	format->pad = ' ';
	format->precision = -1;
	format->flags = FLAGS_NONE;
	format->length = LENGTH_NONE;
	format->width = 0;
}

int	handle_format(t_stream *stream, t_format format, va_list args)
{
	if (format.specifier == 'c')
		return (ft_fmtc(stream, format, args));
	else if (format.specifier == 's')
		return (ft_fmts(stream, format, args));
	else if (format.specifier == 'd' || format.specifier == 'i')
		return (ft_fmtdi(stream, format, args));
	else if (format.specifier == 'x' || format.specifier == 'X')
		return (ft_fmtx(stream, format, args));
	else if (format.specifier == 'u')
		return (ft_fmtu(stream, format, args));
	else if (format.specifier == 'p')
		return (ft_fmtp(stream, format, args));
	else if (format.specifier == '%')
		return (stream->callback(stream, "%%", 1));
	return (0);
}
