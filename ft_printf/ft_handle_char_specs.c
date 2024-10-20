/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char_specs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:35:00 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/20 14:49:09 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_char_specs(char conv_spec, va_list args, int char_count)
{
	if (conv_spec == 'c')
	{
		char_count = ft_printf_c_spec(args, char_count);
	}
	else if (conv_spec == 's')
	{
		char_count = ft_printf_s_spec(args, char_count);
	}
	else if (conv_spec == '%')
	{
		char_count = ft_printf_percent_spec(char_count);
	}
	return (char_count);
}
