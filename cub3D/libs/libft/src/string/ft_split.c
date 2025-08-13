/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 12:38:21 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/12 11:43:22 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/string.h"

static size_t	ft_get_word_length(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		++i;
	return (i);
}

static size_t	ft_count_words(const char *str, char c)
{
	size_t	word_count;
	size_t	word_length;
	size_t	i;

	word_count = 0;
	word_length = 0;
	i = 0;
	while (str[i] != '\0')
	{
		word_length = ft_get_word_length(str + i, c);
		if (word_length == 0)
		{
			++i;
			continue ;
		}
		++word_count;
		i += word_length;
	}
	return (word_count);
}

static void	ft_free_split(char **split, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(split[i]);
		++i;
	}
	free(split);
}

static int	ft_append_split(char **split, char *str, t_split_section *section)
{
	int	is_appended;

	split[section->index] = ft_substr(str, section->start, section->length);
	is_appended = split[section->index] != NULL;
	if (is_appended)
		++section->index;
	return (is_appended);
}

char	**ft_split(const char *str, char sep)
{
	char			**split;
	t_split_section	section;
	size_t			index;
	size_t			word_count;

	index = 0;
	section = (t_split_section){.length = 0, .start = 0, .index = 0};
	word_count = ft_count_words(str, sep) + 1;
	split = (char **)ft_calloc(word_count, sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (str[index] != '\0')
	{
		section.start = index;
		section.length = ft_get_word_length(str + index, sep);
		if (section.length == 0)
			++index;
		else if (!ft_append_split(split, (char *)str, &section))
		{
			ft_free_split(split, section.index + 1);
			return (NULL);
		}
		index += section.length;
	}
	return (split);
}

/* #include <assert.h>
#include <stdio.h>

void	assert_str_arr_eq(char *arr1[], char *arr2[], size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		printf("[%ld] %s <=> %s\n", i, arr1[i], arr2[i]);
		assert(strcmp(arr1[i], arr2[i]) == 0);
		++i;
	}
}

int	main()
{
	char	**split;

	split = ft_split("this is cool", ' ');
	assert(split[3] == NULL);
	assert_str_arr_eq(split, (char*[]){"this", "is", "cool"}, 3);
	ft_free_split(split, 3);

	split = ft_split("  abc  hello world  ", ' ');
	assert(split[3] == NULL);
	assert_str_arr_eq(split, (char*[]){"abc", "hello", "world"}, 3);
	ft_free_split(split, 3);

	// We don't actually expect any string out of this.
	split = ft_split("", ' ');
	assert(split[0] == NULL);
	ft_free_split(split, 0);

	// Same with this, we don't want any empty strings.
	split = ft_split("          ", ' ');
	assert(split[0] == NULL);
	ft_free_split(split, 0);

	split = ft_split("123 321 ", ' ');
	assert(split[2] == NULL);
	assert_str_arr_eq(split, (char*[]){"123", "321"}, 2);
	ft_free_split(split, 2);
} */
