/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:02:04 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/06 17:18:39 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

int	get_smooth_color(int iteration, int max_iterations)
{
	double	t;
	int		red;
	int		green;
	int		blue;
	int		color;

	t = (double)iteration / (double)max_iterations;
	red = 9 * (1 - t) * (t * t * t) * 255;
	green = 15 * ((1 - t) * (1 - t)) * (t * t) * 255;
	blue = 8.5 * ((1 - t) * (1 - t) * (1 - t)) * t * 255;
	color = (red << 16 | green << 8 | blue);
	return (color);
}

int	get_psychedelic_color(int iteration, int max_iterations)
{
	double	t;
	int		color;

	t = (double)iteration / (double)max_iterations;
	color = (int)(t * 16777216);
	return (color);
}

int	get_selected_color(int i, t_mlx *mlx)
{
	int	color;

	if (ft_strncmp(mlx->palette, "smooth", ft_strlen(mlx->palette)) == 0)
	{
		color = get_smooth_color(i, mlx->max_iterations);
	}
	else
	{
		color = get_psychedelic_color(i, mlx->max_iterations);
	}
	return (color);
}
