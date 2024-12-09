/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:15:50 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/09 12:44:38 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_selected_fractal(int x, int y, t_mlx *mlx)
{
	if (!ft_strncmp(mlx->curr_set_name, SET_MB_JL, ft_strlen(SET_MB_JL)))
	{
		render_mandelbrot_fractal(mlx);
		render_mandelbrot_julia_fractal(mlx, x, y);
	}
	else if (!ft_strncmp(mlx->curr_set_name, SET_MB, ft_strlen(SET_MB)))
	{
		render_mandelbrot_fractal(mlx);
	}
	else if (!ft_strncmp(mlx->curr_set_name, SET_JL, ft_strlen(SET_JL)))
	{
		render_julia_fractal(mlx, mlx->j_re, mlx->j_im);
	}
}
