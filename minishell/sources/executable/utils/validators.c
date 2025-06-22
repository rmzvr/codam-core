/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:09:22 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/17 22:00:41 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd/exec_cmd.h"

t_bool	ft_check_identifier_format(char *var_val)
{
	size_t	i;

	if (!ft_isalpha(var_val[0]) && var_val[0] != '_')
		return (FALSE);
	i = 1;
	while (var_val[i] != '\0')
	{
		if (ft_isalnum(var_val[i]) == FALSE && var_val[i] != '_')
		{
			if ((var_val[i] == '+' && var_val[i + 1] == '=')
				|| (var_val[i] == '=' && var_val[i + 1] == '\0'))
				return (TRUE);
			else
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

t_bool	ft_check_num(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
