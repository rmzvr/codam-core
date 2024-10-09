/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:51:27 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/09 18:08:58 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	char	*p;
	size_t	s1_len;
	size_t	s2_len;
	size_t	full_len;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	full_len = (s1_len + s2_len + 1) * sizeof(char);
	p = (char *)malloc(full_len);
	if (p == NULL)
	{
		return (NULL);
	}
	while (i < s1_len)
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < full_len)
	{
		p[i] = s2[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	main(void)
{
	printf("%s", ft_strjoin("ABCD", "EFG"));
	return (0);
}