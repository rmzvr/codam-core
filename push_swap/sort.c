/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:40:08 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/17 16:55:33 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_list **stack_a)
{
	if (get_content(*stack_a) > get_content((*stack_a)->next))
		sa(stack_a);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sort_two(stack_a);
	else if (ft_lstsize(*stack_a) <= 5)
		sort_five(stack_a, stack_b);
	else
		sort_radix(stack_a, stack_b);
}
