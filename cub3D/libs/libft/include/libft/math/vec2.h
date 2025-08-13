/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec2.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 00:00:00 by bamarell      #+#    #+#                 */
/*   Updated: 2024/02/02 00:00:00 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2_H
# define VEC2_H

struct s_vec2
{
	double	x;
	double	y;
};

typedef struct s_vec2	t_vec2;

t_vec2	*ft_vec2(double x, double y);
t_vec2	ft_vec2_add(t_vec2 v1, t_vec2 v2);
t_vec2	ft_vec2_sub(t_vec2 v1, t_vec2 v2);
t_vec2	ft_vec2_mult(t_vec2 v1, t_vec2 v2);
t_vec2	ft_vec2_div(t_vec2 v1, t_vec2 v2);
#endif
