/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:28:26 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/09 17:00:48 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const char	*p;

	p = s1 + n;
	while (s1 != p)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (0);
}

/* int	main(void)
{
	printf("ft_strncmp: %d\n", ft_strncmp("ABC", "A", 3));
	printf("strncmp: %d\n", strncmp("ABC", "A", 3));
	return (0);
} */