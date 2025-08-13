/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 12:36:35 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 12:13:35 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ctype.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/* #include <assert.h>

int	main()
{
	assert(ft_isalnum('a') == 1);
	assert(ft_isalnum('1') == 1);
	assert(ft_isalnum('!') == 0);
} */
