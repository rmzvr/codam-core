/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:46:39 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/22 16:44:23 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "data.h"
# include "pipe.h"
# include "env/env_utils.h"

typedef enum e_builtin
{
	NO_BUILTIN,
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT
}	t_builtin;

int	ft_echo(char **lines);
int	ft_cd(char ***envp, char **argv);
int	ft_pwd(char ***envp);
int	ft_export(char ***envp, char **var_vals);
int	ft_unset(char ***envp, char **argv);
int	ft_env(char **envp);
int	ft_exit(t_data *data, t_bool display);

int	ft_handle_builtin(t_data *data, t_pipe *pipe, t_bool print_exit);
int	ft_get_builtin_num(char *cmd);

#endif