/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:07:56 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/08 18:23:26 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*strdup(const char *s)
{
	int		i;
	char	*copy;
	int		s_len;

	i = 0;
	s_len = ft_strlen(s);
	copy = (char *)malloc((s_len + 1) * sizeof(char));
	if (copy == NULL)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	main(void)
{
	char *ptr;

	ptr = strdup("String!");
	free(ptr);
	return (0);
}