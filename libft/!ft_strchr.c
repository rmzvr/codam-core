/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:29:22 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/08 10:43:06 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char *p;

	*p = s;
	while (*p != '\0')
	{
		if (*p == c)
			return (p);
		p++;
	}
	return (p);
}

int	main(void)
{
	printf("ft_strchr: %s", ft_strchr("str", 's'));
	printf("strchr: %s", strchr("str", 's'));
	return (0);
}