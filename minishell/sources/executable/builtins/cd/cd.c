/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:33:03 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/25 11:52:48 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "builtins/cd/cd.h"
#include "builtins/env/env_utils.h"

static char	*get_directory_to_change(
	char **envp,
	char **argv
)
{
	char	*dir_to_change;

	dir_to_change = NULL;
	if (argv[1] == NULL)
	{
		dir_to_change = ft_getenv(envp, "HOME");
		if (dir_to_change == NULL)
			return (ft_dprintf(STDERR_FILENO,
					"minishell: cd: HOME not set\n"), NULL);
	}
	else if (ft_strcmp(argv[1], "-") == 0)
	{
		dir_to_change = ft_getenv(envp, "OLDPWD");
		if (dir_to_change == NULL)
			return (ft_dprintf(STDERR_FILENO,
					"minishell: cd: OLDPWD not set\n"), NULL);
		ft_dprintf(STDIN_FILENO, "%s\n", dir_to_change);
	}
	else
	{
		dir_to_change = *(argv + 1);
	}
	return (dir_to_change);
}

int	ft_cd(
	char ***envp,
	char **argv)
{
	char	*old_dir;
	char	*dir_to_change;
	char	buffer[PATH_MAX];

	(void)envp;
	if (argv == NULL || *argv == NULL || **argv == '\0')
		return (0);
	dir_to_change = get_directory_to_change(*envp, argv);
	if (dir_to_change == NULL)
		return (1);
	if (ft_char_array_len(argv) > 2)
	{
		return (ft_dprintf(STDERR_FILENO,
				"minishell: cd: too many arguments\n"), 1);
	}
	old_dir = getcwd(buffer, PATH_MAX);
	if (chdir(dir_to_change) == -1)
	{
		return (handle_error_file(dir_to_change), 1);
	}
	if (update_oldpwd(envp, old_dir) == EMALLOC)
		return (EMALLOC);
	if (update_pwd(envp) == EMALLOC)
		return (EMALLOC);
	return (0);
}
