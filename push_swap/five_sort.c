/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:10:57 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/17 17:11:02 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_list **stack_a)
{
	t_list	*biggest;
	t_list	*smallest;
	int		smallest_position;
	int		biggest_position;

	biggest = find_biggest(*stack_a, LONG_MAX);
	biggest_position = find_position(*stack_a, get_content(biggest));
	if (biggest_position == 0)
		ra(stack_a);
	else if (biggest_position == 1)
		rra(stack_a);
	smallest = find_smallest(*stack_a);
	smallest_position = find_position(*stack_a, get_content(smallest));
	if (smallest_position == 1)
		sa(stack_a);
}

static void	move_value_to_left(int smallest_index, t_list **stack_a)
{
	int		iterations;

	iterations = smallest_index;
	while (iterations != 0)
	{
		ra(stack_a);
		iterations--;
	}
}

static void	move_value_to_right(int smallest_position, int stack_length,
	t_list **stack_a)
{
	int		iterations;

	iterations = stack_length - smallest_position;
	while (iterations != 0)
	{
		rra(stack_a);
		iterations--;
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest;
	int		stack_length;
	int		smallest_index;

	stack_length = ft_lstsize(*stack_a);
	while (stack_length != 3)
	{
		smallest = find_smallest(*stack_a);
		smallest_index = find_position(*stack_a, get_content(smallest));
		if (smallest_index <= stack_length / 2)
			move_value_to_left(smallest_index, stack_a);
		else
			move_value_to_right(smallest_index, stack_length, stack_a);
		pb(stack_a, stack_b);
		stack_length = ft_lstsize(*stack_a);
	}
	sort_three(stack_a);
	while (ft_lstsize(*stack_b) != 0)
		pa(stack_a, stack_b);
}
