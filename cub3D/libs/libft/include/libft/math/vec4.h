/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec4.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 00:00:00 by bamarell      #+#    #+#                 */
/*   Updated: 2024/02/02 00:00:00 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC4_H
# define VEC4_H

struct s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
};

typedef struct s_vec4	t_vec4;

t_vec4	ft_vec4(double x, double y, double z, double w);
t_vec4	ft_vec4_add(t_vec4 v1, t_vec4 v2);
t_vec4	ft_vec4_sub(t_vec4 v1, t_vec4 v2);
t_vec4	ft_vec4_mult(t_vec4 v1, t_vec4 v2);
t_vec4	ft_vec4_div(t_vec4 v1, t_vec4 v2);
#endif
