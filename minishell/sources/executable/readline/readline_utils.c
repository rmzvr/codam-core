/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:29:15 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/25 13:36:12 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd/exec_cmd.h"

extern sig_atomic_t	g_is_interactive_mode_switch;

t_bool	handle_history(
	char **input
)
{
	if ((*input) == NULL || **input == '\0')
	{
		return (FALSE);
	}
	(*input) = ft_stringtrim((*input), " \t\n");
	if ((*input) == NULL)
	{
		return (FALSE);
	}
	if ((*input) != NULL && (*input)[0] == '\0')
	{
		return (FALSE);
	}
	add_history(*input);
	return (TRUE);
}

char	*allocate_until_new_line(
	char *input
)
{
	char	*p_new_line;
	char	*res;

	p_new_line = ft_strchr(input, '\n');
	if (p_new_line == NULL)
	{
		res = ft_strdup(input);
	}
	else
	{
		res = ft_strndup(input, p_new_line - input);
	}
	if (res == NULL)
	{
		ft_putendl_fd(MEMERR, STDERR_FILENO);
		return (NULL);
	}
	return (res);
}

int	next_line_chunk(
	char **line,
	char **p_input
)
{
	protected_free(line);
	(*p_input) = ft_strchr((*p_input), '\n');
	if ((*p_input) != NULL)
	{
		(*p_input) += 1;
		(*line) = allocate_until_new_line((*p_input));
		if ((*line) == NULL)
			return (EMALLOC);
	}
	return (0);
}

t_bool	handle_heredoc_signal_exit(
	t_data *data
)
{
	if (g_is_interactive_mode_switch == SIGINT
		|| g_is_interactive_mode_switch == SIGUSR2)
	{
		if (g_is_interactive_mode_switch == SIGINT)
		{
			data->last_exit_code = 130;
		}
		else
			data->last_exit_code = 0;
		if (data->tree.type.command != NULL)
			cleanup_tree(&data->tree);
		kill(getpid(), SIGUSR1);
		return (TRUE);
	}
	return (FALSE);
}
