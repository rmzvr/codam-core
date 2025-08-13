/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fmtu.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 18:29:26 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/18 18:38:10 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/string.h"
#include "libft/stdlib.h"

#include "libft/io/ft_printf.h"

static void	handle_format_width(t_format *format, int value)
{
	if (format->flags & FLAGS_PRECEED_SIGN)
		--format->width;
	else if (format->flags & FLAGS_PRECEED_SPACE && value >= 0)
		--format->width;
}

//
// Handle the format of the specifier: u
//
size_t	ft_fmtu(t_stream *stream, t_format format, va_list args)
{
	size_t			bytes_written;
	unsigned int	value;
	char			*str;

	bytes_written = 0;
	value = va_arg(args, unsigned int);
	str = ft_utoa_base(value, BASE_10);
	if (str == NULL)
		return (-1);
	handle_format_width(&format, value);
	bytes_written += ft_write_n(stream, format, str, value);
	free(str);
	return (bytes_written);
}
