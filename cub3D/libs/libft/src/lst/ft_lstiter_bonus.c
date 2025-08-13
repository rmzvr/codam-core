/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 16:27:15 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 13:13:27 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/lst.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curr;

	curr = lst;
	while (curr != NULL)
	{
		f(curr->content);
		curr = curr->next;
	}
}

/* #include <stdio.h>

static void	ft_print_debug(void *content)
{
	printf("content: %p (value: %d)\n", content, *(int *)content);
}

int	main()
{
	t_list	*lst;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ft_calloc(1, sizeof(char))));
	ft_lstadd_back(&lst, ft_lstnew(ft_calloc(1, sizeof(char))));

	ft_lstiter(lst, ft_print_debug);
} */
