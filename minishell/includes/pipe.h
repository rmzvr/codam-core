/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:46:39 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/18 12:33:18 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

typedef struct s_pipe
{
	int	**pipe_fds;
	int	current_pipe_index;
	int	count_pipes;
}	t_pipe;

#endif