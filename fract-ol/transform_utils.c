/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:35:26 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/09 17:15:15 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale_n(double num, double min_new, double max_new, double max)
{
	return ((max_new - min_new) * num / max + min_new);
}

void	center_fractal_on_plane(t_set *set)
{
	double	scale;
	double	aspect_ratio;
	double	range_im;

	scale = 2.0;
	aspect_ratio = (double)WW / (double)WH;
	range_im = set->range_re / aspect_ratio;
	set->re_min = set->center_re - set->range_re / scale;
	set->re_max = set->center_re + set->range_re / scale;
	set->im_min = set->center_im - range_im / scale;
	set->im_max = set->center_im + range_im / scale;
}

void	scale_view(int x, int y, double scale_factor, t_mlx *mlx)
{
	double	x_ratio;
	double	y_ratio;
	double	d_re;
	double	d_im;

	x_ratio = x / (double)WW;
	y_ratio = y / (double)WH;
	d_re = mlx->curr_set.re_max - mlx->curr_set.re_min;
	d_im = mlx->curr_set.im_max - mlx->curr_set.im_min;
	mlx->curr_set.re_min -= ((scale_factor * d_re - d_re) * x_ratio);
	mlx->curr_set.re_max += ((scale_factor * d_re - d_re) * (1 - x_ratio));
	mlx->curr_set.im_min -= ((scale_factor * d_im - d_im) * (y_ratio));
	mlx->curr_set.im_max += ((scale_factor * d_im - d_im) * (1 - y_ratio));
}

void	shift_horizontal_view(t_set *set, char *direction)
{
	double	shift_factor;
	double	visible_width;
	double	adjusted_x_shift;

	shift_factor = 0.05;
	visible_width = set->re_max - set->re_min;
	adjusted_x_shift = shift_factor * visible_width;
	if (!ft_strncmp(direction, "left", ft_strlen("left")))
	{
		set->re_min -= adjusted_x_shift;
		set->re_max -= adjusted_x_shift;
	}
	else if (!ft_strncmp(direction, "right", ft_strlen("right")))
	{
		set->re_min += adjusted_x_shift;
		set->re_max += adjusted_x_shift;
	}
}

void	shift_vertical_view(t_set *set, char *direction)
{
	double	shift_factor;
	double	visible_height;
	double	adjusted_y_shift;

	shift_factor = 0.05;
	visible_height = set->im_max - set->im_min;
	adjusted_y_shift = shift_factor * visible_height;
	if (!ft_strncmp(direction, "up", ft_strlen("up")))
	{
		set->im_min -= adjusted_y_shift;
		set->im_max -= adjusted_y_shift;
	}
	else if (!ft_strncmp(direction, "down", ft_strlen("down")))
	{
		set->im_min += adjusted_y_shift;
		set->im_max += adjusted_y_shift;
	}
}
