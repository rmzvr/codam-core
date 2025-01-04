/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:31:28 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/03 14:46:52 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
	{
		return (1);
	}
	return (0);
}

static int	ft_isminus(int c)
{
	if (c == '-')
	{
		return (1);
	}
	return (0);
}

static int	ft_issign(int c)
{
	if (ft_isminus(c) || c == '+')
	{
		return (1);
	}
	return (0);
}

static long long	ft_atoll(const char *nptr)
{
	int	i;
	long long	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
	{
		i++;
	}
	if (ft_issign(nptr[i]))
	{
		if (ft_isminus(nptr[i]))
		{
			sign = -1;
		}
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (num * sign);
}

int	is_all_digits(char **argv)
{
	int	i;
	int	j;

	i = 0;

	while (argv[i] != NULL)
	{
		if (ft_atoll(argv[i]) < INT_MIN || ft_atoll(argv[i]) > INT_MAX)
			return (0);
		j = 0;
		if ((argv[i][j] == '+' || argv[i][j] == '-'))
			j++;
		if (argv[i][j] == '\0')
			return (0);
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	has_duplication(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 1;
		while (argv[j] != NULL)
		{
			if (i != j && ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	validate_arguments(char **argv)
{
	if (!is_all_digits(argv) || has_duplication(argv))
		show_error_and_exit();
}