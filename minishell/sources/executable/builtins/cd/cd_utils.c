/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:33:03 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/22 15:10:54 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/cd/cd.h"
#include "builtins/env/env_utils.h"

static char	*handle_removed_pwd(
	char ***envp,
	int *pwd_removed
)
{
	char	**new_envp;
	char	*old_pwd;

	(*pwd_removed) = TRUE;
	new_envp = ft_remove_one("OLDPWD", *envp);
	if (new_envp == NULL)
	{
		return (NULL);
	}
	ft_free_double_char_pointer(envp);
	(*envp) = new_envp;
	old_pwd = ft_strjoin("OLDPWD", NULL);
	if (old_pwd == NULL)
	{
		ft_putendl_fd(MEMERR, STDERR_FILENO);
		return (NULL);
	}
	return (old_pwd);
}

static int	check_oldpwd_and_return(
	char *old_pwd,
	char ***envp
)
{
	if (old_pwd == NULL)
		return (ft_putendl_fd(MEMERR, STDERR_FILENO), EMALLOC);
	if (ft_putenv(envp, old_pwd) == EMALLOC)
		return (protected_free(&old_pwd), EMALLOC);
	return (protected_free(&old_pwd), 0);
}

int	update_oldpwd(
	char ***envp,
	char *old_dir
)
{
	char		*pwd;
	char		*old_pwd;
	static int	pwd_removed;

	old_pwd = ft_getenv(*envp, "OLDPWD");
	if (old_pwd == NULL)
		return (0);
	pwd = ft_getenv(*envp, "PWD");
	if (!pwd_removed && pwd == NULL)
	{
		old_pwd = handle_removed_pwd(envp, &pwd_removed);
		if (old_pwd == NULL)
			return (EMALLOC);
	}
	else if (pwd_removed)
	{
		old_pwd = ft_strjoin("OLDPWD=", old_dir);
	}
	else
	{
		pwd_removed = FALSE;
		old_pwd = ft_strjoin("OLDPWD=", pwd);
	}
	return (check_oldpwd_and_return(old_pwd, envp));
}

int	update_pwd(
	char ***envp
)
{
	char	*current_directory;
	char	buffer[PATH_MAX];

	current_directory = ft_getenv(*envp, "PWD");
	if (current_directory == NULL)
	{
		return (0);
	}
	current_directory = getcwd(buffer, PATH_MAX);
	current_directory = ft_strjoin("PWD=", current_directory);
	if (current_directory == NULL)
	{
		ft_putendl_fd(MEMERR, STDERR_FILENO);
		return (EMALLOC);
	}
	if (ft_putenv(envp, current_directory) == EMALLOC)
		return (EMALLOC);
	protected_free(&current_directory);
	return (0);
}
