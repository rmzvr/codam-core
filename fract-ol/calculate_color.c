/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:02:04 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/02 12:02:25 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_psychedelic_color(int iteration)
{
	double	t;
	int		color;

	t = (double)iteration / (double)MAX_ITERATIONS;
	color = (int)(t * 16777216);
	return (color);
}

int	calculate_smooth_color(int iteration)
{
	double	t;
	int		red;
	int		green;
	int		blue;
	int		color;

	t = (double)iteration / (double)MAX_ITERATIONS;
	red = 9 * (1 - t) * (t * t * t) * 255;
	green = 15 * ((1 - t) * (1 - t)) * (t * t) * 255;
	blue = 8.5 * ((1 - t) * (1 - t) * (1 - t)) * t * 255;
	color = (red << 16 | green << 8 | blue);
	return (color);
}
