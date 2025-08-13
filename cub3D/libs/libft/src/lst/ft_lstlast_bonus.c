/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 15:51:38 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 13:10:43 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/lst.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	curr = lst;
	if (curr == NULL)
		return (NULL);
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}

/* #include <assert.h>

int	main()
{
	t_list	*lst;
	t_list	*last_node;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ft_calloc(1, sizeof(char))));
	ft_lstadd_back(&lst, ft_lstnew(ft_calloc(1, sizeof(char))));
	assert(ft_lstsize(lst) == 2);

	last_node = ft_lstlast(lst);
	assert(last_node != NULL);
	assert(last_node->content != NULL);
	assert(((char *)last_node->content)[0] == '\0');
} */
