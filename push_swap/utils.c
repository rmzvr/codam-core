/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:29:41 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/18 15:07:04 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_node_content(void *content)
{
	free(content);
	content = NULL;
}

void	show_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	cleanup(t_list **stack_a, t_list **stack_b, char **argv, int argc)
{
	ft_lstclear(stack_a, delete_node_content);
	ft_lstclear(stack_b, delete_node_content);
	if (argc == 2)
		free_split(argv);
}
