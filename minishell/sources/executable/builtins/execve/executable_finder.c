/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executable_finder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:41:38 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/25 11:48:46 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd/exec_cmd.h"

static char	*prepend_slash_to_cmd(
	char *cmd_name
)
{
	char	*cmd;

	cmd = malloc(ft_strlen(cmd_name) + 2 * sizeof(char));
	if (!cmd)
		return (NULL);
	cmd[0] = '/';
	ft_strcpy(cmd + 1, cmd_name);
	return (cmd);
}

static char	*resolve_executable_path(
	char **path_values,
	char *cmd
)
{
	char	*pathname;
	size_t	i;

	i = 0;
	pathname = ft_strjoin(path_values[i], cmd);
	if (pathname == NULL)
	{
		return (NULL);
	}
	i++;
	while (path_values[i] && access(pathname, X_OK) != 0)
	{
		protected_free(&pathname);
		pathname = ft_strjoin(path_values[i], cmd);
		if (pathname == NULL)
		{
			return (NULL);
		}
		i++;
	}
	return (pathname);
}

static char	*get_executable_pathname(
	char **envp,
	char *name
)
{
	char	**path_values;
	char	*path_value;
	char	*pathname;
	char	*cmd;

	path_value = ft_getenv(envp, "PATH");
	if (path_value == NULL || *path_value == '\0')
		return (ft_strdup(name));
	path_values = ft_split(path_value, ':');
	if (path_values == NULL)
		return (NULL);
	cmd = prepend_slash_to_cmd(name);
	if (cmd == NULL)
	{
		ft_free_double_char_pointer(&path_values);
		return (NULL);
	}
	pathname = resolve_executable_path(path_values, cmd);
	if (pathname == NULL)
	{
		free_after_get_executable_pathname(&path_values, &cmd);
		return (NULL);
	}
	free_after_get_executable_pathname(&path_values, &cmd);
	return (pathname);
}

static int	handle_file_or_directory(
	t_data *data,
	char **pathname
)
{
	struct stat	file_stat;
	int			res;

	res = 0;
	if (stat(data->argv[0], &file_stat) != -1)
	{
		if (S_ISDIR(file_stat.st_mode))
			return (ft_dprintf(STDERR_FILENO,
					"minishell: %s: Is a directory\n", data->argv[0]),
				ft_free_double_char_pointer(&data->argv), 126);
		if (access(data->argv[0], X_OK) == 0)
		{
			*pathname = ft_strdup(data->argv[0]);
			if (*pathname == NULL)
			{
				ft_putendl_fd(MEMERR, STDERR_FILENO);
				ft_free_double_char_pointer(&data->argv);
				return (EMALLOC);
			}
			return (0);
		}
	}
	res = show_executable_error_msg(data);
	ft_free_double_char_pointer(&data->argv);
	return (res);
}

int	convert_argv_to_pathname(
	t_data *data,
	char **pathname
)
{
	if (ft_strchr(data->argv[0], '/') != NULL
		|| data->argv[0][0] == '.')
	{
		return (handle_file_or_directory(data, pathname));
	}
	*pathname = get_executable_pathname(data->envp, data->argv[0]);
	if (*pathname == NULL)
	{
		ft_free_double_char_pointer(&data->argv);
		ft_putendl_fd(MEMERR, STDERR_FILENO);
		return (EMALLOC);
	}
	return (0);
}
