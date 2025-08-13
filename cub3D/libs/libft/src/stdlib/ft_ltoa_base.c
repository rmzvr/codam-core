/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ltoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 12:48:48 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/19 13:02:19 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"
#include "libft/malloc.h"
#include "libft/string.h"

static size_t	ft_getdigits(long nb, long base_len)
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

char	*ft_ltoa_base(long nb, char *base, int sign)
{
	char	*str;
	size_t	digits;
	long	base_len;

	base_len = (long) ft_strlen(base);
	digits = ft_getdigits(nb, base_len);
	if (nb < 0 && sign)
		++digits;
	str = ft_calloc(digits + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	if (nb < 0 && sign)
		str[0] = '-';
	while (nb != 0)
	{
		str[--digits] = base[ft_labs(nb % base_len)];
		nb /= base_len;
	}
	return (str);
}
