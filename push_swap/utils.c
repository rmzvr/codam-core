/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:29:41 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/08 19:52:10 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pr(void *c)
{
	ft_printf("%d ", *(int *)c);
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
