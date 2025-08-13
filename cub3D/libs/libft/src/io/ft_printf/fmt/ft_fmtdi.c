/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fmtdi.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 12:47:34 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/19 17:58:51 by bamarell      ########   odam.nl         */
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
	else if (value < 0)
		--format->width;
}

//
// Handle the format of the specifiers: d & i
//
size_t	ft_fmtdi(t_stream *stream, t_format format, va_list args)
{
	size_t	bytes_written;
	int		value;
	char	*str;

	bytes_written = 0;
	value = va_arg(args, int);
	str = ft_ltoa_base(value, BASE_10, 0);
	if (str == NULL)
		return (-1);
	handle_format_width(&format, value);
	bytes_written += ft_write_n(stream, format, str, value);
	free(str);
	return (bytes_written);
}
