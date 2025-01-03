/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:21:12 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/02 16:38:19 by rzvir            ###   ########.fr       */
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
		ft_printf("====================\nstack_a before operation\n====================\n");
		ft_lstiter(*stack_a, pr);
		ft_printf("====================\nstack_b before operation\n====================\n");
		ft_lstiter(*stack_b, pr);
		ft_lstadd_front(stack_a, arg);
		ft_remove_file(stack_b, content);
		ft_printf("operation: pa\n");
		ft_printf("====================\nstack_a after operation\n====================\n");
		ft_lstiter(*stack_a, pr);
		ft_printf("====================\nstack_b after operation\n====================\n");
		ft_lstiter(*stack_b, pr);
	}
	else if (ft_strncmp(operation, "pb", 2) == 0)
	{
		if (*stack_a == NULL)
			return ;
		content = (*stack_a)->content;
		arg = ft_lstnew(content);
		ft_printf("====================\nstack_a before operation\n====================\n");
		ft_lstiter(*stack_a, pr);
		ft_printf("====================\nstack_b before operation\n====================\n");
		ft_lstiter(*stack_b, pr);
		ft_lstadd_front(stack_b, arg);
		ft_remove_file(stack_a, content);
		ft_printf("operation: pb\n");
		ft_printf("====================\nstack_a after operation\n====================\n");
		ft_lstiter(*stack_a, pr);
		ft_printf("====================\nstack_b after operation\n====================\n");
		ft_lstiter(*stack_b, pr);
	}
}
