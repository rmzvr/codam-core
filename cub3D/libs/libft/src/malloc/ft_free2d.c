/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free2d.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/15 17:55:53 by bamarell      #+#    #+#                 */
/*   Updated: 2025/07/15 17:55:53 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/malloc.h"

void	ft_free2d(void **ptr)
{
	size_t	i;

	i = 0;
	if (ptr == NULL)
		return ;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		++i;
	}
	free(ptr);
}
