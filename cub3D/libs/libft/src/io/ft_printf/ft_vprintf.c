/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/14 14:51:33 by bamarell      #+#    #+#                 */
/*   Updated: 2023/11/28 14:17:47 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft/io/ft_printf.h"

int	ft_vprintf(const char *fmt, va_list args)
{
	t_stream	stream;

	stream = (t_stream){
		.fd = STDOUT_FILENO,
		.callback = stdstream_write
	};
	return (ft_vfprintf(&stream, fmt, args));
}
