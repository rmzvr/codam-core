/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:29:22 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/09 17:02:33 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	*last_p;

	p = (unsigned char *)s;
	last_p = p + n;
	while (p != last_p)
	{
		if (*p == c)
			return (p);
		p++;
	}
	return (NULL);
}

/* int	main(void)
{
	printf("ft_memchr: %s\n", (char *)ft_memchr("str", '\0', 4));
	printf("memchr: %s\n", (char *)memchr("str", '\0', 4));
	return (0);
} */
