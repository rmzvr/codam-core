/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:09:38 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/25 11:54:01 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/echo/echo.h"

static t_bool	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static t_bool	is_valid_n_option(char *opt)
{
	int	i;

	if (!opt || opt[0] != 'n')
	{
		return (FALSE);
	}
	i = 0;
	while (opt[i] == 'n')
	{
		i++;
	}
	return (opt[i] == '\0' || ft_isspace(opt[i]));
}

static t_bool	is_n_option(char *arg)
{
	if (arg[0] != '-')
	{
		return (FALSE);
	}
	return (is_valid_n_option(arg + 1));
}

int	ft_echo(char **args)
{
	t_bool	no_newline;
	size_t	i;

	no_newline = FALSE;
	i = 1;
	while (args[i] && is_n_option(args[i]))
	{
		no_newline = TRUE;
		i++;
	}
	while (args[i])
	{
		ft_dprintf(STDOUT_FILENO, "%s", args[i]);
		if (args[i + 1])
		{
			ft_dprintf(STDOUT_FILENO, " ");
		}
		i++;
	}
	if (!no_newline)
	{
		ft_dprintf(STDOUT_FILENO, "\n");
	}
	return (0);
}
