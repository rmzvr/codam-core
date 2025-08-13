/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchroc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 13:04:06 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 12:38:28 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

size_t	ft_strchroc(const char *str, int c)
{
	size_t	i;
	size_t	occurrences;

	i = 0;
	occurrences = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			++occurrences;
		++i;
	}
	return (occurrences);
}
