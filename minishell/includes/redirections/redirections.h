/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:46:39 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/18 15:20:59 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

# include "utils.h"
# include <fcntl.h>
# include <unistd.h>

int	handle_redirect_output(t_token_type token_type, char *content);
int	handle_redirect_input(t_token_type token_type,
		char **content, t_bool heredoc);
int	redirect_input(const char *filename, int fd2);
int	redirect_heredoc(const char *filename, int fd2);
int	redirect_output_mode(const char *filename, int fd2, int mode);

#endif