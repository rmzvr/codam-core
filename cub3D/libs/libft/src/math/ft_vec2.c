/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 00:00:00 by bamarell      #+#    #+#                 */
/*   Updated: 2024/02/02 00:00:00 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/math/vec2.h"

t_vec2	*ft_vec2(double x, double y)
{
	t_vec2	*vec;

	vec = malloc(sizeof(t_vec2));
	if (vec == NULL)
		return (NULL);
	vec->x = x;
	vec->y = y;
	return (vec);
}

t_vec2	ft_vec2_add(t_vec2 v1, t_vec2 v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	return (v1);
}

t_vec2	ft_vec2_sub(t_vec2 v1, t_vec2 v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	return (v1);
}

t_vec2	ft_vec2_mult(t_vec2 v1, t_vec2 v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	return (v1);
}

t_vec2	ft_vec2_div(t_vec2 v1, t_vec2 v2)
{
	v1.x /= v2.x;
	v1.y /= v2.y;
	return (v1);
}
