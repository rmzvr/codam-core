/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fmtp.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 16:14:53 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/23 12:35:12 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/string.h"
#include "libft/stdlib.h"

#include "libft/io/ft_printf.h"

// Removes 2 characters because we always add "0x"
// unless the value is NULL / 0
static void	handle_format_width(t_format *format, int value)
{
	if (format->flags & FLAGS_PRECEED_SIGN && value != 0)
		--format->width;
	else if (format->flags & FLAGS_PRECEED_SPACE && value != 0)
		--format->width;
	if (value != 0)
		format->width -= 2;
}

//
// Handle the format of the specifier: p
//
// When the value we're provided is equal to ZERO (lit. 0) we're assuming it's
// basically a NULL (or nil pointer).
//
// We can't have any precision if the value is NULL, it's basically not meant
// to have any effect on the actual output ("nil"). That is why the precision
// is then *always* set to "-1".
//
size_t	ft_fmtp(t_stream *stream, t_format format, va_list args)
{
	size_t				bytes_written;
	char				*str;
	unsigned long int	value;

	bytes_written = 0;
	value = va_arg(args, unsigned long int);
	if (value == 0)
		str = ft_strdup("(nil)");
	else
		str = ft_ultoa_base(value, LOW_BASE_16);
	if (str == NULL)
		return (-1);
	handle_format_width(&format, value);
	if (value != 0)
	{
		if (format.precision != -1)
			format.pad = ' ';
		bytes_written += ft_write_n(stream, format, str, value);
	}
	else
	{
		format.precision = -1;
		bytes_written += ft_write_s(stream, format, str);
	}
	return (free(str), bytes_written);
}
