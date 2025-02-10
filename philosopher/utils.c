/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:43:20 by rzvir             #+#    #+#             */
/*   Updated: 2025/02/08 14:36:30 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_nbrlen(int n)
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

uint64_t	ft_atoul(const char *nptr)
{
	int			i;
	uint64_t	num;

	i = 0;
	num = 0;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-')
		return (0);
	if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (num);
}

uint32_t	ft_atoui(const char *nptr)
{
	int			i;
	uint32_t	num;

	i = 0;
	num = 0;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-')
		return (0);
	if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (num);
}
