/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:27:03 by rmzvr             #+#    #+#             */
/*   Updated: 2024/10/13 19:55:55 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	new_list = NULL;
	while (lst != NULL)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/* int	main(void)
{
	t_list *curr_node;

	t_list *root_node;

	t_list *new_node1;
	t_list *new_node2;
	t_list *new_node3;

	root_node = malloc(sizeof(t_list));
	root_node->content = "Root node";
	root_node->next = NULL;

	new_node1 = malloc(sizeof(t_list));
	new_node1->content = "New node 1";
	new_node1->next = NULL;

	new_node2 = malloc(sizeof(t_list));
	new_node2->content = "New node 2";
	new_node2->next = NULL;

	new_node3 = malloc(sizeof(t_list));
	new_node3->content = "New node 3";
	new_node3->next = NULL;

	ft_lstadd_back(&root_node, new_node1);
	ft_lstadd_front(&root_node, new_node2);
	ft_lstadd_front(&root_node, new_node3);

	curr_node = root_node;

	// while (curr_node != NULL)
	// {
	// 	printf("%s\n", (char *)(curr_node->content));
	// 	curr_node = curr_node->next;
	// }
	// printf("%s\n", (char *)(ft_lstlast(curr_node)->content));
	return (0);
} */
