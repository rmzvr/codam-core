/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 13:03:08 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 11:26:08 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ctype.h"

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	return (c);
}

/* #include <assert.h>

int	main()
{
	assert(ft_toupper('A') == 'a');
	assert(ft_toupper('a') == 'a');
	assert(ft_toupper('?') == '?');
} */
