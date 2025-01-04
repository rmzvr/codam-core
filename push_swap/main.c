/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:33:37 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/03 15:44:40 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_smallest(t_list *stack)
{
	t_list *curr;
	t_list *smallest;

	curr = stack;
	smallest = curr;
	while (curr != NULL)
	{
		if (curr->next != NULL && *(int *)(curr->content) > *(int *)(curr->next->content))
			smallest = curr->next;
		curr = curr->next;
	}
	return (smallest);
}

t_list	*find_biggest(t_list *stack)
{
	t_list *curr;
	t_list *biggest;

	curr = stack;
	biggest = curr;
	while (curr != NULL)
	{
		if (curr->next != NULL && *(int *)(curr->content) < *(int *)(curr->next->content))
			biggest = curr->next;
		curr = curr->next;
	}
	return (biggest);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list *first;
	t_list *second;
	t_list *smallest;
	t_list *biggest;

	int first_content;
	int second_content;

	first = (*stack_a);
	second = (*stack_a)->next;
	first_content = *(int *)first->content;
	second_content = *(int *)second->content;
	if (ft_lstsize(*stack_a) == 2)
	{
		if (first_content > second_content)
			swap("sa", stack_a, stack_b);
	}
	else if (ft_lstsize(*stack_a) == 3)
	{
		biggest = find_biggest(*stack_a);
		ft_printf("%d\n", *(int *)(biggest->content));
		find_smallest
	}
}
// 123 321 213 312 132 231

int	main(int argc, char **argv)
{
	char	**arguments;
	t_list	*stack_a;
	t_list	*stack_b;

	arguments = argv + 1;
	if (argc == 1)
		exit(EXIT_FAILURE);
	else if (argc == 2)
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
