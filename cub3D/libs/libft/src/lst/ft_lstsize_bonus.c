/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 15:49:09 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 13:05:38 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/lst.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*curr;

	i = 0;
	curr = lst;
	while (curr != NULL)
	{
		++i;
		curr = curr->next;
	}
	return (i);
}

/* #include <assert.h>
#include <stdlib.h>

int	main()
{
	t_list	*lst;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(calloc(1, sizeof(char))));
	ft_lstadd_back(&lst, ft_lstnew(calloc(1, sizeof(char))));
	ft_lstadd_back(&lst, ft_lstnew(calloc(1, sizeof(char))));

	assert(ft_lstsize(lst) == 3);

	// We expect it to not crash and give back the right value.
	lst = NULL;
	assert(ft_lstsize(lst) == 0);
} */
