/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:33:37 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/18 13:42:12 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**arguments;

	arguments = argv + 1;
	if (argc == 1)
		return (1);
	else if (argc == 2)
	{
		arguments = ft_split(argv[1], ' ');
		if (arguments == NULL)
			return (1);
		if (*arguments == NULL)
		{
			free_split(arguments);
			return (1);
		}
		if (ft_strlen(argv[1]) == 0)
			show_error_and_exit();
	}
	validate_arguments(arguments);
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, arguments);
	sort_stack(&stack_a, &stack_b);
	ft_lstclear(&stack_a, delete_content);
	ft_lstclear(&stack_b, delete_content);
	if (argc == 2)
		free_split(arguments);
	return (0);
}
