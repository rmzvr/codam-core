/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fmts.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 12:14:38 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/18 13:41:38 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

#include "libft/io/ft_printf.h"

//
// Handle the format of the specifier: s
//
size_t	ft_fmts(t_stream *stream, t_format format, va_list args)
{
	return (ft_write_s(stream, format, va_arg(args, char *)));
}
