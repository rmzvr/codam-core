/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:08:21 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/21 14:10:58 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft/libft.h"
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>

typedef struct sigaction	t_action;
typedef struct s_sig
{
	int	character;
	int	bits;
	int	counter;
}	t_sig;

#endif