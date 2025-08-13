/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 15:45:04 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 14:11:32 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/lst.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

/* #include <assert.h>

int	main()
{
	t_list	*lst;

	lst = ft_lstnew(ft_calloc(1, sizeof(char)));
	assert(lst != NULL);
	assert(lst->content != NULL);
	assert(lst->next == NULL);
	assert(((char *)lst->content)[0] == '\0');
} */
