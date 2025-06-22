/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:24:48 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/21 19:44:55 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/env/putenv.h"

static char	*ft_replace_plus(
	char **variable
)
{
	char	*variable_without_plus;
	size_t	i;

	variable_without_plus = malloc(sizeof(char) * ft_strlen((*variable)));
	if (variable_without_plus == NULL)
	{
		ft_putendl_fd(MEMERR, STDERR_FILENO);
		protected_free(variable);
		return (NULL);
	}
	i = 0;
	while ((*variable)[i] != '+' && (*variable)[i] != '\0')
	{
		variable_without_plus[i] = (*variable)[i];
		i++;
	}
	variable_without_plus[i++] = '=';
	variable_without_plus[i] = '\0';
	protected_free(variable);
	return (variable_without_plus);
}

static int	detect_and_strip_concat_flag(
	const char *var_val,
	char **variable
)
{
	t_bool	to_concate;
	size_t	variable_len;

	to_concate = FALSE;
	(*variable) = get_variable_name(var_val, TRUE);
	if ((*variable) == NULL)
	{
		ft_putendl_fd(MEMERR, STDERR_FILENO);
		return (EMALLOC);
	}
	variable_len = ft_strlen(*variable);
	if (variable_len >= 2 && ((*variable)[variable_len - 2]) == '+')
	{
		to_concate = TRUE;
		(*variable) = ft_replace_plus(variable);
		if ((*variable) == NULL)
		{
			return (EMALLOC);
		}
	}
	return (to_concate);
}

int	change_or_add_env_variable(
	char ***env_root,
	char *variable,
	char *value,
	int to_concate
)
{
	char	**new_envp;

	new_envp = NULL;
	if (ft_getenv(*env_root, variable) == NULL)
	{
		new_envp = ft_create_new_env_variable(*env_root, variable, value);
	}
	else
	{
		if (to_concate && value)
			new_envp = ft_concat_env_value(*env_root, variable, value);
		else
			new_envp = ft_replace_env_value(*env_root, variable, value);
	}
	if (new_envp == NULL)
	{
		return (EMALLOC);
	}
	ft_free_double_char_pointer(env_root);
	*env_root = new_envp;
	return (0);
}

int	ft_putenv(
	char ***env_root,
	char *var_val
)
{
	char	*variable;
	char	*value;
	int		concat;
	int		exit_code;

	exit_code = 0;
	concat = detect_and_strip_concat_flag(var_val, &variable);
	if (concat == EMALLOC)
		return (EMALLOC);
	exit_code = proceed_var_val(var_val, variable, &value, concat);
	if (exit_code == EMALLOC)
		return (EMALLOC);
	else if (exit_code == 1)
		value = NULL;
	exit_code = change_or_add_env_variable(env_root, variable, value, concat);
	if (exit_code == EMALLOC)
	{
		protected_free(&variable);
		protected_free(&value);
		return (EMALLOC);
	}
	protected_free(&variable);
	protected_free(&value);
	return (0);
}
