/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:33:37 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/18 15:26:45 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			return (free_split(arguments), 1);
		if (ft_strlen(argv[1]) == 0)
			show_error_and_exit();
	}
	validate_arguments(arguments, argc);
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, arguments);
	sort_stack(&stack_a, &stack_b);
	cleanup(&stack_a, &stack_b, arguments, argc);
	return (0);
}
