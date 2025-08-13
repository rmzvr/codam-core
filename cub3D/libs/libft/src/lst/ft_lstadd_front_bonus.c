/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 15:46:53 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/12 12:08:16 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/lst.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL)
		return ;
	if (*lst != NULL)
		new->next = *lst;
	*lst = new;
}

/* #include <assert.h>
#include <stdlib.h>

int	main()
{
	t_list	*lst;
	t_list	*new_front;

	lst = NULL;
	// Build up the initial head node.
	new_front = ft_lstnew(ft_calloc(1, sizeof(char)));
	ft_lstadd_front(&lst, new_front);
	// Check and make sure it actually worked.
	assert(ft_lstsize(lst) == 1);
	// We expect the pointers to now align, since it became the head
	// of the list.
	assert(new_front == lst);
	assert(*(char *)lst->content == '\0');

	// We make a new front and change the pointer to reuse for
	// comparison below.
	new_front = ft_lstnew(ft_calloc(1, sizeof(char)));
	ft_lstadd_front(&lst, new_front);
	// Make sure it was added.
	assert(ft_lstsize(lst) == 2);
	// Compare the new pointer with the head of the list.
	assert(new_front == lst);
	assert(*(char *)lst->content == '\0');

	// We expect the function to not make the program crash.
	ft_lstadd_front(NULL, NULL);
} */
