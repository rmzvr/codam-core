/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:15:21 by rzvir             #+#    #+#             */
/*   Updated: 2025/02/08 14:38:31 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_invalid_argument(char *argument)
{
	unsigned long long	number;
	size_t				number_length;
	size_t				argument_length;

	number = ft_atoul(argument);
	number_length = ft_nbrlen(number);
	argument_length = ft_strlen(argument);
	if (number == 0 && (argument[0] != '0' && argument_length != 1))
		return (1);
	if (number_length != argument_length)
		return (1);
	return (0);
}

int	validate_arguments(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (show_help());
	if (ft_atoul(argv[1]) < 1)
		return (show_error(3));
	i = 1;
	while (i < argc)
	{
		if (is_invalid_argument(argv[i]))
			return (show_error(2));
		i++;
	}
	if (argv[5] != NULL && ft_atoui(argv[5]) == 0)
		return (show_error(5));
	return (0);
}
