/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:44:59 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/12 18:00:27 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*char_dest;
	char	*char_src;

	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	char_dest = (char *) dest;
	char_src = (char *) src;
	if (char_dest <= char_src)
	{
		ft_memcpy(char_dest, char_src, n);
	}
	else
	{
		while (n != 0)
		{
			n--;
			char_dest[n] = char_src[n];
		}
	}
	return (dest);
}
