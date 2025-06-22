/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_executor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:16:30 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/24 20:28:08 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/heredoc.h"
#include "signals/signal_handler.h"

static char	*get_heredoc_delimiter(
	t_token *token
)
{
	char	*buffer;

	buffer = NULL;
	while (token != NULL)
	{
		if (token->type == EXPANDABLE_HEREDOC
			|| token->type == NON_EXPANDABLE_HEREDOC)
		{
			buffer = ft_strdup(token->content);
			if (buffer == NULL)
				return (print_merror_and_return_null());
			return (buffer);
		}
		token = token->next;
	}
	return (NULL);
}

static int	heredoc_open_fd(
	t_executor_data *executor_data
)
{
	if (create_temp_heredoc_file(&executor_data->write_fd,
			&executor_data->filepath) == EMALLOC)
	{
		return (free_heredoc_data(executor_data, TRUE));
	}
	if (file_manipulation(executor_data) == FAIL)
	{
		return (free_heredoc_data(executor_data, TRUE));
	}
	free_heredoc_data(executor_data, FALSE);
	executor_data->token->content = ft_itoa(executor_data->read_fd);
	if (executor_data->token->content == NULL)
	{
		return (print_merror_and_return_code(EMALLOC));
	}
	return (OK);
}

static int	handle_heredoc_input(
	t_executor_data *executor_data,
	t_data *data
)
{
	int	return_code;

	executor_data->buffer = ft_strdup("");
	if (executor_data->buffer == NULL)
		return (free_heredoc_data(executor_data, TRUE));
	signal(SIGINT, signal_handler_heredoc);
	while (1)
	{
		executor_data->input = readline("heredoc> ");
		if (heredoc_handle_signal(executor_data) == FAIL)
			return (FAIL);
		data->count_lines++;
		return_code = update_buffer(executor_data, data);
		if (return_code == EMALLOC)
			return (free_heredoc_data(executor_data, FALSE), EMALLOC);
		if (return_code == CONTINUE)
			continue ;
		if (return_code == BREAK)
			break ;
	}
	if (heredoc_open_fd(executor_data) == EMALLOC)
		return (EMALLOC);
	executor_data->token->type = DLESS;
	return (OK);
}

int	execute_heredoc(
	t_data *data
)
{
	t_executor_data	executor_data;
	int				result;

	initialize_executor_data(&executor_data, data);
	if (find_heredoc_token(executor_data.token) == NULL)
		return (OK);
	executor_data.delimiter = get_heredoc_delimiter(executor_data.token);
	if (executor_data.delimiter == NULL)
		return (print_merror_and_return_code(EMALLOC));
	while (executor_data.delimiter != NULL)
	{
		if (executor_data.token->type == EXPANDABLE_HEREDOC
			|| executor_data.token->type == NON_EXPANDABLE_HEREDOC)
		{
			result = handle_heredoc_input(&executor_data, data);
			if (result == EMALLOC || result == FAIL)
				return (result);
		}
		executor_data.token = executor_data.token->next;
		protected_free(&executor_data.delimiter);
		executor_data.delimiter = get_heredoc_delimiter(executor_data.token);
	}
	protected_free(&executor_data.buffer);
	protected_free(&executor_data.delimiter);
	return (OK);
}
