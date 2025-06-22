/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:26:20 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/22 22:23:44 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt/prompt.h"

t_bool	check_home_path_format(
	char *home_path,
	size_t home_path_len
)
{
	if (home_path[0] != '/')
	{
		return (FALSE);
	}
	if (home_path[home_path_len - 1] == '/')
	{
		return (FALSE);
	}
	if (home_path_len < 2)
	{
		return (FALSE);
	}
	return (TRUE);
}

char	*get_error_path(
	char *full_path_name
)
{
	full_path_name = protect_strjoin(full_path_name, "."RESET"$ ");
	if (full_path_name == NULL)
	{
		return (print_merror_and_return_null());
	}
	return (full_path_name);
}

int	verify_username(
	char **username,
	t_data *data
)
{
	(*username) = ft_getenv(data->envp, "USER");
	if ((*username) == NULL)
	{
		(*username) = ft_getenv(data->envp, "USER");
	}
	if ((*username) != NULL)
	{
		(*username) = ft_strdup((*username));
		if ((*username) == NULL)
		{
			return (EMALLOC);
		}
	}
	else
	{
		(*username) = ft_strdup("user");
		if ((*username) == NULL)
		{
			return (EMALLOC);
		}
	}
	return (OK);
}
