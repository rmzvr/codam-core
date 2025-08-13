/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstpop_front_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/30 10:20:04 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/30 10:25:32 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/lst.h"

t_list	*ft_lstpop_front(t_list **lst)
{
	t_list	*popped_lst;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	popped_lst = *lst;
	*lst = popped_lst->next;
	return (popped_lst);
}
