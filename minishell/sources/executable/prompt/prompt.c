/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:53:58 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/24 20:33:22 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt/prompt.h"

static char	*get_home_path(
	char **full_path_name,
	char **current_path,
	t_data *data
)
{
	char	*home_path;

	home_path = ft_strdup(data->home);
	if (home_path == NULL)
	{
		protected_free(full_path_name);
		protected_free(current_path);
		return (print_merror_and_return_null());
	}
	return (home_path);
}

static char	*get_full_path_name_with_home(
	char **full_path_name,
	char **current_path,
	char **home_path
)
{
	size_t	home_path_len;

	home_path_len = ft_strlen((*home_path));
	(*full_path_name) = protect_strjoin((*full_path_name), "~");
	if ((*full_path_name) == NULL)
		return (free_and_return_null_failure(NULL, current_path, home_path));
	(*full_path_name) = protect_strjoin((*full_path_name),
			(*current_path) + home_path_len);
	if ((*full_path_name) == NULL)
		return (free_and_return_null_failure(NULL, current_path, home_path));
	(*full_path_name) = protect_strjoin((*full_path_name), RESET"$ ");
	if ((*full_path_name) == NULL)
		return (free_and_return_null_failure(NULL, current_path, home_path));
	protected_free(current_path);
	protected_free(home_path);
	return ((*full_path_name));
}

static char	*replace_home_path(
	char **full_path_name,
	char **current_path,
	char **home_path
)
{
	size_t	home_path_len;

	if (home_path != NULL && (*home_path) != NULL)
	{
		home_path_len = ft_strlen((*home_path));
		if (home_path_len == 0)
			return (free_and_return_full_path_without_home(
					full_path_name, current_path, home_path));
		if (check_home_path_format((*home_path), home_path_len) == FALSE)
			return (free_and_return_full_path_without_home(
					NULL, NULL, home_path));
		if (ft_strnstr((*current_path), (*home_path), home_path_len) != NULL)
		{
			return (get_full_path_name_with_home(
					full_path_name, current_path, home_path));
		}
		protected_free(home_path);
	}
	return (get_full_path_name_without_home(full_path_name, current_path));
}

char	*get_prompt_name(t_data *data)
{
	char	*full_path_name;
	char	*current_path;
	int		res_code;
	char	*home_path;

	home_path = NULL;
	full_path_name = append_username_to_path_name(data);
	if (full_path_name == NULL)
		return (NULL);
	current_path = NULL;
	res_code = get_current_path(&current_path, data);
	if (res_code == EMALLOC)
		return (free_and_return_null_failure(&full_path_name, NULL, NULL));
	if (res_code == FAIL)
	{
		protected_free(&current_path);
		return (get_error_path(full_path_name));
	}
	if (data->home != NULL)
	{
		home_path = get_home_path(&full_path_name, &current_path, data);
		if (home_path == NULL)
			return (NULL);
	}
	return (replace_home_path(&full_path_name, &current_path, &home_path));
}

char	*get_prompt(t_data *data)
{
	char	*prompt;

	prompt = get_prompt_name(data);
	if (prompt == NULL)
	{
		data->last_exit_code = 2;
		ft_exit(data, FALSE);
	}
	return (prompt);
}
