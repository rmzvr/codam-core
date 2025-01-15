/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:32:54 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/15 11:56:14 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_list **stack, char **argv)
{
	int		i;
	t_list	*node;
	t_content	*content;

	i = 0;
	while (argv[i] != NULL)
	{
		content = (t_content *)malloc(sizeof(t_content));
		if (content == NULL)
			exit(EXIT_FAILURE);
		content->value = ft_atoi(argv[i]);
		node = ft_lstnew(content);
		ft_lstadd_back(stack, node);
		i++;
	}
}
