/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:08:41 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 20:53:57 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

# include "libft.h"
# include "ft_boolean.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <unistd.h>

void	handle_signals(t_bool set_default);
void	handle_sigint_signal_no_nl(int signum);

#endif
