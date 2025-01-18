/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:44:05 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/18 15:14:00 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_content(t_list *stack)
{
	t_content	*content;

	content = stack->content;
	return (content->value);
}

int	get_index(t_list *stack)
{
	t_content	*content;

	content = stack->content;
	return (content->index);
}

int	find_position(t_list *stack, int value)
{
	int		index;
	t_list	*curr;

	index = 0;
	curr = stack;
	while (curr != NULL)
	{
		if (get_content(curr) == value)
			break ;
		curr = curr->next;
		index++;
	}
	return (index);
}

t_list	*find_smallest(t_list *stack)
{
	t_list	*curr;
	t_list	*smallest;

	if (ft_lstsize(stack) == 1)
		return (stack);
	curr = stack;
	smallest = curr;
	while (curr->next != NULL)
	{
		if (get_content(smallest) > get_content(curr->next))
			smallest = curr->next;
		curr = curr->next;
	}
	return (smallest);
}

t_list	*find_biggest(t_list *stack, long last_biggest)
{
	t_list	*biggest;

	biggest = NULL;
	while (stack->next != NULL && get_content(stack) >= last_biggest)
		stack = stack->next;
	if (get_content(stack) >= last_biggest)
		return (NULL);
	biggest = stack;
	while (stack->next != NULL)
	{
		if (get_content(biggest) < get_content(stack->next))
		{
			if (get_content(stack->next) < last_biggest)
				biggest = stack->next;
		}
		stack = stack->next;
	}
	return (biggest);
}
