/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_evaluator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:56:22 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/23 11:21:55 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser/heredoc.h"
#include "parser/evaluator.h"

int	evaluate_heredoc_delimiter(t_token **tokens)
{
	t_token	*token;
	int		return_code;

	token = *tokens;
	token = find_heredoc_token(token);
	while (token != NULL)
	{
		token = token->next;
		if (is_delimiter_token(token))
			token = token->next;
		return_code = concatenate_tokens_to_heredoc_delimiter(&token);
		if (return_code == EMALLOC || return_code == FAIL)
			return (return_code);
		token = find_heredoc_token(token);
	}
	return (OK);
}
