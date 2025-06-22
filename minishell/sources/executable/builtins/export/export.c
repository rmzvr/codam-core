/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:47:19 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/25 11:54:53 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "builtins/env/env_utils.h"

static int	compare_variable_names(
	const char *s1,
	const char *s2
)
{
	int	num1;
	int	num2;

	while (*s1 && *s2 && *s1 != '=' && *s2 != '='
		&& !ft_isdigit(*s1) && !ft_isdigit(*s2))
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	num1 = -1;
	num2 = -1;
	if (ft_isdigit(*s1))
		num1 = ft_atoi(s1);
	if (ft_isdigit(*s2))
		num2 = ft_atoi(s2);
	if (num1 == -1 && num2 == -1)
	{
		if ((unsigned char)*s1 - (unsigned char)*s2 != 0)
			return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	return ((num1 - num2));
}

static int	ft_print_in_export_no_arg_format(
	char **envp
)
{
	size_t	i;
	char	*variable;
	char	*value;
	int		exit_code;

	i = 0;
	while (envp[i] != NULL)
	{
		variable = get_variable_name(envp[i], TRUE);
		if (variable == NULL)
			return (ft_putendl_fd(MEMERR, STDERR_FILENO), EMALLOC);
		exit_code = proceed_var_val(envp[i], variable, &value, 0);
		if (exit_code == EMALLOC)
			return (EMALLOC);
		if (exit_code == 1)
			ft_dprintf(STDOUT_FILENO, "declare -x %s\n", variable);
		else
			ft_dprintf(STDOUT_FILENO, "declare -x %s\"%s\"\n", variable, value);
		protected_free(&variable);
		protected_free(&value);
		i++;
	}
	return (0);
}

static int	ft_export_no_arg(
	char **envp
)
{
	char	**sorted_envp;
	size_t	envp_len;
	size_t	j;
	size_t	i;

	envp_len = ft_char_array_len(envp);
	sorted_envp = copy_char_array(envp, envp_len);
	if (sorted_envp == NULL)
		return (EMALLOC);
	i = 0;
	while (i < envp_len)
	{
		j = 0;
		while (j < envp_len - i - 1)
		{
			if (compare_variable_names(sorted_envp[j], sorted_envp[j + 1]) > 0)
				ft_char_array_swap(&sorted_envp[j], &sorted_envp[j + 1]);
			j++;
		}
		i++;
	}
	if (ft_print_in_export_no_arg_format(sorted_envp) == EMALLOC)
		return (ft_free_double_char_pointer(&sorted_envp), EMALLOC);
	ft_free_double_char_pointer(&sorted_envp);
	return (0);
}

static int	ft_export_handler(
	char *var_val,
	char ***envp
)
{
	char	*variable;

	variable = get_variable_name(var_val, TRUE);
	if (variable == NULL)
	{
		ft_putendl_fd(MEMERR, STDERR_FILENO);
		return (1);
	}
	if (ft_check_identifier_format(variable) == FALSE)
	{
		ft_dprintf(STDERR_FILENO,
			"minishell: export: `%s': not a valid identifier\n",
			var_val);
		return (protected_free(&variable), 1);
	}
	if (ft_putenv(envp, var_val) == EMALLOC)
	{
		return (protected_free(&variable), EMALLOC);
	}
	return (protected_free(&variable), 0);
}

int	ft_export(
	char ***envp,
	char **argv
)
{
	int		exit_status;
	int		exit_code;
	size_t	i;

	i = 1;
	exit_code = 0;
	if (!(*envp) || !(**envp) || argv == NULL)
		return (0);
	if (argv[i] == NULL)
	{
		if (ft_export_no_arg((*envp)) == EMALLOC)
			return (EMALLOC);
		return (0);
	}
	while (argv[i] != NULL)
	{
		exit_status = ft_export_handler(argv[i], envp);
		if (exit_status == 1)
			exit_code = 1;
		if (exit_status == EMALLOC)
			ft_putendl_fd(MEMERR, STDERR_FILENO);
		i++;
	}
	return (exit_code);
}
