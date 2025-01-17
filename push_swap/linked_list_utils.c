/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:27:47 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/17 16:35:17 by rzvir            ###   ########.fr       */
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

void	ft_lst_rotate_rev(t_list **lst)
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

void	ft_lst_rotate(t_list **lst)
{
	t_list	*curr_node;

	if (lst == NULL || *lst == NULL)
		return ;
	curr_node = *lst;
	ft_lstadd_back(lst, curr_node);
	*lst = curr_node->next;
	curr_node->next = NULL;
}
