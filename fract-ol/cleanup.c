/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:00:21 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/02 12:00:45 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cleanup(t_mlx *mlx)
{
	if (mlx->img.ptr != NULL)
		mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	if (mlx->win_ptr != NULL)
		mlx_destroy_window(mlx->ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	exit(1);
}
