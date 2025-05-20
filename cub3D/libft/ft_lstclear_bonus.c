/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:08:34 by rmzvr             #+#    #+#             */
/*   Updated: 2024/10/13 19:51:52 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_to_delete;
	t_list	*curr;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		lst_to_delete = curr;
		curr = curr->next;
		del(lst_to_delete->content);
		free(lst_to_delete);
	}
	*lst = NULL;
}
