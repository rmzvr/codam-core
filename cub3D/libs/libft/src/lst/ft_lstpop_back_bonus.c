/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstpop_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/30 10:20:04 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/30 10:25:32 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/lst.h"

t_list	*ft_lstpop_back(t_list **lst)
{
	t_list	*temp;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	if ((*lst)->next == NULL)
		return (ft_lstpop_front(lst));
	while (*lst)
	{
		if ((*lst)->next->next == NULL)
			break ;
		lst = &(*lst)->next;
	}
	temp = (*lst)->next;
	(*lst)->next = NULL;
	return (temp);
}

/* #include <assert.h>

int	main()
{
	t_list	*lst;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ft_calloc(1, sizeof(char))));
	ft_lstadd_back(&lst, ft_lstnew(ft_calloc(1, sizeof(char))));
	ft_lstadd_back(&lst, ft_lstnew(ft_calloc(1, sizeof(char))));
	assert(ft_lstsize(lst) == 3);
	ft_lstpop_back(&lst);
	assert(ft_lstsize(lst) == 2);
	ft_lstpop_back(&lst);
	assert(ft_lstsize(lst) == 1);
	ft_lstpop_back(&lst);
	assert(ft_lstsize(lst) == 0);
} */
