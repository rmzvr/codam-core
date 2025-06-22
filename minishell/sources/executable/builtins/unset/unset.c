/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:31:08 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/24 20:42:36 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/env/env_utils.h"

int	skip_element(
	char ***new_envp,
	char *var_to_find,
	size_t *j
)
{
	char	*variable_name;

	variable_name = get_variable_name((*new_envp)[*j], FALSE);
	if (variable_name == NULL)
	{
		protected_free(&variable_name);
		ft_putendl_fd(MEMERR, STDERR_FILENO);
		return (EMALLOC);
	}
	if (ft_strcmp(var_to_find, variable_name) == 0)
	{
		(*j)++;
		protected_free(&variable_name);
		return (CONTINUE);
	}
	protected_free(&variable_name);
	return (0);
}

static int	assign_new_variable(
	char ***new_envp,
	char **envp,
	size_t i,
	size_t j
)
{
	(*new_envp)[i] = ft_strdup(envp[j]);
	if ((*new_envp)[i] == NULL)
	{
		ft_putendl_fd(MEMERR, STDERR_FILENO);
		ft_free_double_char_pointer(new_envp);
		return (EMALLOC);
	}
	return (0);
}

char	**ft_remove_one(
	char *var_to_find,
	char **envp
)
{
	char	**new_envp;
	int		return_code;
	size_t	str_len;
	size_t	i;
	size_t	j;

	str_len = ft_char_array_len(envp);
	new_envp = malloc((str_len) * sizeof(char *));
	if (!new_envp)
		return (ft_putendl_fd(MEMERR, STDERR_FILENO), NULL);
	i = 0;
	j = 0;
	while (envp[j] != NULL)
	{
		return_code = skip_element(&envp, var_to_find, &j);
		if (return_code == EMALLOC)
			return (ft_free_double_char_pointer(&new_envp), NULL);
		if (return_code == CONTINUE)
			continue ;
		if (assign_new_variable(&new_envp, envp, i, j) == EMALLOC)
			return (NULL);
		i++;
		j++;
	}
	return (new_envp[i] = NULL, new_envp);
}

int	is_variable_name_exists(
	char **envp,
	char *var_to_find
)
{
	size_t	i;
	char	*variable_name;

	i = 0;
	while (envp[i] != NULL)
	{
		variable_name = get_variable_name(envp[i], FALSE);
		if (variable_name == NULL)
			return (ft_putendl_fd(MEMERR, STDERR_FILENO), EMALLOC);
		if (ft_strcmp(variable_name, var_to_find) == 0)
		{
			protected_free(&variable_name);
			return (TRUE);
		}
		protected_free(&variable_name);
		i++;
	}
	return (FALSE);
}

int	ft_unset(
	char ***envp,
	char **argv
)
{
	size_t	i;
	char	**new_envp;
	int		exit_code;

	if (!argv || !*argv || !**argv || !envp || !*envp)
		return (0);
	i = 1;
	exit_code = 0;
	while (argv[i] != NULL)
	{
		exit_code = is_variable_name_exists((*envp), argv[i]);
		if (exit_code == EMALLOC)
			return (EMALLOC);
		if (exit_code == TRUE)
		{
			new_envp = ft_remove_one(argv[i], (*envp));
			if (new_envp == NULL)
				return (EMALLOC);
			exit_code = 0;
			ft_free_double_char_pointer(envp);
			(*envp) = new_envp;
		}
		i++;
	}
	return (exit_code);
}
