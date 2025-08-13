/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 00:00:00 by bamarell      #+#    #+#                 */
/*   Updated: 2024/02/02 00:00:00 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_vec3	t_vec3;

t_vec3	ft_vec3(double x, double y, double z);
t_vec3	ft_vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3	ft_vec3_sub(t_vec3 v1, t_vec3 v2);
t_vec3	ft_vec3_mult(t_vec3 v1, t_vec3 v2);
t_vec3	ft_vec3_div(t_vec3 v1, t_vec3 v2);
#endif
