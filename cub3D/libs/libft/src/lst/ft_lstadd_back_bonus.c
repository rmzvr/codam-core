/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 16:04:50 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 13:26:54 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/lst.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_lst;

	if (lst == NULL)
		return ;
	last_lst = ft_lstlast(*lst);
	if (last_lst == NULL)
		*lst = new;
	else
		last_lst->next = new;
}

/* #include <assert.h>

int	main()
{
	t_list	*lst;

	lst = NULL;
	// We now expect the new list to be the head
	// of the list since it didn't have one prior.
	ft_lstadd_back(&lst, ft_lstnew(ft_calloc(1, sizeof(char))));
	assert(*((char *)lst->content) == '\0'); // See if it's content matches
	assert(ft_lstsize(lst) == 1);

	int	val = 1;
	ft_lstadd_back(&lst, ft_lstnew(&val));
	// Compare the pointers and see if they point to the same address.
	assert(((int *)ft_lstlast(lst)->content) == &val);
	// Compare the value and see if they're the same value.
	assert(*((int *)ft_lstlast(lst)->content) == val);
	assert(ft_lstsize(lst) == 2);

	// We expect the function to not make the program crash.
	ft_lstadd_back(NULL, NULL);
} */
