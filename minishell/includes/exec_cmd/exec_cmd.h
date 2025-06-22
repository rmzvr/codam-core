/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:46:39 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/22 16:40:23 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_CMD_H
# define EXEC_CMD_H

# include "signals/signal_handler.h"
# include "builtins/env/env_utils.h"
# include "builtins/builtins.h"
# include "utils.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include "readline.h"

int		assign_tree(char *input, t_data *data);
int		handle_parser_exit_code(int res, char **line, t_data *data);
int		redirect(t_options *redirections, t_bool heredoc);
void	free_after_get_executable_pathname(char ***path_values, char **cmd);
int		exec_cmd(t_command *command, t_pipe *pipes, t_data *data);
int		convert_argv_to_pathname(t_data *data, char **pathname);
int		is_pathname_correct(t_data *data, char *pathname);
int		ft_tokens_actionizer(t_data *data);

int		handle_command_arguments(t_options *arguments, t_data *data,
			int *builtin_num, char **pathname);
int		show_executable_error_msg(t_data *data);

void	exec_cmd_in_child(t_command *command, t_pipe *pipes, char *pathname,
			t_data *data);
int		try_exec_in_parent(t_command *command, t_data *data, t_pipe *pipes);

int		wait_for_child(int last_pid);

t_bool	handle_heredoc_signal_exit(t_data *data);

#endif