/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:32:54 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/02 14:33:07 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_list **stack, char **argv)
{
	int		i;
	t_list	*arg;
	int		*value;

	i = 1;
	while (argv[i] != NULL)
	{
		value = malloc(sizeof(int));
		if (value == NULL)
			exit(EXIT_FAILURE);
		*value = ft_atoi(argv[i]);
		arg = ft_lstnew(value);
		ft_lstadd_back(stack, arg);
		i++;
	}
}
