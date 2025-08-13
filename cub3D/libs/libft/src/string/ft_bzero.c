/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 12:53:34 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 12:11:27 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/* #include <assert.h>

void	assert_mem(void *ptr, int value, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		assert(((unsigned char *)ptr)[i++] == value);
}

int	main()
{
	char	temp[3];

	ft_bzero(temp, 3);
	// We expect the function to fill the 3 bytes with NULs.
	assert_mem(temp, '\0', 3);
} */
