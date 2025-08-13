/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 13:15:27 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 12:12:34 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/string.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && (nmemb * size) / size != nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/* #include <assert.h>
#include <stdint.h>

void	assert_mem(void *ptr, int value, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		assert(((unsigned char *)ptr)[i++] == value);
}

int	main()
{
	char	*ptr;

	ptr = ft_calloc(5, sizeof(char));
	assert_mem(ptr, '\0', 5);
	free(ptr);

	ptr = ft_calloc(0, 0);
	free(ptr);

	// Negative values will make the value of whatever
	// parameter it is, overflow.
	// We expect the function to give back a NULL
	// and not crash the program.
	ptr = ft_calloc(-1, -1);
	assert(ptr == NULL);

	// It should handle these accordingly and not crash.
	ptr = ft_calloc(SIZE_MAX, SIZE_MAX);
	assert(ptr == NULL);
} */
