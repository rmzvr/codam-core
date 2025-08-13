/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec4.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 00:00:00 by bamarell      #+#    #+#                 */
/*   Updated: 2024/02/02 00:00:00 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math/vec4.h"

t_vec4	ft_vec4(double x, double y, double z, double w)
{
	return ((t_vec4){.x = x, .y = y, .z = z, .w = w});
}

t_vec4	ft_vec4_add(t_vec4 v1, t_vec4 v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	v1.w += v2.w;
	return (v1);
}

t_vec4	ft_vec4_sub(t_vec4 v1, t_vec4 v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	v1.w -= v2.w;
	return (v1);
}

t_vec4	ft_vec4_mult(t_vec4 v1, t_vec4 v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	v1.w *= v2.w;
	return (v1);
}

t_vec4	ft_vec4_div(t_vec4 v1, t_vec4 v2)
{
	v1.x /= v2.x;
	v1.y /= v2.y;
	v1.z /= v2.z;
	v1.w /= v2.w;
	return (v1);
}
