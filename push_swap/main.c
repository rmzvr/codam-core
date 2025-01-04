/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:33:37 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/04 16:44:38 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*find_smallest(t_list *stack)
{
	t_list *curr;
	t_list *smallest;

	curr = stack;
	smallest = curr;
	while (curr != NULL)
	{
		if (curr->next != NULL && *(int *)(smallest->content) > *(int *)(curr->next->content))
			smallest = curr->next;
		curr = curr->next;
	}
	return (smallest);
}

static t_list	*find_biggest(t_list *stack)
{
	t_list *curr;
	t_list *biggest;

	curr = stack;
	biggest = curr;
	while (curr != NULL)
	{
		if (curr->next != NULL && *(int *)(biggest->content) < *(int *)(curr->next->content))
			biggest = curr->next;
		curr = curr->next;
	}
	return (biggest);
}

static int	find_position(t_list *stack, int i)
{
	int	c;
	t_list *curr;

	c = 0;
	curr = stack;
	while (curr != NULL)
	{
		if (*(int *)(curr->content) == i)
			break ;
		curr = curr->next;
		c++;
	}
	return (c);
}

void	sort_two(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	t_list	*second;
	int first_content;
	int second_content;

	first = (*stack_a);
	second = (*stack_a)->next;
	first_content = *(int *)first->content;
	second_content = *(int *)second->content;

	if (first_content > second_content)
		swap("sa", stack_a, stack_b);
}

void	sort_three(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest;
	t_list	*biggest;
	int		smallest_position;
	int		biggest_position;

	biggest = find_biggest(*stack_a);
	biggest_position = find_position(*stack_a, *(int *)(biggest->content));
	if (biggest_position == 0)
		rotate("ra", stack_a, stack_b);
	else if (biggest_position == 1)
		rotate_rev("rra", stack_a, stack_b);

	smallest = find_smallest(*stack_a);
	smallest_position = find_position(*stack_a, *(int *)(smallest->content));
	if (smallest_position == 1)
		swap("sa", stack_a, stack_b);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest;
	int		smallest_position;

	smallest = find_smallest(*stack_a);
	smallest_position = find_position(*stack_a, *(int *)(smallest->content));
	if (smallest_position == 1)
	{
		rotate("ra", stack_a, stack_b);
	}
	else if (smallest_position == 2)
	{
		rotate_rev("rra", stack_a, stack_b);
		rotate_rev("rra", stack_a, stack_b);
	}
	else if (smallest_position == 3)
	{
		rotate_rev("rra", stack_a, stack_b);
	}
	push("pb", stack_a, stack_b);
	sort_three(stack_a, stack_b);
	push("pa", stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest;
	int		smallest_position;

	smallest = find_smallest(*stack_a);
	smallest_position = find_position(*stack_a, *(int *)(smallest->content));
	if (smallest_position == 1)
	{
		rotate("ra", stack_a, stack_b);
	}
	else if (smallest_position == 2)
	{
		rotate("ra", stack_a, stack_b);
		rotate("ra", stack_a, stack_b);
	}
	else if (smallest_position == 3)
	{
		rotate_rev("rra", stack_a, stack_b);
		rotate_rev("rra", stack_a, stack_b);
	}
	else if (smallest_position == 4)
	{
		rotate_rev("rra", stack_a, stack_b);
	}
	push("pb", stack_a, stack_b);
	sort_four(stack_a, stack_b);
	push("pa", stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sort_two(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 4)
		sort_four(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort_five(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	char	**arguments;
	t_list	*stack_a;
	t_list	*stack_b;

	arguments = argv + 1;
	if (argc == 1)
		exit(EXIT_FAILURE);
	else if (argc == 2)
	{
		arguments = ft_split(argv[1], ' ');
		if (ft_strlen(argv[1]) == 0)
			show_error_and_exit();
	}
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
