/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_array_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:09:34 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/22 15:11:27 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd/exec_cmd.h"

void	ft_char_array_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

size_t	ft_char_array_len(char **argv)
{
	size_t	len;

	len = 0;
	while (argv[len] != NULL)
		len++;
	return (len);
}

char	**copy_char_array(char **src, size_t count)
{
	char	**dest;
	size_t	i;

	if (count == 0 || src == NULL || *src == NULL)
		return (NULL);
	dest = (char **)malloc((count + 1) * sizeof(char *));
	if (dest == NULL)
	{
		ft_putendl_fd(MEMERR, STDERR_FILENO);
		return (NULL);
	}
	i = 0;
	while (i < count && src[i])
	{
		dest[i] = ft_strdup(src[i]);
		if (dest[i] == NULL)
		{
			ft_putendl_fd(MEMERR, STDERR_FILENO);
			ft_free_double_char_pointer(&dest);
			return (NULL);
		}
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

char	*ft_stringtrim(char *s1, char const *set)
{
	int		start;
	int		end;
	int		s1_len;
	char	*trimmed_str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	start = ft_count_any(s1, set, 0);
	if (s1_len == start)
	{
		protected_free(&s1);
		return (ft_strdup(""));
	}
	end = ft_count_any(s1 + s1_len - 1, set, 1);
	trimmed_str = ft_substr(s1, start, s1_len - start - end);
	if (trimmed_str == NULL)
	{
		protected_free(&s1);
		return (ft_strdup(""));
	}
	protected_free(&s1);
	return (trimmed_str);
}
