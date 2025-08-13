/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_n.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/22 12:42:11 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/24 16:53:25 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/string.h"
#include "libft/math.h"

#include "libft/io/ft_printf.h"

//
// Handle writing anything string related in a centralized space.
// This is used by `fmtc` and `fmtp`.
//
static size_t	handle_flags(t_stream *st, t_format format, long int val)
{
	size_t	bytes_written;

	bytes_written = 0;
	if (val != 0 && (format.specifier == 'x' || format.specifier == 'X'))
	{
		if (~format.flags & FLAGS_PRECEED_ZERO)
			return (0);
		bytes_written += st->callback(st, "0", 1);
		bytes_written += st->callback(st, &format.specifier, 1);
	}
	else
	{
		if (format.specifier != 'p' && val < 0)
			bytes_written += st->callback(st, "-", 1);
		else if (format.flags & FLAGS_PRECEED_SIGN && val >= 0)
			bytes_written += st->callback(st, "+", 1);
		else if (format.flags & FLAGS_PRECEED_SPACE && val >= 0)
			bytes_written += st->callback(st, " ", 1);
	}
	if (val != 0 && format.specifier == 'p')
		bytes_written += st->callback(st, "0x", 2);
	return (bytes_written);
}

static size_t	prepad(t_stream *st, t_format *f, size_t slen, long int val)
{
	size_t	bytes_written;
	size_t	prec;

	bytes_written = 0;
	prec = ft_max(0, f->precision - slen);
	f->width -= slen + prec;
	if (~f->flags & FLAGS_LEFT_JUSTIFY && f->pad == ' ')
	{
		bytes_written += ft_write_pad(st, ' ', f->width);
		f->width = 0;
	}
	bytes_written += handle_flags(st, *f, val);
	if (f->flags & FLAGS_LEFT_JUSTIFY)
		bytes_written += ft_write_pad(st, '0', prec);
	else
		bytes_written += ft_write_pad(st, '0', f->width + prec);
	if (f->width < 0 && prec > 0 && ~ f->flags & FLAGS_LEFT_JUSTIFY)
		bytes_written += ft_write_pad(st, '0', prec);
	return (bytes_written);
}

//
// A general purpose (x, X, u, d & i) implementation to handle precision
// and padding in a centralized area. It's purpose is to write a "number"
// whether that'd be a base16 or base10 number.
//
// For whatever reason, precision of `0` is only actually "applied"
// in the sense that it actually trims / limits the max width of the
// string displayed, whenever the value given is "0" (lit. int 0).
//
// e.g. "%.0d" with the value (lit. int) 0.
//
// The "precision" variable is used to acquire the amount of "filler"
// characters we need. This is calculated by subtracting the precision the user
// wants, by the length of the string (which will always take priority). This
// value is also clamped to a min of 0 since it can go negative.
//
// If we're required to display space characters at the start, we set the width
// to ZERO (lit. 0) afterwards because we already know the width won't require
// any additional characters anymore (because it's not left justified).
//
// After we display the filler padding, filler characters and the number itself
// we check if we still need filler characters afterwards. We only need to
// display more characters if we don't have any left justification. We subtract
// the amount of characters we already wrote from the width (which I suppose we
// can also clamp to zero, even though the `write_pad` function checks for
// negative values anyway.
//
size_t	ft_write_n(t_stream *st, t_format format, char *str, long int value)
{
	size_t	bytes_written;
	size_t	str_len;

	bytes_written = 0;
	str_len = ft_strlen(str);
	if (format.precision == 0 && value == 0 && format.specifier != 'p')
		str_len = 0;
	bytes_written += prepad(st, &format, str_len, value);
	bytes_written += st->callback(st, str, str_len);
	if (~format.flags & FLAGS_LEFT_JUSTIFY)
		format.width -= bytes_written;
	bytes_written += ft_write_pad(st, ' ', format.width);
	return (bytes_written);
}
