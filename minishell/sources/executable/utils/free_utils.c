/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:10:02 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/15 22:25:04 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd/exec_cmd.h"

void	protected_free(char **string)
{
	if ((*string))
	{
		free((*string));
		(*string) = NULL;
	}
}

void	ft_free_double_char_pointer(char ***argv)
{
	size_t	i;

	i = 0;
	if (!argv || !(*argv))
		return ;
	while ((*argv)[i] != NULL)
	{
		protected_free(&(*argv)[i]);
		i++;
	}
	free((*argv));
	(*argv) = NULL;
}

void	ft_free_double_int_pointer(int ***argv, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free((*argv)[i]);
		(*argv)[i] = NULL;
		i++;
	}
	free((*argv));
	(*argv) = NULL;
}
