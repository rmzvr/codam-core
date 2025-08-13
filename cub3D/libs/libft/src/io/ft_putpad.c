/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putpad.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 12:57:59 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/12 12:05:25 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft/string.h"
#include "libft/math.h"

#define PAD_SIZE 256

void	ft_putpad(int pad, int len)
{
	char	pads[PAD_SIZE];

	if (len <= 0)
		return ;
	ft_memset(pads, pad, PAD_SIZE);
	while (len != 0)
	{
		write(1, pads, ft_min(len, PAD_SIZE));
		len -= ft_min(len, PAD_SIZE);
	}
}
