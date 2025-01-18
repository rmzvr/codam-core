/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:32:54 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/18 15:07:04 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_indexes_to_values(t_list *stack)
{
	t_content	*content;
	t_list		*biggest;
	int			stack_size;
	int			last_biggest_value;

	biggest = NULL;
	stack_size = ft_lstsize(stack) - 1;
	while (stack_size != 0)
	{
		if (biggest == NULL)
			biggest = find_biggest(stack, LONG_MAX);
		else
			biggest = find_biggest(stack, last_biggest_value);
		if (!biggest)
			return ;
		content = biggest->content;
		content->index = stack_size;
		last_biggest_value = get_content(biggest);
		stack_size--;
	}
}

void	init_stack(t_list **stack, char **arguments)
{
	int			i;
	t_list		*node;
	t_content	*content;

	i = 0;
	node = NULL;
	content = NULL;
	while (arguments[i] != NULL)
	{
		content = (t_content *)malloc(sizeof(t_content));
		if (content == NULL)
			exit(EXIT_FAILURE);
		content->value = ft_atoi(arguments[i]);
		content->index = 0;
		node = ft_lstnew(content);
		if (node == NULL)
		{
			delete_node_content(content);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(stack, node);
		i++;
	}
	assign_indexes_to_values(*stack);
}
