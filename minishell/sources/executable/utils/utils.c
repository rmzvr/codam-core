/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:20:57 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/21 21:00:48 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"
#include "builtins/builtins.h"

int	ft_any(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_count_any(char const *s1, char const *set, int to_left)
{
	int	count;

	count = 0;
	while (ft_any(*s1, set))
	{
		count++;
		if (to_left == 0)
		{
			s1++;
		}
		else
		{
			s1--;
		}
	}
	return (count);
}

char	*print_and_return_null(char *message)
{
	ft_putendl_fd(message, STDERR_FILENO);
	return (NULL);
}
