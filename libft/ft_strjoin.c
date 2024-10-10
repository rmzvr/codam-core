/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:51:27 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/10 13:32:30 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	size_t	joined_str_len;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_str_len = (s1_len + s2_len + 1) * sizeof(char);
	joined_str = (char *)malloc(joined_str_len);
	if (joined_str == NULL)
		return (NULL);
	while (i < joined_str_len - 1)
	{
		if (i < s1_len)
			joined_str[i] = s1[i];
		else
			joined_str[i] = s2[i - s1_len];
		i++;
	}
	joined_str[i] = '\0';
	return (joined_str);
}

/* int	main(void)
{
	printf("%s", ft_strjoin("ABC", "DEF"));
	return (0);
} */
