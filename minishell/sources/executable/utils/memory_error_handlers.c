/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_error_handlers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:09:41 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/21 19:43:39 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd/exec_cmd.h"

int	free_and_return_code(char **value_to_free, int code)
{
	protected_free(value_to_free);
	return (code);
}

int	print_merror_and_return_code(int code)
{
	ft_putendl_fd(MEMERR, STDERR_FILENO);
	return (code);
}

char	*print_merror_and_return_null(void)
{
	ft_putendl_fd(MEMERR, STDERR_FILENO);
	return (NULL);
}

char	*free_and_return_value(char **value_to_free, char *value_to_return)
{
	protected_free(value_to_free);
	return (value_to_return);
}

int	free_tokens_and_return_code(t_token **tokens, int code)
{
	free_tokens(tokens);
	return (code);
}
