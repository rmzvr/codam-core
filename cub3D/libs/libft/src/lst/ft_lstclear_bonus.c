/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 16:19:54 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 13:36:25 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/lst.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;

	if (lst == NULL || del == NULL)
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		*lst = curr->next;
		ft_lstdelone(curr, del);
		curr = *lst;
	}
}

/* #include <assert.h>

int	main()
{
	t_list	*lst;

	lst = NULL;
	// List of 2 nodes
	ft_lstadd_back(&lst, ft_lstnew(calloc(1, sizeof(char))));
	ft_lstadd_back(&lst, ft_lstnew(calloc(1, sizeof(char))));
	assert(ft_lstsize(lst) == 2);
	ft_lstclear(&lst, free);
	// We now expect the list to be completely empty and thus
	// the head should be pointing to NULL
	assert(lst == NULL);
	assert(ft_lstsize(lst) == 0);

	// Here we demonstrate the program protecting itself against
	// trying to clear an already empty list.
	ft_lstclear(&lst, free);

	// We expect the function to not make the program crash.
	ft_lstclear(NULL, NULL);
} */
