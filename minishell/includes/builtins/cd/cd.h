/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:46:39 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/21 23:55:14 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

# include "builtins/env/env_utils.h"
# include <sys/param.h>
# include <errno.h>
# include <string.h>

int	update_oldpwd(char ***envp, char *old_dir);
int	update_pwd(char ***envp);

#endif