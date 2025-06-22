/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putenv.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:46:39 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/16 16:01:29 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUTENV_H
# define PUTENV_H

# include "env_utils.h"

char	**ft_replace_env_value(char **envp, const char *variable,
			const char *value);

//! ADD CONST CHAR *VALUE
char	**ft_concat_env_value(char **envp, const char *variable,
			char *value);

char	**ft_create_new_env_variable(char **envp,
			const char *variable, const char *value);

#endif