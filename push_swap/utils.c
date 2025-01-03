/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:29:41 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/02 14:32:09 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pr(void *c)
{
	ft_printf("stack: %d\n", *(int *)c);
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
