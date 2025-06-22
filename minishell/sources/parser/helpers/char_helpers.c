/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:06:20 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 20:56:46 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_null_terminator(char c)
{
	if (c == '\0')
		return (1);
	return (0);
}

int	is_valid_char(char c)
{
	if (ft_isalpha(c) || c == '_')
		return (1);
	return (0);
}

int	is_metacharacter(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == '$' || c == '\'' || c == '"')
		return (1);
	return (0);
}

int	is_delimiter(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	is_redirection(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}
