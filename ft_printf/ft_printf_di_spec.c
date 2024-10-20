/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di_spec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:34:36 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/20 14:52:54 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_di_spec(va_list args, int char_count)
{
	int	i;

	i = va_arg(args, int);
	ft_putnbr_fd(i, 1);
	char_count += ft_nbrlen(i);
	return (char_count);
}
