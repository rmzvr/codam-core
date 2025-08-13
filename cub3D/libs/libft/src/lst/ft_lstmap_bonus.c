/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 16:29:13 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 13:20:38 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/lst.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curr;
	t_list	*new_lst;
	t_list	*node;

	curr = lst;
	new_lst = NULL;
	if (curr == NULL)
		return (NULL);
	while (curr != NULL)
	{
		node = ft_lstnew(f(curr->content));
		if (node == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		curr = curr->next;
	}
	return (new_lst);
}

/* #include <assert.h>
#include <stdio.h>

static void	*ft_lstmapper(void *content)
{
	static int	value;

	value = 1;
	printf("mapper received: %p (value: %d)\n", content, *(int *)content);
	return (&value);
}

static void	ft_print_debug(void *content)
{
	printf("read content: %p (value: %d)\n", content, *(int *)content);
}

int	main()
{
	t_list	*lst;
	t_list	*mapped_lst;
	int		lst_size;

	// Add 3 lists to the back
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ft_calloc(1, sizeof(char))));
	ft_lstadd_back(&lst, ft_lstnew(ft_calloc(1, sizeof(char))));
	ft_lstadd_back(&lst, ft_lstnew(ft_calloc(1, sizeof(char))));
	// We store it locally and compare it to the mapped list
	lst_size = ft_lstsize(lst);
	assert(lst_size == 3);

	mapped_lst = ft_lstmap(lst, ft_lstmapper, free);
	assert(ft_lstsize(mapped_lst) == lst_size);
	ft_lstiter(mapped_lst, ft_print_debug);
} */
