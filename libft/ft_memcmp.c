/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:28:26 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/13 00:32:48 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_p;
	unsigned char	*s2_p;

	i = 0;
	s1_p = (unsigned char *) s1;
	s2_p = (unsigned char *) s2;
	while (i != n)
	{
		if (s1_p[i] != s2_p[i])
		{
			return (s1_p[i] - s2_p[i]);
		}
		i++;
	}
	return (0);
}
