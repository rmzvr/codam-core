/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:49:09 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/12 17:18:48 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	size_t	s_len;
	char	*m;

	if (s == NULL)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	m = (char *)malloc((s_len + 1) * sizeof(char));
	if (m == NULL)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		m[i] = f(i, s[i]);
		i++;
	}
	m[i] = '\0';
	return (m);
}
