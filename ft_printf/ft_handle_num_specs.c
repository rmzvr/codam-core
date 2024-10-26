/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_num_specs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:34:46 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/26 11:35:05 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(int n)
{
	long	long_num;
	size_t	nbr_length;

	long_num = n;
	nbr_length = 0;
	if (long_num < 0)
	{
		long_num = long_num * -1;
		nbr_length++;
	}
	while (long_num >= 10)
	{
		nbr_length++;
		long_num = long_num / 10;
	}
	nbr_length++;
	return (nbr_length);
}

static int	ft_putunbr(unsigned int i)
{
	char	digit;
	int		count;

	count = 0;
	if (i > 9)
	{
		count += ft_putunbr(i / 10);
	}
	digit = i % 10 + '0';
	write(1, &digit, 1);
	count++;
	return (count);
}

static int	ft_print_di_spec(va_list args, int str_len)
{
	int	i;

	i = va_arg(args, int);
	ft_putnbr_fd(i, 1);
	str_len += ft_nbrlen(i);
	return (str_len);
}

static int	ft_print_u_spec(va_list args, int str_len)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	str_len += ft_putunbr(i);
	return (str_len);
}

int	ft_handle_num_specs(va_list args, char conv_spec, int str_len)
{
	if (ft_strchr("di%", conv_spec))
	{
		str_len = ft_print_di_spec(args, str_len);
	}
	else if (conv_spec == 'u')
	{
		str_len = ft_print_u_spec(args, str_len);
	}
	return (str_len);
}
