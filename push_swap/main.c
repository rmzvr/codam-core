/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:33:37 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/03 10:25:09 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b)
{
	int		i;

	i = 0;
	while (ft_lstsize(*stack_a) != 0 && i < 4)
	{
		ft_printf("\n\n====================\ntemp: %d\n====================\n\n", *(int *)((*stack_a)->content));
		while (ft_lstsize(*stack_b) > 0 && *(int *)((*stack_b)->content) < *(int *)((*stack_a)->content))
		{
			push("pa", stack_a, stack_b);
		}
		push("pb", stack_a, stack_b);
		i++;
	}
	ft_printf("\n\n\ni = %d\n\n\n", i);
}

int	main(int argc, char **argv)
{
	t_list* stack_a;
	t_list* stack_b;

	if (argc == 1)
		exit(EXIT_FAILURE);
	validate_arguments(argv);
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, argv);
	ft_lstclear(&stack_a, dl);
	ft_lstclear(&stack_b, dl);
	stack_a = NULL;
	stack_b = NULL;
	return (0);
}
