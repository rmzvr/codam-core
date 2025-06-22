/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:19:36 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/22 12:07:38 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# include "exec_cmd/exec_cmd.h"
# include <sys/param.h>

int		run_readline(t_data *data);
t_bool	handle_history(char **input);
char	*allocate_until_new_line(char *input);
int		next_line_chunk(char **line, char **p_input);
int		assign_tree(char *input, t_data *data);
char	*get_prompt_name(t_data *data);

//PROPMT
void	get_home_directory_path(t_data *data);
char	*get_prompt(t_data *data);
char	*get_user_hostname(t_data *data);

#endif