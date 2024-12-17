/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:29:22 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/14 11:11:29 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			s_len;
	unsigned char	*str;
	unsigned char	chr;

	s_len = ft_strlen(s);
	chr = (unsigned char) c;
	str = (unsigned char *) s + s_len;
	while (str != (unsigned char *)s)
	{
		if (*str == chr)
		{
			return ((char *)str);
		}
		str--;
	}
	if (*str == chr)
	{
		return ((char *)str);
	}
	return (NULL);
}
