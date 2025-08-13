/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 18:35:46 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/19 13:02:23 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"
#include "libft/malloc.h"
#include "libft/string.h"

static size_t	ft_getdigits(unsigned int nb, long base_len)
{
	size_t	i;

	i = 1;
	while (nb / base_len)
	{
		nb /= base_len;
		++i;
	}
	return (i);
}

char	*ft_utoa_base(unsigned int nb, char *base)
{
	char	*str;
	size_t	digits;
	size_t	base_len;

	base_len = ft_strlen(base);
	digits = ft_getdigits(nb, base_len);
	str = ft_calloc(digits + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		str[--digits] = base[ft_abs(nb % base_len)];
		nb /= base_len;
	}
	return (str);
}
