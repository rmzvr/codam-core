/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_num_specs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:34:46 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/20 14:58:47 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_num_specs(char conv_spec, va_list args, int char_count)
{
	if (ft_strchr("di%", conv_spec))
	{
		char_count = ft_printf_di_spec(args, char_count);
	}
	else if (conv_spec == 'u')
	{
		char_count = ft_printf_u_spec(args, char_count);
	}
	return (char_count);
}
