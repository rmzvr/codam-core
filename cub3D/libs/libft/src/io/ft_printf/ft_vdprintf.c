/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vdprintf.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/28 11:04:08 by bamarell      #+#    #+#                 */
/*   Updated: 2023/11/28 11:04:08 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/ft_printf.h"

int	ft_vdprintf(int fd, const char *fmt, va_list args)
{
	t_stream	stream;

	stream = (t_stream){
		.callback = stdstream_write,
		.fd = fd,
	};
	return (ft_vfprintf(&stream, fmt, args));
}
