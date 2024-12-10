/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:26:01 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/10 11:07:12 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

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
	char	**splitted_str;

	if (!str || *str == '\0')
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	splitted_str = ft_split(str, '.');
	if (!is_valid_part(splitted_str[0])
		|| !is_valid_part(splitted_str[1])
		|| splitted_str[2] != NULL)
	{
		free_split(splitted_str);
		return (0);
	}
	free_split(splitted_str);
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
	free_split(splitted_str);
	return (int_p + fract_p * sign);
}
