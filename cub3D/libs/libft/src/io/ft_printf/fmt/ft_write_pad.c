/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_pad.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 12:17:36 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/18 13:51:08 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"
#include "libft/math.h"

#include "libft/io/ft_printf.h"

// Pad chunk size
#define PAD_SIZE 32

//
// Handle general padding
//
// Rendering / displaying or outputting the pad characters in chunks
// improves the performance by calling the syscall less frequently.
//
size_t	ft_write_pad(t_stream *stream, char pad, int length)
{
	char	pads[PAD_SIZE];
	size_t	bytes_written;

	bytes_written = 0;
	if (length <= 0)
		return (0);
	ft_memset(pads, pad, PAD_SIZE);
	while (length != 0)
	{
		bytes_written += stream->callback(stream, pads,
				ft_min(length, PAD_SIZE));
		length -= ft_min(length, PAD_SIZE);
	}
	return (bytes_written);
}
