/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:37:16 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/17 16:40:11 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
