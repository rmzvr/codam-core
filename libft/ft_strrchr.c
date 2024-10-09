/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:29:22 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/09 16:58:36 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;
	char	*p;

	s_len = ft_strlen(s);
	p = (char *)s + s_len;
	if (*p == c)
	{
		return (p);
	}
	while (p != s)
	{
		if (*p == c)
		{
			return (p);
		}
		p--;
	}
	return (NULL);
}

/* int	main(void)
{
	printf("ft_strrchr: %s\n", ft_strrchr("str", ' '));
	printf("strrchr: %s\n", strrchr("str", ' '));
	return (0);
} */
