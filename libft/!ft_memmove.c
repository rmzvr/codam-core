/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:44:59 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/08 12:44:57 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*char_dest;
	char	*char_src;

	i = 0;
	char_dest = (char *) dest;
	char_src = (char *) src;
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}

int	main(void)
{
	char	ft_str1[] = "Test";
	char	ft_str2[] = "Hello";
	ft_memmove(ft_str1, ft_str2, sizeof(ft_str2));
	printf("ft_memmove: %s\n", ft_str1);

	char	str1[] = "Test";
	char	str2[] = "Hello";
	memmove(str1, str2, sizeof(str2) - 1);
	printf("memmove: %s\n", str1);
	return (0);
}