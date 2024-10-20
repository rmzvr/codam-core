/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_spec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:34:36 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/20 17:31:58 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s_spec(va_list args, int char_count)
{
	char	*str;
	char	*null_str;

	null_str = "(null)";
	str = va_arg(args, char *);
	if (str == NULL)
	{
		ft_putstr_fd(null_str, 1);
		char_count += ft_strlen(null_str);
	}
	else
	{
		char_count += ft_strlen(str);
		ft_putstr_fd(str, 1);
	}
	return (char_count);
}
