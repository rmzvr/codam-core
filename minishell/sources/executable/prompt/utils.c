/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:25:12 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/22 13:30:01 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt/prompt.h"

int	get_current_path(
	char **current_path,
	t_data *data
)
{
	char	buffer[PATH_MAX];

	(*current_path) = getcwd(buffer, PATH_MAX);
	if ((*current_path) == NULL)
	{
		(*current_path) = ft_getenv(data->envp, "PWD");
		if ((*current_path) == NULL)
		{
			return (FAIL);
		}
	}
	(*current_path) = ft_strdup((*current_path));
	if ((*current_path) == NULL)
	{
		return (EMALLOC);
	}
	return (OK);
}

char	*get_full_path_name_without_home(
	char **full_path_name,
	char **current_path
)
{
	(*full_path_name) = protect_strjoin((*full_path_name), (*current_path));
	if ((*full_path_name) == NULL)
	{
		protected_free(current_path);
		return (print_merror_and_return_null());
	}
	(*full_path_name) = protect_strjoin((*full_path_name), RESET"$ ");
	if ((*full_path_name) == NULL)
	{
		protected_free(current_path);
		return (print_merror_and_return_null());
	}
	protected_free(current_path);
	return ((*full_path_name));
}

char	*free_and_return_full_path_without_home(
	char **full_path_name,
	char **current_path,
	char **home_path
)
{
	if (full_path_name != NULL)
	{
		protected_free(full_path_name);
	}
	if (current_path != NULL)
	{
		protected_free(current_path);
	}
	if (home_path != NULL)
	{
		protected_free(home_path);
	}
	return (get_full_path_name_without_home(full_path_name, current_path));
}

char	*free_and_return_null_failure(
	char **full_path_name,
	char **current_path,
	char **home_path
)
{
	if (full_path_name != NULL)
	{
		protected_free(full_path_name);
	}
	if (current_path != NULL)
	{
		protected_free(current_path);
	}
	if (home_path != NULL)
	{
		protected_free(home_path);
	}
	return (print_merror_and_return_null());
}

char	*append_username_to_path_name(
	t_data *data
)
{
	char	*full_path_name;

	full_path_name = NULL;
	full_path_name = protect_strjoin(full_path_name, BLUE);
	if (full_path_name == NULL)
	{
		return (print_merror_and_return_null());
	}
	full_path_name = protect_strjoin(full_path_name, data->user_hostname);
	if (full_path_name == NULL)
	{
		return (print_merror_and_return_null());
	}
	full_path_name = protect_strjoin(full_path_name, RESET":"GREEN);
	if (full_path_name == NULL)
	{
		return (print_merror_and_return_null());
	}
	return (full_path_name);
}
