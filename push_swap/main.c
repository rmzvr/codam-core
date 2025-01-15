/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:33:37 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/15 16:09:30 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "limits.h"

int	get_content(t_list *stack)
{
	t_content	*content;

	content = stack->content;
	return (content->value);
}

int	get_index(t_list *stack)
{
	t_content	*content;

	content = stack->content;
	return (content->index);
}

static t_list	*find_smallest(t_list *stack)
{
	t_list *curr;
	t_list *smallest;

	curr = stack;
	smallest = curr;
	while (curr != NULL)
	{
		if (curr->next != NULL && get_content(smallest) > get_content(curr->next))
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
	while (curr->next != NULL)
	{
		if (get_content(biggest) < get_content(curr->next))
			biggest = curr->next;
		curr = curr->next;
	}
	return (biggest);
}

static t_list	*find_biggest1(t_list *stack, int last_biggest)
{
	t_list	*biggest;

	biggest = NULL;
	while (stack->next != NULL && get_content(stack) >= last_biggest)
		stack = stack->next;
	if (get_content(stack) >= last_biggest)
		return (NULL);
	biggest = stack;
	while (stack->next != NULL)
	{
		if (get_content(biggest) < get_content(stack->next))
		{
			if (get_content(stack->next) < last_biggest)
				biggest = stack->next;
		}
		stack = stack->next;
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
		if (get_content(curr) == i)
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

int	is_sorted_des(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (get_content(stack) < get_content(stack->next))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_sorted_asc(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (get_content(stack) > get_content(stack->next))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_contains_all_same_bit(t_list *stack, int shift)
{
	while (stack->next != NULL)
	{
		if ((get_content(stack) >> shift & 1) != (get_content(stack->next) >> shift & 1))
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
	int		counter;
	int		len;

	mask = 1;
	counter = 0;
	shift = 0;
	curr = *stack_a;
	biggest = get_index(find_biggest(*stack_a));
	while (biggest != 0)
	{
		len = ft_lstsize(*stack_a);
		counter = 0;
		if (*stack_a != NULL)
		{
			while (counter < len)
			{
				curr = *stack_a;
				value = get_index(curr) >> shift;
				if (value & mask)
					rotate("ra", stack_a, stack_b);
				else
					push("pb", stack_a, stack_b);
				counter++;
			}
		}
		if (shift == 0)
		{
			shift++;
			biggest >>= 1;
			continue;
		}
		len = ft_lstsize(*stack_b);
		counter = 0;
		if (*stack_b != NULL)
		{
			while (counter < len)
			{
				curr = *stack_b;
				value = get_index(curr) >> shift;
				if (value & mask)
					push("pa", stack_a, stack_b);
				else
					rotate("rb", stack_a, stack_b);
				counter++;
			}
		}
		shift++;
		biggest >>= 1;
	}
	while (*stack_b  != NULL)
		push("pa", stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	// if (ft_lstsize(*stack_a) == 2)
	// 	sort_two(stack_a, stack_b);
	// else if (ft_lstsize(*stack_a) == 3)
	// 	sort_three(stack_a, stack_b);
	// else if (ft_lstsize(*stack_a) == 4)
	// 	sort_four(stack_a, stack_b);
	// else if (ft_lstsize(*stack_a) == 5)
	// 	sort_five(stack_a, stack_b);
	// else
		sort2(stack_a, stack_b);
}

void	print_index(void *c)
{
	t_content	*content;

	content = c;
	ft_printf("value: %d, index: %d\n", content->value, content->index);
}

void	calculate_index(t_list *stack)
{
	t_list		*biggest;
	t_content	*content;
	int			stack_size;
	int			last_biggest_value;
	int			last_biggest_index;

	stack_size = ft_lstsize(stack) - 1;
	biggest = find_biggest1(stack, INT_MAX);
	content = biggest->content;
	last_biggest_value = get_content(biggest);
	last_biggest_index = find_position(stack, last_biggest_value);
	content->index = stack_size;
	stack_size--;
	while (stack_size != 0)
	{
		biggest = find_biggest1(stack, last_biggest_value);
		if (!biggest)
			return ;
		content = biggest->content;
		last_biggest_value = get_content(biggest);
		last_biggest_index = find_position(stack, last_biggest_value);
		content->index = stack_size;
		stack_size--;
	}
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
	calculate_index(stack_a);
	sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a, dl);
	ft_lstclear(&stack_b, dl);
	stack_a = NULL;
	stack_b = NULL;
	return (0);
}
