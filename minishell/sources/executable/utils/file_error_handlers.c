/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_error_handlers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:09:41 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/25 11:56:05 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd/exec_cmd.h"

int	print_ferror_and_return_code(char *message, char *error, int code)
{
	ft_dprintf(STDERR_FILENO, "%s: %s\n", message, error);
	return (code);
}
