/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:32:25 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/13 19:53:01 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_count(char const *s, char c)
{
	int	i;
	int	words_count;

	i = 0;
	words_count = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && (s[i + 1] == c || s[i + 1] == '\0')))
		{
			words_count++;
		}
		i++;
	}
	return (words_count);
}

static	int	ft_word_count(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static void	ft_free_mem(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

static char	**ft_alloc_words(char const *s, char c, int words_count)
{
	int		i;
	int		j;
	char	**words;

	i = 0;
	j = 0;
	words = (char **)malloc((words_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < words_count)
	{
		while (s[j] == c)
			j++;
		words[i] = ft_substr(s + j, 0, ft_word_count(s + j, c));
		if (words[i] == NULL)
		{
			ft_free_mem(words, i);
			return (NULL);
		}
		while (s[j] != c && s[j] != '\0')
			j++;
		i++;
	}
	words[i] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		words_count;

	if (s == NULL)
		return (NULL);
	words_count = ft_words_count(s, c);
	words = ft_alloc_words(s, c, words_count);
	return (words);
}
