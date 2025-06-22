/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:58:01 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 23:39:50 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include <fcntl.h>

# include "data.h"
# include "utils.h"

typedef struct s_temp_file_data
{
	mode_t	modes;
	int		flags;
	char	*path;
	char	*prefix;
	char	*filename;
	char	*fullpath;
	int		int_index;
	char	*char_index;
}	t_temp_file_data;

typedef struct s_executor_data
{
	char	*input;
	t_token	*token;
	char	*buffer;
	int		read_fd;
	int		write_fd;
	char	*filepath;
	ssize_t	bytes_read;
	char	*delimiter;
	ssize_t	starting_line;
}	t_executor_data;

int		is_contain_dollar_symbol(char *input);
char	*handle_expansion(char *input, t_data *data);

int		execute_heredoc(t_data *data);
void	signal_handler_heredoc(int sig);
t_token	*find_heredoc_token(t_token *token);
int		evaluate_heredoc_delimiter(t_token **tokens);
int		file_manipulation(t_executor_data *executor_data);
void	show_heredoc_warning(size_t line, char *delimiter);
int		create_temp_heredoc_file(int *fd, char **filepath);
int		heredoc_handle_signal(t_executor_data *executor_data);
int		concatenate_tokens_to_heredoc_delimiter(t_token **tokens);
int		update_buffer(t_executor_data *executor_data, t_data *data);
void	initialize_executor_data(t_executor_data *executor_data, t_data *data);
int		free_heredoc_data(
			t_executor_data *executor_data, t_bool print_error_msg);

#endif