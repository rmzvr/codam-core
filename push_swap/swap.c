/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:22:30 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/17 15:20:07 by rzvir            ###   ########.fr       */
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

void	sa(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) < 2)
		return ;
	ft_printf("sa\n");
	ft_lstswap(stack_a);
}
