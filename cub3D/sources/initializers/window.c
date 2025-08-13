/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:12:42 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/22 17:42:57 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"
#include "utils.h"

t_bool	initialize_window_and_image(
	t_mlx *mlx
)
{
	mlx->ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->img.ptr = NULL;
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		return (FALSE);
	mlx->win_ptr = mlx_new_window(
			mlx->ptr, WINDOW_WIDTH, WINDOW_HEIGHT, PROGRAM_NAME);
	if (mlx->win_ptr == NULL)
		return (FALSE);
	mlx->img.ptr = mlx_new_image(mlx->ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (mlx->img.ptr == NULL)
		return (FALSE);
	mlx->img.pixels_addr = mlx_get_data_addr(
			mlx->img.ptr,
			&mlx->img.bytes_per_pixel,
			&mlx->img.line_length,
			&mlx->img.endian
			);
	if (mlx->img.pixels_addr == NULL)
		return (FALSE);
	mlx_mouse_move(mlx->ptr, mlx->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	return (TRUE);
}
