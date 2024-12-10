/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:02:04 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/09 17:02:47 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_smooth_color(int iteration)
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

static int	get_psychedelic_color(int iteration)
{
	double	t;
	int		color;

	t = (double)iteration / (double)MAX_ITERATIONS;
	color = (int)(t * 16777216);
	return (color);
}

int	get_selected_color(int i)
{
	int	color;

	if (ft_strncmp(PALETTE, "smooth", ft_strlen(PALETTE)) == 0)
		color = get_smooth_color(i);
	else
		color = get_psychedelic_color(i);
	return (color);
}
