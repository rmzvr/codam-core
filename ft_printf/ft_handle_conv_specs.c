/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conv_specs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:34:56 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/20 14:34:57 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_conv_specs(va_list	args, char conv_spec, int char_count)
{
	if (ft_strchr("cs%", conv_spec))
	{
		char_count = ft_handle_char_specs(conv_spec, args, char_count);
	}
	else if (ft_strchr("diu", conv_spec))
	{
		char_count = ft_handle_num_specs(conv_spec, args, char_count);
	}
	else if (ft_strchr("pxX", conv_spec))
	{
		char_count = ft_handle_mem_specs(conv_spec, args, char_count);
	}
	return (char_count);
}
