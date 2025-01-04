/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:23:33 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/04 15:03:00 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_lst_prev_last(t_list *lst)
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

static void	ft_lst_rotate_rev(t_list **lst)
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

static void	ft_lst_rotate(t_list **lst)
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
		ft_printf("ra\n");
		ft_lst_rotate(stack_a);
	}
	else if (ft_strncmp(operation, "rb", 2) == 0)
	{
		ft_printf("rb\n");
		ft_lst_rotate(stack_b);
	}
	else if (ft_strncmp(operation, "rr", 2) == 0)
	{
		ft_printf("rr\n");
		ft_lst_rotate(stack_a);
		ft_lst_rotate(stack_b);
	}
}

void	rotate_rev(char *operation, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(operation, "rra", 3) == 0)
	{
		ft_printf("rra\n");
		ft_lst_rotate_rev(stack_a);
	}
	else if (ft_strncmp(operation, "rrb", 3) == 0)
	{
		ft_printf("rrb\n");
		ft_lst_rotate_rev(stack_b);
	}
	else if (ft_strncmp(operation, "rrr", 3) == 0)
	{
		ft_printf("rrr\n");
		ft_lst_rotate_rev(stack_a);
		ft_lst_rotate_rev(stack_b);
	}
}
