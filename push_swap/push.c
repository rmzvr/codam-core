/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:21:12 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/04 15:04:13 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_remove_file(t_list **list, int *content)
{
	t_list	*curr;
	t_list	*file_to_delete;

	if (list == NULL || *list == NULL)
		return ;
	curr = *list;
	if ((*list)->content == content)
	{
		file_to_delete = *list;
		*list = (*list)->next;
		free(file_to_delete);
		return ;
	}
	while (curr->next != NULL)
	{
		if (curr->next->content == content)
		{
			file_to_delete = curr->next;
			curr->next = curr->next->next;
			free(file_to_delete);
			return ;
		}
		curr = curr->next;
	}
}

void	push(char *operation, t_list **stack_a, t_list **stack_b)
{
	t_list	*arg;
	int		*content;

	if (ft_strncmp(operation, "pa", 2) == 0)
	{
		if (*stack_b == NULL)
			return ;
		content = (*stack_b)->content;
		arg = ft_lstnew(content);
		ft_printf("pa\n");
		ft_lstadd_front(stack_a, arg);
		ft_remove_file(stack_b, content);
	}
	else if (ft_strncmp(operation, "pb", 2) == 0)
	{
		if (*stack_a == NULL)
			return ;
		content = (*stack_a)->content;
		arg = ft_lstnew(content);
		ft_printf("pb\n");
		ft_lstadd_front(stack_b, arg);
		ft_remove_file(stack_a, content);
	}
}
