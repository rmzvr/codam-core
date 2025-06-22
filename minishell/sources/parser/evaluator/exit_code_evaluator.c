/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code_evaluator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:59:26 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/21 23:40:41 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/token.h"
#include "utils.h"
#include "parser/evaluator.h"

int	process_exit_code(
	t_token *token,
	int is_next,
	t_data *data
)
{
	char	*buffer;

	if (is_next)
		buffer = get_exit_code(&token->next, data);
	else
		buffer = get_exit_code(&token, data);
	if (buffer == NULL)
		return (print_merror_and_return_code(EMALLOC));
	if (!is_next)
		protected_free(&token->content);
	token->content = protect_strjoin(token->content, buffer);
	if (token->content == NULL)
	{
		protected_free(&buffer);
		return (print_merror_and_return_code(EMALLOC));
	}
	token->type = STRING;
	protected_free(&buffer);
	return (OK);
}
