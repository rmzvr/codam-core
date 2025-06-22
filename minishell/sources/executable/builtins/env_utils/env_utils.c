/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:46:39 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/23 11:12:11 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtins.h"
#include "exec_cmd/exec_cmd.h"
#include "signals/signal_handler.h"

int	proceed_var_val(
	const char *var_val,
	char *variable,
	char **value,
	int plus_sign
)
{
	if (variable[ft_strlen(variable) - 1] != '=')
		return (1);
	(*value) = ft_strdup(var_val + ft_strlen(variable) + plus_sign);
	if ((*value) == NULL)
	{
		ft_putendl_fd(MEMERR, STDERR_FILENO);
		protected_free(&variable);
		return (EMALLOC);
	}
	return (0);
}

int	check_shlvl_validity(
	char *current_shlvl_str,
	char ***envp
)
{
	if (current_shlvl_str == NULL || ft_check_num(current_shlvl_str) == FALSE)
	{
		if (ft_putenv(envp, "SHLVL=1"))
		{
			return (EMALLOC);
		}
	}
	return (0);
}

int	increase_shlvl(
	char ***envp,
	char *pathname
)
{
	char	*current_shlvl_str;
	int		current_shlvl;
	char	*next_shlvl_str;
	char	*shlvl_assignment;
	int		exit_code;

	if (pathname && ft_strcmp(pathname, "./minishell") != 0)
		return (0);
	current_shlvl_str = ft_getenv(*envp, "SHLVL");
	exit_code = check_shlvl_validity(current_shlvl_str, envp);
	if (exit_code == EMALLOC)
		return (EMALLOC);
	current_shlvl = ft_atoi(current_shlvl_str) + 1;
	next_shlvl_str = ft_itoa(current_shlvl);
	if (next_shlvl_str == NULL)
		return (ft_putendl_fd(MEMERR, STDERR_FILENO), EMALLOC);
	shlvl_assignment = ft_strjoin("SHLVL=", next_shlvl_str);
	if (shlvl_assignment == NULL)
		return (protected_free(&next_shlvl_str),
			ft_putendl_fd(MEMERR, STDERR_FILENO), EMALLOC);
	exit_code = ft_putenv(envp, shlvl_assignment);
	protected_free(&next_shlvl_str);
	protected_free(&shlvl_assignment);
	return (exit_code);
}
