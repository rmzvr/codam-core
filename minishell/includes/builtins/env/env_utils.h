/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:00:53 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/18 11:13:09 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

# include "utils.h"

int		ft_env(char **envp);
char	*ft_getenv(char **envp, const char *variable_name);
int		ft_putenv(char ***env_root, char *var_val);
int		increase_shlvl(char ***envp, char *pathname);
int		proceed_var_val(const char *var_val,
			char *variable, char **value, int plus_sign);
char	**ft_remove_one(char *variable_name, char **envp);

#endif