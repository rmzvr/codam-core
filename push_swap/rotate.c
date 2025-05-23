/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:23:33 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/18 15:04:38 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) <= 1)
		return ;
	ft_printf("ra\n");
	rotate_list(stack_a);
}

void	rra(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) <= 1)
		return ;
	ft_printf("rra\n");
	reverse_rotate_list(stack_a);
}

void	rb(t_list **stack_b)
{
	if (ft_lstsize(*stack_b) <= 1)
		return ;
	ft_printf("rb\n");
	rotate_list(stack_b);
}
