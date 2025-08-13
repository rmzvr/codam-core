/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vsprintf.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 19:45:13 by bamarell      #+#    #+#                 */
/*   Updated: 2023/01/31 20:11:42 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/ft_printf.h"

int	ft_vsprintf(char *buf, const char *fmt, va_list args)
{
	return (ft_vsnprintf(buf, -1, fmt, args));
}
