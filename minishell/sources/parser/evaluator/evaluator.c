/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 21:27:48 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 23:38:54 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/heredoc.h"
#include "parser/evaluator.h"

int	evaluate_tokens(t_data *data)
{
	t_token	*tokens;
	int		return_code;

	return_code = OK;
	tokens = data->tokens;
	return_code = evaluate_heredoc_delimiter(&tokens);
	if (return_code == EMALLOC || return_code == FAIL)
		return (return_code);
	return_code = concatenate_tokens(data);
	if (return_code == EMALLOC || return_code == FAIL)
		return (return_code);
	return_code = evaluate_redirection_tokens(tokens);
	if (return_code == EMALLOC || return_code == FAIL)
		return (return_code);
	return_code = validate_syntax(tokens);
	if (return_code == EMALLOC || return_code == FAIL)
		return (return_code);
	return_code = execute_heredoc(data);
	if (return_code == EMALLOC || return_code == FAIL)
		return (return_code);
	return (OK);
}
