/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vfprintf.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/28 11:03:53 by bamarell      #+#    #+#                 */
/*   Updated: 2023/11/28 14:02:17 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft/string.h"

#include "libft/io/ft_printf.h"

//
// Handle a format expression which is structured or "prototyped"
// like the following:
//
// %[flags][width][.precision][length]specifier
//
static int	handle_fmt(t_stream *stream, const char **fmt, va_list args)
{
	t_format	format;

	if (**fmt != '%' && (*fmt)++)
		return (0);
	if ((*fmt)[1] == '\0')
		return (-1);
	format = parse_format(fmt, args);
	if (format.specifier == '0')
		return (0);
	return (handle_format(stream, format, args));
}

int	stdstream_write(t_stream *stream, const char *fmt, size_t length)
{
	return (write(stream->fd, fmt, length));
}

//
// The general approach of this function is to read the buffer or format
// given in chunks like the following example:
//
// ```
// Hello %s, I'm %d years old.
// ```
//
// And will be read and consumed like the following:
//
// [Hello ]{%s}[, I'm]{%d}[ years old.]
//
// The part between the brackets ([ & ]) is read and displayed at once
// as opposed to reading each character and writing it individually.
//
// It basically starts at the first character "H" and looks for the first
// "%" occurrence and prints anything in between if necessary. After it
// prints that, it consumes the the actual "format", a sequence of
// characters opened with "%" and followed by optional flags, closed by
// one of the specifiers supported & defined in the header.
// It repeats this process until it can not find a "%" character anymore.
//
// Afterwards, it checks whether there's still anything after the last
// part it just handled, and if so, prints out that remaining string.
//
// https://cplusplus.com/reference/cstdio/vfprintf/
//
int	ft_vfprintf(t_stream *stream, const char *fmt, va_list args)
{
	size_t		bytes_written;
	ssize_t		handle_written;
	const char	*expression;

	bytes_written = 0;
	expression = ft_strchr(fmt, '%');
	while (expression != NULL)
	{
		if ((expression - fmt) > 0)
			bytes_written += stream->callback(stream, fmt, expression - fmt);
		handle_written = handle_fmt(stream, &expression, args);
		if (handle_written == -1)
			return (-1);
		bytes_written += handle_written;
		fmt = expression;
		expression = ft_strchr(fmt, '%');
	}
	if (*fmt != '\0')
		bytes_written += stream->callback(stream, fmt, ft_strlen(fmt));
	return (bytes_written);
}
