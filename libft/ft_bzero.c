/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:44:59 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/09 17:01:24 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *) s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

/* #include <stdio.h>

int	main(void)
{
	char ft_str[] = "Hello, World!";
	char str[] = "Hello, World!";
	ft_bzero(ft_str, 10 * sizeof(char));
	printf("ft_str: %s\n", ft_str);
	bzero(str, 10 * sizeof(char));
	printf("str: %s\n", str);
	return (0);
} */
