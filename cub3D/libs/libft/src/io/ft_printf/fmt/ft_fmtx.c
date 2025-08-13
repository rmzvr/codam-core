/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fmtx.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 16:14:53 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/19 13:45:46 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/string.h"
#include "libft/stdlib.h"

#include "libft/io/ft_printf.h"

static char	*ft_get_format_base(t_format format)
{
	if (format.specifier == 'x')
		return (LOW_BASE_16);
	return (UP_BASE_16);
}

static void	handle_format_width(t_format *format)
{
	if (format->flags & FLAGS_PRECEED_SIGN)
		--format->width;
	else if (format->flags & FLAGS_PRECEED_SPACE)
		--format->width;
	if (format->flags & FLAGS_PRECEED_ZERO)
		format->width -= 2;
}

//
// Handle the format of the specifiers: x & X
//
size_t	ft_fmtx(t_stream *stream, t_format format, va_list args)
{
	size_t			bytes_written;
	char			*str;
	unsigned int	value;

	bytes_written = 0;
	value = va_arg(args, unsigned int);
	str = ft_ltoa_base(value, ft_get_format_base(format), 0);
	if (str == NULL)
		return (-1);
	handle_format_width(&format);
	bytes_written += ft_write_n(stream, format, str, value);
	free(str);
	return (bytes_written);
}
