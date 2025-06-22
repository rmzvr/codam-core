/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:37:22 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/18 12:42:52 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections/redirections.h"

int	handle_redirect_output(
	t_token_type token_type,
	char *content
)
{
	if (token_type == GREAT)
	{
		if (redirect_output_mode(content, STDOUT_FILENO, O_TRUNC))
		{
			return (1);
		}
	}
	else if (token_type == DGREAT)
	{
		if (redirect_output_mode(content, STDOUT_FILENO, O_APPEND))
		{
			return (1);
		}
	}
	return (0);
}

int	handle_redirect_input(
	t_token_type token_type,
	char **content,
	t_bool heredoc
)
{
	if (token_type == LESS)
	{
		if (redirect_input((*content), STDIN_FILENO))
		{
			return (1);
		}
	}
	else if (heredoc && token_type == DLESS)
	{
		if (redirect_heredoc((*content), STDIN_FILENO))
		{
			protected_free(content);
			(*content) = NULL;
			return (1);
		}
		protected_free(content);
		(*content) = NULL;
	}
	return (0);
}
