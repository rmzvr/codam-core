/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/15 00:00:00 by bamarell      #+#    #+#                 */
/*   Updated: 2025/07/15 00:00:00 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

#include "libft/string.h"

void	*ft_realloc(void *ptr, size_t psize, size_t size)
{
	void	*new_ptr;

	if (size == 0 && ptr == NULL)
	{
		free((void *) ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(size));
	if (size >= SIZE_MAX / 2 - 4096)
		return (NULL);
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	ft_memcpy(new_ptr, ptr, psize);
	free((void *) ptr);
	return (new_ptr);
}
