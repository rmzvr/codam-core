/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:31:28 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/18 15:30:28 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_all_digits(char **argv)
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

static int	has_duplication(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] != NULL)
	{
		j = 0;
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

void	validate_arguments(char **arguments, int argc)
{
	if (!is_all_digits(arguments) || has_duplication(arguments))
	{
		if (argc == 2)
			free_split(arguments);
		show_error_and_exit();
	}
}
