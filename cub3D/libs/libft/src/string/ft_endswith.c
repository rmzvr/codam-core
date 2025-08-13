/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_endswith.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/22 11:53:51 by bamarell      #+#    #+#                 */
/*   Updated: 2023/11/29 12:29:51 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

int	ft_endswith(const char *str, const char *suffix)
{
	size_t	str_len;
	size_t	suffix_len;

	str_len = ft_strlen(str);
	suffix_len = ft_strlen(suffix);
	if (suffix_len > str_len)
		return (0);
	while (suffix_len > 0)
	{
		if (str[str_len - 1] != suffix[suffix_len - 1])
			return (0);
		--str_len;
		--suffix_len;
	}
	return (1);
}
