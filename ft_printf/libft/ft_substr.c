/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:15:53 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/16 15:06:01 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	*ft_get_empty_substr(void)
{
	unsigned char	*substr;

	substr = (unsigned char *)malloc(1);
	if (substr == NULL)
		return (NULL);
	substr[0] = '\0';
	return (substr);
}

static size_t	ft_calc_alloc_len(size_t substr_len, size_t start, size_t len)
{
	size_t	alloc_len;

	alloc_len = substr_len - start;
	if (alloc_len > len)
	{
		alloc_len = len;
	}
	return (alloc_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			alloc_len;
	size_t			substr_len;
	unsigned char	*substr;

	if (s == NULL)
		return (NULL);
	substr_len = ft_strlen(s);
	if (start >= substr_len)
	{
		substr = ft_get_empty_substr();
		return ((char *)substr);
	}
	alloc_len = ft_calc_alloc_len(substr_len, start, len);
	substr = (unsigned char *)malloc((alloc_len + 1) * sizeof(unsigned char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < alloc_len && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return ((char *)substr);
}
