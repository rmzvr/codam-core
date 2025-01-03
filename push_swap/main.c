/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:33:37 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/03 12:26:35 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b)
{
	(void) stack_a;
	(void) stack_b;
	// int		i;

	// i = 0;

	ft_lstiter(*stack_a, pr);
	// while (ft_lstsize(*stack_a) != 0 && i < 4)
	// {
	// 	ft_printf("\n====================\ntemp: %d\n====================\n", *(int *)((*stack_a)->content));
	// 	// while (ft_lstsize(*stack_b) > 0 && *(int *)((*stack_b)->content) < *(int *)((*stack_a)->content))
	// 	// {
	// 	// 	push("pa", stack_a, stack_b);
	// 	// }
	// 	// push("pb", stack_a, stack_b);
	// 	i++;
	// }
	// ft_printf("\n\n\ni = %d\n\n\n", i);
}

int	main(int argc, char **argv)
{
	char	**arguments;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		exit(EXIT_FAILURE);
	arguments = argv;
	if (ft_split(argv[1], ' ')[1] != NULL)
		arguments = ft_split(argv[1], ' ');
	validate_arguments(arguments);
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, arguments);
	sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a, dl);
	ft_lstclear(&stack_b, dl);
	stack_a = NULL;
	stack_b = NULL;
	return (0);
}
