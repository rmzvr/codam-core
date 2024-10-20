/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_mem_specs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:34:51 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/20 17:10:28 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_mem_specs(char conv_spec, va_list args, int char_count)
{
	if (conv_spec == 'p')
	{
		char_count = ft_printf_p_spec(args, char_count);
	}
	else if (conv_spec == 'x')
	{
		char_count = ft_printf_x_spec(args, char_count);
	}
	else if (conv_spec == 'X')
	{
		char_count = ft_printf_ux_spec(args, char_count);
	}
	return (char_count);
}
