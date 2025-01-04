/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:22:30 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/03 15:02:38 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstswap(t_list **lst)
{
	t_list	*curr_node;
	t_list	*next_node;

	if (lst == NULL || *lst == NULL)
		return ;
	curr_node = *lst;
	next_node = curr_node->next;
	curr_node->next = next_node->next;
	next_node->next = *lst;
	*lst = next_node;
}

void	swap(char *operation, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(operation, "sa", 2) == 0)
	{
		if (ft_lstsize(*stack_a) < 2)
			return ;
		ft_printf("sa\n");
		ft_lstswap(stack_a);
	}
	else if (ft_strncmp(operation, "sb", 2) == 0)
	{
		if (ft_lstsize(*stack_b) < 2)
			return ;
		ft_printf("====================\noperation: sb\n");
		ft_printf("====================\nstack_a before operation\n====================\n");
		ft_lstiter(*stack_a, pr);
		ft_printf("====================\nstack_b before operation\n====================\n");
		ft_lstiter(*stack_b, pr);
		ft_lstswap(stack_b);
		ft_printf("====================\nstack_a after operation\n====================\n");
		ft_lstiter(*stack_a, pr);
		ft_printf("====================\nstack_b after operation\n====================\n");
		ft_lstiter(*stack_b, pr);
	}
	else if (ft_strncmp(operation, "ss", 2) == 0)
	{
		if (ft_lstsize(*stack_a) >= 2)
			ft_lstswap(stack_a);
		if (ft_lstsize(*stack_b) >= 2)
			ft_lstswap(stack_b);
		ft_printf("ss\n");
	}
}
