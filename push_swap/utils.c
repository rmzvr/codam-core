/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:29:41 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/17 17:05:13 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_content(void *content)
{
	free(content);
	content = NULL;
}

void	show_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
