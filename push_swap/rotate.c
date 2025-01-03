/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:23:33 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/02 17:01:45 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_prev_last(t_list *lst)
{
	if (lst == NULL)
	{
		return (lst);
	}
	while (lst->next->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

static void	ft_lstrotate(t_list **lst)
{
	t_list	*curr_node;
	t_list	*next_node;
	t_list	*prev_next_node;

	if (lst == NULL || *lst == NULL)
		return ;
	curr_node = *lst;
	next_node = ft_lstlast(curr_node);
	prev_next_node = ft_lst_prev_last(curr_node);
	ft_lstadd_front(lst, next_node);
	prev_next_node->next = NULL;
}

static void	ft_lstrotate_rev(t_list **lst)
{
	t_list	*curr_node;

	if (lst == NULL || *lst == NULL)
		return ;
	curr_node = *lst;
	ft_lstadd_back(lst, curr_node);
	*lst = curr_node->next;
	curr_node->next = NULL;
}

void	rotate(char *operation, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(operation, "ra", 2) == 0)
	{
		ft_printf("====================\noperation: ra\n");
		ft_printf("====================\nstack_a before operation\n====================\n");
		ft_lstiter(*stack_a, pr);
		ft_printf("====================\nstack_b before operation\n====================\n");
		ft_lstiter(*stack_b, pr);
		ft_lstrotate(stack_a);
		ft_printf("====================\nstack_a after operation\n====================\n");
		ft_lstiter(*stack_a, pr);
		ft_printf("====================\nstack_b after operation\n====================\n");
		ft_lstiter(*stack_b, pr);
	}
	else if (ft_strncmp(operation, "rb", 2) == 0)
	{
		ft_printf("====================\noperation: rb\n");
		ft_printf("====================\nstack_a before operation\n====================\n");
		ft_lstiter(*stack_a, pr);
		ft_printf("====================\nstack_b before operation\n====================\n");
		ft_lstiter(*stack_b, pr);
		ft_lstrotate(stack_b);
		ft_printf("====================\nstack_a after operation\n====================\n");
		ft_lstiter(*stack_a, pr);
		ft_printf("====================\nstack_b after operation\n====================\n");
		ft_lstiter(*stack_b, pr);
	}
	else if (ft_strncmp(operation, "rr", 2) == 0)
	{
		ft_printf("====================\noperation: rr\n");
		ft_printf("====================\nstack_a before operation\n====================\n");
		ft_lstiter(*stack_a, pr);
		ft_printf("====================\nstack_b before operation\n====================\n");
		ft_lstiter(*stack_b, pr);
		ft_lstrotate(stack_a);
		ft_lstrotate(stack_b);
		ft_printf("====================\nstack_a after operation\n====================\n");
		ft_lstiter(*stack_a, pr);
		ft_printf("====================\nstack_b after operation\n====================\n");
		ft_lstiter(*stack_b, pr);
	}
}

void	rotate_rev(char *operation, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(operation, "rra", 3) == 0)
	{
		ft_printf("====================\nstack_a before operation\n====================\n");
		ft_lstiter(*stack_a, pr);
		ft_printf("====================\nstack_b before operation\n====================\n");
		ft_lstiter(*stack_b, pr);
		ft_lstrotate_rev(stack_a);
		ft_printf("operation: rra\n");
		ft_printf("====================\nstack_a after operation\n====================\n");
		ft_lstiter(*stack_a, pr);
		ft_printf("====================\nstack_b after operation\n====================\n");
		ft_lstiter(*stack_b, pr);
	}
	else if (ft_strncmp(operation, "rrb", 3) == 0)
	{
		ft_printf("====================\nstack_a before operation\n====================\n");
		ft_lstiter(*stack_a, pr);
		ft_printf("====================\nstack_b before operation\n====================\n");
		ft_lstiter(*stack_b, pr);
		ft_lstrotate_rev(stack_b);
		ft_printf("operation: rrb\n");
		ft_printf("====================\nstack_a after operation\n====================\n");
		ft_lstiter(*stack_a, pr);
		ft_printf("====================\nstack_b after operation\n====================\n");
		ft_lstiter(*stack_b, pr);

	}
	else if (ft_strncmp(operation, "rrr", 3) == 0)
	{
		ft_printf("====================\nstack_a before operation\n====================\n");
		ft_lstiter(*stack_a, pr);
		ft_printf("====================\nstack_b before operation\n====================\n");
		ft_lstiter(*stack_b, pr);
		ft_lstrotate_rev(stack_a);
		ft_lstrotate_rev(stack_b);
		ft_printf("operation: rrr\n");
		ft_printf("====================\nstack_a after operation\n====================\n");
		ft_lstiter(*stack_a, pr);
		ft_printf("====================\nstack_b after operation\n====================\n");
		ft_lstiter(*stack_b, pr);
	}
}
