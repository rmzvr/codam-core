/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 12:32:47 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 12:14:29 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ctype.h"

int	ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}

/* #include <assert.h>

int	main()
{
	assert(ft_isalpha('a') == 1);
	assert(ft_isalpha('1') == 0);
	assert(ft_isalpha('!') == 0);
} */
