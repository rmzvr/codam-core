/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_s.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 12:30:52 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/24 14:14:53 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"
#include "libft/math.h"

#include "libft/io/ft_printf.h"

//
// Handle writing anything string related in a centralized space.
// This is used by `fmtc` and `fmtp`.
//
// Get the smallest of the two, since we don't want to read "less" than
// 0 characters, we require this check. also a clamp / max to str_len
// since we can't read more than len characters.
//
// if precision < 0 && str == NULL then str_len should be 0
// format.precision < N - where N is length of "(null)".
//
size_t	ft_write_s(t_stream *stream, t_format format, char *str)
{
	size_t	bytes_written;
	int		str_len;

	bytes_written = 0;
	if (str == NULL)
	{
		if (format.precision != -1 && format.precision < 6)
			format.precision = 0;
		str = "(null)";
	}
	str_len = ft_strlen(str);
	if (format.precision > -1)
		str_len = ft_min(format.precision, str_len);
	if (format.width > str_len && ~ format.flags & FLAGS_LEFT_JUSTIFY)
		bytes_written += ft_write_pad(stream, ' ', format.width - str_len);
	bytes_written += stream->callback(stream, str, str_len);
	if (format.width > str_len && format.flags & FLAGS_LEFT_JUSTIFY)
		bytes_written += ft_write_pad(stream, ' ', format.width - str_len);
	return (bytes_written);
}
