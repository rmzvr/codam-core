/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:42:39 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/09 12:54:24 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	power_of_ten(size_t len)
{
	int		i;
	size_t	counter;

	i = 1;
	counter = 0;
	while (counter < len)
	{
		i *= 10;
		counter++;
	}
	return (i * 1.0);
}

static int	is_valid_part(char *str)
{
	size_t	i;

	if (str != NULL)
	{
		i = 0;
		while (str[i] != '\0')
		{
			if (!ft_isdigit(str[i]))
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

int	is_valid_double(char *str)
{
	char	**splitted_arg;

	if (!str || *str == '\0')
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	splitted_arg = ft_split(str, '.');
	if (splitted_arg[2] != NULL)
	{
		free(splitted_arg);
		return (0);
	}
	if (!is_valid_part(splitted_arg[0]) || !is_valid_part(splitted_arg[1]))
	{
		free(splitted_arg);
		return (0);
	}
	free(splitted_arg);
	return (1);
}

double	ft_atof(char *str)
{
	char	**splitted_str;
	double	int_p;
	double	fract_p;
	size_t	fract_p_len;
	int		sign;

	sign = 1;
	splitted_str = ft_split(str, '.');
	fract_p_len = ft_strlen(splitted_str[1]);
	int_p = ft_atoi(splitted_str[0]) * 1.0;
	fract_p = ft_atoi(splitted_str[1]) / power_of_ten(fract_p_len);
	if (int_p < 0.0)
		sign = -1;
	return (int_p + fract_p * sign);
}
