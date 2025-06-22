/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putenv_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:24:48 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/21 19:44:53 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/env/putenv.h"

char	**ft_create_new_env_variable(
	char **envp,
	const char *variable,
	const char *value
)
{
	char	**new_envp;
	size_t	str_len;

	str_len = ft_char_array_len(envp);
	new_envp = copy_char_array(envp, str_len + 1);
	if (!new_envp)
	{
		return (NULL);
	}
	new_envp[str_len] = ft_strjoin(variable, value);
	if (new_envp[str_len] == NULL)
	{
		ft_putendl_fd(MEMERR, STDERR_FILENO);
		ft_free_double_char_pointer(&new_envp);
		return (NULL);
	}
	new_envp[str_len + 1] = NULL;
	return (new_envp);
}

static int	check_alloc_fail(
	char	**new_envp,
	size_t	i,
	char	*env_variable_name
){
	if (env_variable_name == NULL)
	{
		ft_putendl_fd(MEMERR, STDERR_FILENO);
		ft_free_double_char_pointer(&new_envp);
		return (EMALLOC);
	}
	if (new_envp[i] == NULL)
	{
		ft_putendl_fd(MEMERR, STDERR_FILENO);
		ft_free_double_char_pointer(&new_envp);
		protected_free(&env_variable_name);
		return (EMALLOC);
	}
	return (0);
}

char	**ft_replace_env_value(
	char		**envp,
	const char	*variable,
	const char	*value
)
{
	char	*env_variable_name;
	char	**new_envp;
	size_t	i;

	i = 0;
	new_envp = copy_char_array(envp, ft_char_array_len(envp));
	if (new_envp == NULL)
		return (ft_putendl_fd(MEMERR, STDERR_FILENO), NULL);
	while (new_envp[i] != NULL)
	{
		env_variable_name = get_variable_name(new_envp[i], TRUE);
		if (check_alloc_fail(new_envp, i, env_variable_name) == EMALLOC)
			return (NULL);
		if (ft_strncmp(env_variable_name, variable,
				ft_strlen(env_variable_name)) == 0)
		{
			protected_free(&new_envp[i]);
			new_envp[i] = ft_strjoin(variable, value);
			if (check_alloc_fail(new_envp, i, env_variable_name) == EMALLOC)
				return (NULL);
		}
		protected_free(&env_variable_name);
		i++;
	}
	return (new_envp);
}

static int	concat_str_to_val(
	char	**new_envp,
	size_t	index,
	char	*env_var_name,
	const char	*str
)
{
	new_envp[index] = protect_strjoin(new_envp[index], (char *)str);
	return (check_alloc_fail(new_envp, index, env_var_name));
}

char	**ft_concat_env_value(
	char		**envp,
	const char	*variable,
	char	*value
)
{
	size_t	i;
	char	*var_name;
	char	**new_envp;

	i = 0;
	new_envp = copy_char_array(envp, ft_char_array_len(envp));
	if (new_envp == NULL)
		return (ft_putendl_fd(MEMERR, STDERR_FILENO), NULL);
	while (new_envp[i] != NULL)
	{
		var_name = get_variable_name(new_envp[i], TRUE);
		if (check_alloc_fail(new_envp, i, var_name) == EMALLOC)
			return (NULL);
		if (ft_strncmp(var_name, variable, ft_strlen(var_name)) == 0)
		{
			if (ft_strchr(new_envp[i], '=') == NULL)
				if (concat_str_to_val(new_envp, i, var_name, "=") == EMALLOC)
					return (NULL);
			if (concat_str_to_val(new_envp, i, var_name, value) == EMALLOC)
				return (NULL);
		}
		protected_free(&var_name);
		i++;
	}
	return (new_envp);
}
