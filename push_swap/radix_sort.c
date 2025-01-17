/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:59:52 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/17 17:00:17 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack_a(int shift, t_list **stack_a, t_list **stack_b)
{
	int	mask;
	int	value;
	int	counter;
	int	stack_length;

	mask = 1;
	value = 0;
	counter = 0;
	stack_length = ft_lstsize(*stack_a);
	if (*stack_a == NULL)
		return ;
	while (counter < stack_length)
	{
		value = get_index(*stack_a) >> shift;
		if (value & mask)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		counter++;
	}
}

static void	sort_stack_b(int shift, t_list **stack_a, t_list **stack_b)
{
	int	mask;
	int	value;
	int	counter;
	int	stack_length;

	mask = 1;
	value = 0;
	counter = 0;
	stack_length = ft_lstsize(*stack_b);
	if (*stack_b == NULL)
		return ;
	while (counter < stack_length)
	{
		value = get_index(*stack_b) >> shift;
		if (value & mask)
			pa(stack_a, stack_b);
		else
			rb(stack_b);
		counter++;
	}
}

void	sort_radix(t_list **stack_a, t_list **stack_b)
{
	int		shift;
	int		biggest_value;

	shift = 0;
	biggest_value = get_index(find_biggest(*stack_a, LONG_MAX));
	while (biggest_value != 0)
	{
		sort_stack_a(shift, stack_a, stack_b);
		if (shift == 0)
		{
			shift++;
			biggest_value >>= 1;
			continue ;
		}
		sort_stack_b(shift, stack_a, stack_b);
		shift++;
		biggest_value >>= 1;
	}
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}
