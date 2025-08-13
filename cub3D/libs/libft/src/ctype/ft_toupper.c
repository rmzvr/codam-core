/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 13:01:08 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 11:25:27 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ctype.h"

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}

/* #include <assert.h>

int	main()
{
	assert(ft_toupper('a') == 'A');
	assert(ft_toupper('A') == 'A');
	assert(ft_toupper('?') == '?');
} */
