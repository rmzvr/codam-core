/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:03:54 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/27 14:17:09 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	clear_image(t_game *game)
{
	memset(
		game->mlx.img.pixels_addr,
		0,
		WINDOW_WIDTH * WINDOW_HEIGHT * (game->mlx.img.bytes_per_pixel / 8)
		);
}

void	cleanup(t_mlx *mlx, unsigned int with_exit)
{
	if (mlx->img.ptr != NULL)
		mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	if (mlx->win_ptr != NULL)
		mlx_destroy_window(mlx->ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	if (with_exit > 0)
		exit(1);
}
