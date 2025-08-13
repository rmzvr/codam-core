/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 12:36:59 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 12:15:57 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/* #include <assert.h>

int	main()
{
	assert(ft_isascii(' ') == 1);
	assert(ft_isascii('!') == 1);
	assert(ft_isascii(127) == 1); // DEL
	assert(ft_isascii(128) == 0); // Invalid
} */
