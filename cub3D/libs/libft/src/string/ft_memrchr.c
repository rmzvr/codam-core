/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 12:57:59 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/12 12:05:25 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

void	*ft_memrchr(const void *ptr, int ch, size_t n)
{
	while (n > 0)
	{
		if (((unsigned char *)ptr)[n] == (char) ch)
			return ((char *)(ptr + n));
		--n;
	}
	return (NULL);
}
