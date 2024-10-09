/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:29:22 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/09 16:57:41 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	if (*p == c)
	{
		return (p);
	}
	while (*p != '\0')
	{
		if (*p == c)
			return (p);
		p++;
	}
	return (NULL);
}

/* int	main(void)
{
	printf("ft_strchr: %s\n", ft_strchr("str", 't'));
	printf("strchr: %s\n", strchr("str", 't'));
	return (0);
} */
