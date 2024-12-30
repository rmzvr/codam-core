/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:33:37 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/30 18:22:19 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	show_error_and_exit()
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	validate_arguments(char **argv)
{
	int		i;
	int		j;
	int		arg;
	size_t	arg_len;

	i = 1;
	j = 1;
	while (argv[i] != NULL)
	{
		arg = ft_atoi(argv[i]);
		arg_len = ft_strlen(argv[i]);
		if ((arg == 0 && argv[i][0] != '0') || arg_len != ft_nbrlen(arg))
			show_error_and_exit();
		j = 1;
		while (argv[j] != NULL)
		{
			if (i != j && arg == ft_atoi(argv[j]))
				show_error_and_exit();
			j++;
		}
		i++;
	}
	ft_printf("\n\nALL ARGUMENTS ARE VALID\n\n\n");
}

void	ft_lstswap(t_list **lst)
{
	t_list	*curr_node;
	t_list	*next_node;

	if (lst == NULL || *lst == NULL)
		return ;
	curr_node = *lst;
	next_node = curr_node->next;
	curr_node->next = next_node->next;
	next_node->next = *lst;
	*lst = next_node;
}



void	swap(char *operation, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(operation, "sa", 2) == 0)
	{
		if (ft_lstsize(*stack_a) < 2)
			return ;
		ft_lstswap(stack_a);
		ft_printf("sa\n");
	}
	else if (ft_strncmp(operation, "sb", 2) == 0)
	{
		if (ft_lstsize(*stack_b) < 2)
			return ;
		ft_lstswap(stack_b);
		ft_printf("sb\n");
	}
	else if (ft_strncmp(operation, "ss", 2) == 0)
	{
		if (ft_lstsize(*stack_a) >= 2)
			ft_lstswap(stack_a);
		if (ft_lstsize(*stack_b) >= 2)
			ft_lstswap(stack_b);
		ft_printf("ss\n");
	}
}



void	pr(void *c)
{
	// (void) c;
	ft_printf("stack: %d\n", *(int *)c);
}

void	dl(void *c)
{
	free(c);
	c = NULL;
}

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

void	ft_lstrotate(t_list **lst)
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

void	ft_lstrotate_rev(t_list **lst)
{
	t_list	*curr_node;

	if (lst == NULL || *lst == NULL)
		return ;
	curr_node = *lst;
	ft_lstadd_back(lst, curr_node);
	*lst = curr_node->next;
	curr_node->next = NULL;
}

void	rotate(char *operation, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(operation, "ra", 2) == 0)
	{
		ft_lstrotate(stack_a);
		ft_printf("ra\n");
	}
	else if (ft_strncmp(operation, "rb", 2) == 0)
	{
		ft_lstrotate(stack_b);
		ft_printf("rb\n");
	}
	else if (ft_strncmp(operation, "rr", 2) == 0)
	{
		ft_lstrotate(stack_a);
		ft_lstrotate(stack_b);
		ft_printf("rr\n");
	}
}

void	rotate_rev(char *operation, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(operation, "rra", 2) == 0)
	{
		ft_lstrotate_rev(stack_a);
		ft_printf("rra\n");
	}
	else if (ft_strncmp(operation, "rrb", 2) == 0)
	{
		ft_lstrotate_rev(stack_b);
		ft_printf("rrb\n");
	}
	else if (ft_strncmp(operation, "rrr", 2) == 0)
	{
		ft_lstrotate_rev(stack_a);
		ft_lstrotate_rev(stack_b);
		ft_printf("rrr\n");
	}
}

void	ft_remove_file(t_list **list, int *content)
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
		ft_lstadd_front(stack_a, arg);
		ft_remove_file(stack_b, content);
		ft_printf("pa\n");
	}
	else if (ft_strncmp(operation, "pb", 2) == 0)
	{
		if (*stack_a == NULL)
			return ;
		content = (*stack_a)->content;
		arg = ft_lstnew(content);
		ft_lstadd_front(stack_b, arg);
		ft_remove_file(stack_a, content);
		ft_printf("pb\n");
	}
}

void	init_stack(t_list **stack, char **argv)
{
	int		i;
	t_list	*arg;
	int		*value;

	i = 1;
	while (argv[i] != NULL)
	{
		value = malloc(sizeof(int));
		if (value == NULL)
			exit(EXIT_FAILURE);
		*value = ft_atoi(argv[i]);
		arg = ft_lstnew(value);
		ft_lstadd_back(stack, arg);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list* stack_a;
	t_list* stack_b;

	if (argc == 1)
		exit(EXIT_FAILURE);
	validate_arguments(argv);
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, argv);
	ft_printf("====================\nstack_a before\n====================\n");
	ft_lstiter(stack_a, pr);
	ft_printf("====================\nstack_b before\n====================\n");
	ft_lstiter(stack_b, pr);
	ft_printf("====================\n");
	rotate_rev("rra", &stack_a, &stack_b);
	rotate_rev("rra", &stack_a, &stack_b);
	rotate_rev("rra", &stack_a, &stack_b);
	rotate_rev("rra", &stack_a, &stack_b);
	rotate_rev("rra", &stack_a, &stack_b);
	// rotate_rev("rra", &stack_a, &stack_b);
	// rotate_rev("rra", &stack_a, &stack_b);
	// push("pb", &stack_a, &stack_b);
	// push("pb", &stack_a, &stack_b);
	// swap("ss", &stack_a, &stack_b);
	// push("pb", &stack_a, &stack_b);
	// push("pa", &stack_a, &stack_b);
	// push("pa", &stack_a, &stack_b);
	// push("pa", &stack_a, &stack_b);
	ft_printf("====================\nstack_a after\n====================\n");
	ft_lstiter(stack_a, pr);
	ft_printf("====================\n");
	ft_printf("====================\nstack_b after\n====================\n");
	ft_lstiter(stack_b, pr);
	ft_printf("====================\n");
	ft_lstclear(&stack_a, dl);
	stack_a = NULL;
	ft_lstclear(&stack_b, dl);
	stack_b = NULL;
	return (0);
}
