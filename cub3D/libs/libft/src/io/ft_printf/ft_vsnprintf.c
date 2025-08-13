/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vsnprintf.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 19:31:33 by bamarell      #+#    #+#                 */
/*   Updated: 2023/01/31 20:17:47 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft/string.h"

#include "libft/io/ft_printf.h"

// If the buffer is full we don't want to attempt writing anything else to it.
// NOTE: probably better to just read output length from ft_vfprintf invocation
// below and adjusting / moving the terminator accordingly.
int	stdstream_writebuf(t_stream *stream, const char *str, size_t length)
{
	size_t	max_len;

	max_len = (size_t)(stream->io->wend - stream->io->wptr);
	if (stream->io->wend != (char *) -1 && max_len == 0)
		return (length);
	ft_memcpy(stream->io->wptr, str, length);
	stream->io->wptr += length;
	stream->io->wptr[0] = '\0';
	return (length);
}

// TODO: implement 0-size overflow properly
int	ft_vsnprintf(char *buf, size_t n, const char *fmt, va_list args)
{
	t_stream	stream;
	t_stream_io	stream_io;
	char		*end;

	if (n == 0)
		end = ft_strchr(buf, '\0');
	else if (buf + n > buf)
		end = (char *) buf + n;
	else
		end = (char *) -1;
	stream_io = (t_stream_io){
		.size = n - 1,
		.wptr = buf,
		.wbase = buf,
		.wend = end,
	};
	stream = (t_stream){
		.fd = STDOUT_FILENO,
		.callback = stdstream_writebuf,
		.io = &stream_io
	};
	if (n == 0)
		return (-1);
	buf[0] = '\0';
	return (ft_vfprintf(&stream, fmt, args));
}
