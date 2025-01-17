/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:46:04 by rmzvr             #+#    #+#             */
/*   Updated: 2024/12/30 16:39:15 by rzvir            ###   ########.fr       */
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
