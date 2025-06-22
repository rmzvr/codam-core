/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:10:08 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/15 16:10:09 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd/exec_cmd.h"

size_t	get_variable_len(const char *word)
{
	size_t	variable_len;

	variable_len = 0;
	while (word && word[variable_len] != '\0' && word[variable_len] != '=')
	{
		variable_len++;
	}
	return (variable_len);
}

char	*get_variable_name(const char *word, t_bool add_equal_sign)
{
	size_t	variable_len;

	variable_len = get_variable_len(word);
	if (add_equal_sign && word[variable_len] == '=')
	{
		variable_len++;
	}
	return (ft_strndup(word, variable_len));
}

char	*protect_strjoin(char *s1, char *s2)
{
	char	*buffer;

	buffer = ft_strjoin(s1, s2);
	if (buffer == NULL)
	{
		protected_free(&s1);
		return (NULL);
	}
	protected_free(&s1);
	return (buffer);
}
