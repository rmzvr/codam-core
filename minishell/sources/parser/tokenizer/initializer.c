/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:42:31 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/21 23:39:21 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/state.h"

void	initialize_tokenizer(
	t_state_data *tokenizer
)
{
	tokenizer->i = 0;
	tokenizer->state = S;
	tokenizer->buffer = NULL;
}
