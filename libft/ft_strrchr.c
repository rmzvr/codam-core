/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:29:22 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/13 19:52:36 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;
	char	*p;

	s_len = ft_strlen(s);
	p = (char *)s + s_len;
	while (p != s)
	{
		if (*p == c)
		{
			return (p);
		}
		p--;
	}
	if (*p == c)
	{
		return (p);
	}
	return (NULL);
}
