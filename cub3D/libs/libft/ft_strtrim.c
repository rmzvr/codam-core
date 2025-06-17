/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:33:26 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/12 19:19:36 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_any(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_count_any(char const *s1, char const *set, int to_left)
{
	int	count;

	count = 0;
	while (ft_any(*s1, set))
	{
		count++;
		if (to_left == 0)
		{
			s1++;
		}
		else
		{
			s1--;
		}
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		s1_len;
	char	*trimmed_str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	start = ft_count_any(s1, set, 0);
	end = ft_count_any(s1 + s1_len - 1, set, 1);
	trimmed_str = ft_substr(s1, start, s1_len - start - end);
	return (trimmed_str);
}
