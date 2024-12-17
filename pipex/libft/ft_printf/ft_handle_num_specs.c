/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_num_specs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:34:46 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/30 11:34:31 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(int n)
{
	long	long_num;
	size_t	nbr_len;

	long_num = n;
	nbr_len = 0;
	if (long_num < 0)
	{
		long_num = long_num * -1;
		nbr_len++;
	}
	while (long_num >= 10)
	{
		nbr_len++;
		long_num = long_num / 10;
	}
	nbr_len++;
	return (nbr_len);
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
	char			*base;
	size_t			base_len;

	base = "0123456789";
	base_len = ft_strlen(base);
	i = va_arg(args, unsigned int);
	str_len += ft_put_unum(i, base, base_len);
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
