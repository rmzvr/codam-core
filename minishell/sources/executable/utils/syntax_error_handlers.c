/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_handlers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:09:41 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/25 11:48:19 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd/exec_cmd.h"

int	print_serror_and_return_code(char *message, int code)
{
	ft_dprintf(STDERR_FILENO,
		"minishell: syntax error near unexpected token `%s'\n", message);
	return (code);
}

char	*print_qerror_and_return_null(void)
{
	ft_putendl_fd("minishell: unclosed quotation mark", STDERR_FILENO);
	return (NULL);
}
