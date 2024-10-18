/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:46:04 by rmzvr             #+#    #+#             */
/*   Updated: 2024/10/13 12:22:20 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list_item;

	list_item = malloc(sizeof(t_list));
	if (list_item == NULL)
	{
		return (NULL);
	}
	list_item->content = content;
	list_item->next = NULL;
	return (list_item);
}
