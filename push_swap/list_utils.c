/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:27:47 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/18 15:05:10 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_second_last_node(t_list *list)
{
	if (list == NULL)
	{
		return (list);
	}
	while (list->next->next != NULL)
	{
		list = list->next;
	}
	return (list);
}

void	reverse_rotate_list(t_list **list)
{
	t_list	*curr_node;
	t_list	*next_node;
	t_list	*second_last_node;

	if (list == NULL || *list == NULL)
		return ;
	curr_node = *list;
	next_node = ft_lstlast(curr_node);
	second_last_node = get_second_last_node(curr_node);
	ft_lstadd_front(list, next_node);
	second_last_node->next = NULL;
}

void	rotate_list(t_list **list)
{
	t_list	*curr_node;

	if (list == NULL || *list == NULL)
		return ;
	curr_node = *list;
	ft_lstadd_back(list, curr_node);
	*list = curr_node->next;
	curr_node->next = NULL;
}
