/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:19:02 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/09 17:15:15 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_mlx_window_and_image(t_mlx *mlx, char *title)
{
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		exit(1);
	mlx->win_ptr = mlx_new_window(mlx->ptr, WW, WH, title);
	if (mlx->win_ptr == NULL)
		cleanup(mlx, 1);
	mlx->img.ptr = mlx_new_image(mlx->ptr, WW, WH);
	if (mlx->img.ptr == NULL)
		cleanup(mlx, 1);
	mlx->img.pixels_addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp,
			&mlx->img.ll, &mlx->img.endian);
	if (mlx->img.pixels_addr == NULL)
		cleanup(mlx, 1);
}

static void	init_set(t_mlx *mlx, char *set)
{
	if (ft_strncmp(set, SET_MB_JL, ft_strlen(SET_MB_JL)) == 0)
	{
		mlx->curr_set.range_re = 2.5;
		mlx->curr_set.center_re = -0.75;
		mlx->curr_set.center_im = 0.0;
		mlx->add_set.range_re = 4.0;
		mlx->add_set.center_re = 0.0;
		mlx->add_set.center_im = 0.0;
		center_fractal_on_plane(&mlx->add_set);
	}
	else if (ft_strncmp(set, SET_MB, ft_strlen(SET_MB)) == 0)
	{
		mlx->curr_set.range_re = 2.5;
		mlx->curr_set.center_re = -0.75;
		mlx->curr_set.center_im = 0.0;
	}
	else if (ft_strncmp(set, SET_JL, ft_strlen(SET_JL)) == 0)
	{
		mlx->curr_set.range_re = 4.0;
		mlx->curr_set.center_re = 0.0;
		mlx->curr_set.center_im = 0.0;
	}
	center_fractal_on_plane(&mlx->curr_set);
}

void	init_project(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->img.ptr = NULL;
	init_mlx_window_and_image(mlx, mlx->curr_set_name);
	init_set(mlx, mlx->curr_set_name);
}
