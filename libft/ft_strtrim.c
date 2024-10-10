/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:33:26 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/10 17:13:23 by rzvir            ###   ########.fr       */
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

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	int		s1_len;
	char	*trimmed_str;

	i = 0;
	start = 0;
	end = 0;
	s1_len = ft_strlen(s1);
	while (ft_any(s1[i], set))
	{
		start++;
		i++;
	}
	i = s1_len - 1;
	while (ft_any(s1[i], set))
	{
		end++;
		i--;
	}
	trimmed_str = ft_substr(s1, start, s1_len - start - end);
	return (trimmed_str);
}

/* int    main(void)
{
	// ft_strtrim(" Hello ", " ");
	printf("%s\n", ft_strtrim("lorem ipsum dolor sit amet", "te"));
	return (0);
} */