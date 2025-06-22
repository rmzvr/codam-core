/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:12:24 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/22 22:27:16 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtins/env/env_utils.h"

static size_t	get_variable_name_len(
	const char *variable_name,
	t_bool *no_equal_sign
)
{
	size_t	len;

	*no_equal_sign = (ft_strchr(variable_name, '=') == NULL);
	len = ft_strlen(variable_name);
	if (!*no_equal_sign)
		len--;
	return (len);
}

static size_t	get_env_key_len(
	const char *env_entry
)
{
	size_t	len;

	len = 0;
	while (env_entry[len] != '\0' && env_entry[len] != '=')
		len++;
	return (len);
}

static t_bool	is_match(
	const char *env_entry,
	const char *variable_name,
	size_t variable_len
)
{
	size_t	env_key_len;

	env_key_len = get_env_key_len(env_entry);
	if (variable_len >= env_key_len)
		env_key_len = variable_len;
	return (ft_strncmp(env_entry, variable_name, env_key_len) == 0);
}

char	*ft_getenv(
	char **envp,
	const char *variable_name
)
{
	size_t	i;
	t_bool	no_equal_sign;
	size_t	variable_len;

	i = 0;
	variable_len = get_variable_name_len(variable_name, &no_equal_sign);
	while (envp[i] != NULL)
	{
		if (is_match(envp[i], variable_name, variable_len))
		{
			if (ft_strchr(envp[i], '=') != NULL)
				return (envp[i] + get_env_key_len(envp[i]) + 1);
			return (envp[i] + get_env_key_len(envp[i]));
		}
		i++;
	}
	return (NULL);
}
