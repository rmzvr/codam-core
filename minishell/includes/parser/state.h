/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:55:26 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/23 10:51:41 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include <stddef.h>

typedef enum e_current_token
{
	CURRENT_TOKEN,
	NEXT_TOKEN,
}	t_current_token;

typedef enum e_state
{
	S,
	STR,
	T_STR,
	DS,
	T_ES,
	EV,
	T_EV,
	SQ,
	T_SQ,
	DQ,
	T_DQ,
	LS,
	T_LS,
	GS,
	T_GS,
	DLS,
	T_DLS,
	DGS,
	T_DGS,
	P,
	T_P,
	DL,
	T_DL,
	ERROR
}	t_state;

typedef struct s_state_data
{
	size_t	i;
	t_state	state;
	char	*buffer;
}	t_state_data;

#endif