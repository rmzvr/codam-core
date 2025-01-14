/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:33:37 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/14 16:42:03 by rmzvr            ###   ########.fr       */
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

// void	sort1(t_list **stack_a, t_list **stack_b)
// {
// 	int		stack_size;
// 	int		init_stack_size;
// 	t_list	*smallest;
// 	t_list	*curr;
// 	int		i;
// 	int		is_sorted_des;

// 	i = 0;
// 	stack_size = ft_lstsize(*stack_a);
// 	init_stack_size = stack_size;
// 	while (stack_size != 3)
// 	{
// 		curr = *stack_a;
// 		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
// 		{
// 			swap("sa", stack_a, stack_b);
// 		}
// 		smallest = find_smallest(*stack_a);
// 		while (*(int *)(smallest->content) != *(int *)(curr->content))
// 		{
// 			if (find_position(*stack_a, *(int *)smallest->content) <= init_stack_size / 2)
// 			{
// 				rotate("ra", stack_a, stack_b);
// 				// ft_lstiter(*stack_a, pr);
// 				// ft_printf("\n");
// 			}
// 			else
// 			{
// 				rotate_rev("rra", stack_a, stack_b);
// 				// ft_lstiter(*stack_a, pr);
// 				// ft_printf("\n");
// 			}
// 			curr = *stack_a;
// 		}
// 		push("pb", stack_a, stack_b);
// 		// ft_lstiter(*stack_a, pr);
// 		// ft_printf("\n");
// 		stack_size = ft_lstsize(*stack_a);
// 	}
// 	sort_three(stack_a, stack_b);
// 	while (i < init_stack_size - 3)
// 	{
// 		push("pa", stack_a, stack_b);
// 		// ft_lstiter(*stack_a, pr);
// 		// ft_printf("\n");
// 		i++;
// 	}
// 	// ft_lstiter(*stack_a, pr);
// 	// ft_lstiter(*stack_a, pr);
// }

#include <stdio.h>

void printBinary(int n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

int	get_value(t_list *stack)
{
	return (*(int *)stack->content);
}

int	is_sorted_des(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (get_value(stack) < get_value(stack->next))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_sorted_asc(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (get_value(stack) > get_value(stack->next))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_contains_all_same_bit(t_list *stack, int shift)
{
	while (stack->next != NULL)
	{
		if ((get_value(stack) >> shift & 1) != (get_value(stack->next) >> shift & 1))
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort2(t_list **stack_a, t_list **stack_b)
{
	int		mask;
	int		value;
	t_list	*curr;
	int		biggest;
	int		shift;

	mask = 1;
	shift = 0;
	curr = *stack_a;
	biggest = get_value(find_biggest(*stack_a));
	while (biggest != 0)
	{
		if (*stack_a != NULL)
		{
			while (!is_contains_all_same_bit(*stack_a, shift))
			{
				curr = *stack_a;
				value = get_value(curr) >> shift;
				if (value & mask)
					rotate("ra", stack_a, stack_b);
				else
					push("pb", stack_a, stack_b);
			}
		}
		if (*stack_b != NULL)
		{
			while (!is_contains_all_same_bit(*stack_b, shift))
			{
				curr = *stack_b;
				value = get_value(curr) >> shift;
				if (value & mask)
					push("pa", stack_a, stack_b);
				else
					rotate("rb", stack_a, stack_b);
			}
		}
		shift++;
		biggest >>= 1;
	}
}

int	main(int argc, char **argv)
{
	char	**arguments;
	t_list	*stack_a;
	t_list	*stack_b;
	(void)	stack_b;

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
	// ft_lstiter(stack_a, pr);
	sort2(&stack_a, &stack_b);
	// printf("%d", is_contains_all_same_bit(stack_a, 2));
	// ft_lstiter(stack_a, pr);
	ft_lstclear(&stack_a, dl);
	ft_lstclear(&stack_b, dl);
	stack_a = NULL;
	stack_b = NULL;
	return (0);
}
