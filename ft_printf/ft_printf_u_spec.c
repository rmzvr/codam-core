/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_spec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:34:36 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/20 17:30:33 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_u_spec(va_list args, int char_count)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	char_count += ft_putunbr(i);
	return (char_count);
}
