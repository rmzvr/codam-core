/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:29:41 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/15 11:57:11 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pr(void *c)
{
	t_content	*content;

	content = c;
	ft_printf("%d ", content->value);
}

void	dl(void *c)
{
	free(c);
	c = NULL;
}

void	show_error_and_exit()
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
