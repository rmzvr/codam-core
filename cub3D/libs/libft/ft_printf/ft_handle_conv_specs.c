/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conv_specs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:34:56 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/26 11:24:33 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_conv_specs(va_list args, char conv_spec, int str_len)
{
	if (ft_strchr("cs%", conv_spec))
	{
		str_len = ft_handle_char_specs(args, conv_spec, str_len);
	}
	else if (ft_strchr("diu", conv_spec))
	{
		str_len = ft_handle_num_specs(args, conv_spec, str_len);
	}
	else if (ft_strchr("pxX", conv_spec))
	{
		str_len = ft_handle_mem_specs(args, conv_spec, str_len);
	}
	return (str_len);
}
