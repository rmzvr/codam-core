/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:03:24 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/25 11:54:04 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/env/env_utils.h"

static void	ft_print_env_variables(
	char **argv
)
{
	size_t	i;

	i = 0;
	while (argv[i] != NULL && ft_strchr(argv[i], '=') != NULL)
	{
		ft_dprintf(STDOUT_FILENO, "%s\n", argv[i]);
		i++;
	}
}

int	ft_env(char **envp)
{
	ft_print_env_variables(envp);
	return (0);
}
