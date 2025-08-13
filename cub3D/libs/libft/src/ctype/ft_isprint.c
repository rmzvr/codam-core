/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 12:40:19 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 12:17:12 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/* #include <assert.h>

int	main()
{
	assert(ft_isprint(' ') == 1);
	assert(ft_isprint(127) == 0); // DEL
} */
