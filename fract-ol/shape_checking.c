/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:48:21 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/08 14:03:43 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_within_cardioid(double re, double im)
{
	double	sq_im;
	double	c_center;
	double	c_distance;

	sq_im = im * im;
	c_center = 0.25;
	c_distance = (re - c_center) * (re - c_center) + sq_im;
	if (c_distance * (c_distance + (re - c_center)) < c_center * sq_im)
		return (1);
	return (0);
}

static int	is_within_bulb(double re, double im)
{
	double	sq_re;
	double	sq_im;
	double	bulb_radius_squared;

	sq_re = re * re;
	sq_im = im * im;
	bulb_radius_squared = 0.0625;
	if (sq_re + (2.0 * re) + 1.0 + sq_im < bulb_radius_squared)
		return (1);
	return (0);
}

int	is_within_shape(int x, int y, t_mlx *mlx)
{
	if (is_within_bulb(mlx->curr_set.c.re, mlx->curr_set.c.im)
		|| is_within_cardioid(mlx->curr_set.c.re, mlx->curr_set.c.im))
	{
		pixel_put(&mlx->img, x, y, COLOR_BLACK);
		return (1);
	}
	return (0);
}
