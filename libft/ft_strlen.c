/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:33:29 by rmzvr             #+#    #+#             */
/*   Updated: 2024/10/07 21:41:16 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

size_t	ft_strlen(const char *s)
{
	size_t i;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	main(void)
{
	printf("ft_strlen: %ld\n", ft_strlen("abc"));
	printf("strlen: %ld\n", strlen("abc"));
	return (0);
}