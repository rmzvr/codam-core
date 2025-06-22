/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:33:03 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/25 11:54:58 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "colors.h"
#include <sys/param.h>

int	ft_pwd(
	char ***envp
)
{
	char	buffer[PATH_MAX];
	char	*current_directory;

	(void)envp;
	current_directory = getcwd(buffer, PATH_MAX);
	if (current_directory == NULL)
	{
		handle_error_file("pwd: error retrieving current directory");
		return (1);
	}
	ft_dprintf(STDOUT_FILENO, "%s\n", current_directory);
	return (0);
}
