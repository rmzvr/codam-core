/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_path_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:52:13 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/24 20:33:25 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt/prompt.h"

void	get_home_directory_path(
	t_data *data
)
{
	char	*home;

	if (data->home != NULL)
		protected_free(&data->home);
	home = ft_getenv(data->envp, "HOME");
	if (home != NULL)
	{
		data->home = ft_strdup(home);
		if (data->home == NULL)
		{
			ft_putendl_fd(MEMERR, STDERR_FILENO);
			data->last_exit_code = 2;
			ft_exit(data, FALSE);
		}
	}
	else
	{
		data->home = NULL;
	}
}
