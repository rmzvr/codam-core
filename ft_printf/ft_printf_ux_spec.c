/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ux_spec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:36:47 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/20 17:18:00 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_ux_spec(va_list args, int char_count)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	char_count += ft_puthex(i, 1);
	return (char_count);
}
