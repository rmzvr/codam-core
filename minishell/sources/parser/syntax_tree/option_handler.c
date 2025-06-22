/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:57:38 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 23:40:41 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser/token.h"
#include <unistd.h>

static void	add_option_to_list(t_options **options, t_options *option)
{
	t_options	*curr;

	if (options == NULL || option == NULL)
		return ;
	if (*options == NULL)
	{
		*options = option;
		return ;
	}
	curr = *options;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = option;
}

t_options	*create_option(
	t_token_type token_type,
	char *content,
	t_node_type node_type
)
{
	t_options	*option;

	option = malloc(sizeof(t_options));
	if (option == NULL)
	{
		return (ft_putendl_fd(MEMERR, STDERR_FILENO), NULL);
	}
	option->node_type = node_type;
	option->token_type = token_type;
	option->content = ft_strdup(content);
	if (option->content == NULL)
	{
		free(option);
		return (ft_putendl_fd(MEMERR, STDERR_FILENO), NULL);
	}
	option->next = NULL;
	return (option);
}

int	handle_options(
	t_options **options,
	t_token *token,
	t_options *(*creator)(
		t_token_type token_type,
		char *content,
		t_node_type node_type
	),
	t_node_type node_type
)
{
	t_options	*option;

	option = creator(token->type, token->content, node_type);
	if (option == NULL)
	{
		return (EMALLOC);
	}
	if (*options == NULL)
	{
		*options = option;
	}
	else
	{
		add_option_to_list(options, option);
	}
	return (OK);
}
