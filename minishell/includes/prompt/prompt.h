/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:08:41 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/22 15:40:08 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include <sys/param.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "colors.h"

# include "builtins/builtins.h"

int		assign_line(char **line, int fd);
int		assign_username(char **line, int fd, char **username);
int		compare_uid(char **line, long uid);
int		get_file_descriptor(char *str);
void	get_home_directory_path(t_data *data);
char	*get_error_path(char *full_path_name);
int		get_current_path(char **current_path, t_data *data);
char	*append_username_to_path_name(t_data *data);
char	*get_full_path_name_without_home(
			char **full_path_name, char **current_path);
char	*free_and_return_full_path_without_home(
			char **full_path_name, char **current_path, char **home_path);
t_bool	check_home_path_format(char *home_path, size_t home_path_len);
char	*free_and_return_null_failure(
			char **full_path_name, char **current_path, char **home_path);
char	*append_username_to_path_name(t_data *data);
int		verify_username(char **username, t_data *data);

#endif