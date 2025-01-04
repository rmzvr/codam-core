/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:22:30 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/04 15:04:48 by rzvir            ###   ########.fr       */
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
		ft_printf("sb\n");
		ft_lstswap(stack_b);
	}
	else if (ft_strncmp(operation, "ss", 2) == 0)
	{
		ft_printf("ss\n");
		if (ft_lstsize(*stack_a) >= 2)
			ft_lstswap(stack_a);
		if (ft_lstsize(*stack_b) >= 2)
			ft_lstswap(stack_b);
	}
}
