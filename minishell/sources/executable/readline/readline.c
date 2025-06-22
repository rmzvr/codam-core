/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:36:28 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/25 13:39:37 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

extern sig_atomic_t	g_is_interactive_mode_switch;

static int	proceed_current_line(
	char **line,
	t_data *data
)
{
	int	res;

	if (handle_history(line) == FALSE)
		return (0);
	res = assign_tree((*line), data);
	if (handle_heredoc_signal_exit(data))
		return (0);
	if (handle_parser_exit_code(res, line, data))
		return (res);
	protected_free(line);
	res = ft_tokens_actionizer(data);
	data->last_exit_code = res;
	if (res == EMALLOC)
	{
		data->last_exit_code = 2;
		data->leaks = TRUE;
	}
	handle_signals(FALSE);
	cleanup_tree(&data->tree);
	data->tree.type.command = NULL;
	return (data->last_exit_code);
}

static int	iterate_all_input_lines(
	char *input,
	t_data *data
)
{
	char	*line;
	char	*p_input;

	p_input = input;
	line = allocate_until_new_line(p_input);
	if (line == NULL)
		return (EMALLOC);
	while (p_input != NULL && *p_input != '\0')
	{
		data->count_lines++;
		proceed_current_line(&line, data);
		if (data->leaks == TRUE)
			return (EMALLOC);
		next_line_chunk(&line, &p_input);
		if (data->leaks == TRUE)
			return (EMALLOC);
	}
	protected_free(&line);
	return (0);
}

static void	handle_interactive_mode_signals(
	t_data *data
)
{
	handle_signals(FALSE);
	if (g_is_interactive_mode_switch == SIGINT)
	{
		data->last_exit_code = 130;
	}
	kill(getpid(), SIGUSR1);
}

void	process_readline_input(char **input, t_data *data)
{
	if (**input == '\0')
	{
		data->count_lines++;
	}
	else
	{
		if (iterate_all_input_lines((*input), data) == EMALLOC)
		{
			protected_free(input);
			ft_exit(data, FALSE);
		}
		kill(getpid(), SIGUSR2);
	}
	protected_free(input);
}

int	run_readline(
	t_data *data
)
{
	char	*input;
	char	*prompt;
	char	*user_hostname;

	input = NULL;
	user_hostname = get_user_hostname(data);
	data->user_hostname = user_hostname;
	handle_signals(FALSE);
	while (1)
	{
		get_home_directory_path(data);
		prompt = get_prompt(data);
		input = readline(prompt);
		handle_interactive_mode_signals(data);
		if (input == NULL)
		{
			protected_free(&prompt);
			ft_exit(data, TRUE);
		}
		protected_free(&prompt);
		process_readline_input(&input, data);
	}
	protected_free(&data->user_hostname);
	return (0);
}
