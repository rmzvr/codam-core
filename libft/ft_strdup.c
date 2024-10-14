/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:07:56 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/13 19:52:56 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
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
