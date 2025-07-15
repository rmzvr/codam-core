/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:00:27 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/15 14:46:05 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	init_mlx_window_and_image(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		exit(1);
	mlx->win_ptr = mlx_new_window(
			mlx->ptr, WINDOW_WIDTH, WINDOW_HEIGHT, PROGRAM_NAME);
	if (mlx->win_ptr == NULL)
		cleanup(mlx, 1);
	mlx->img.ptr = mlx_new_image(mlx->ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (mlx->img.ptr == NULL)
		cleanup(mlx, 1);
	mlx->img.pixels_addr = mlx_get_data_addr(
			mlx->img.ptr,
			&mlx->img.bytes_per_pixel,
			&mlx->img.line_length,
			&mlx->img.endian
			);
	if (mlx->img.pixels_addr == NULL)
		cleanup(mlx, 1);
}

void	init_project(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->img.ptr = NULL;
	init_mlx_window_and_image(mlx);
}

void	init_texture_image(char *path, t_texture *texture, t_game *game)
{
	texture->xpm.path = path;
	texture->img.ptr = mlx_xpm_file_to_image(
			game->mlx.ptr,
			texture->xpm.path,
			&texture->xpm.width,
			&texture->xpm.height
			);
	if (texture->img.ptr == NULL)
	{
		perror("Image load failed");
	}
	texture->img.pixels_addr = mlx_get_data_addr(
			texture->img.ptr,
			&texture->img.bytes_per_pixel,
			&texture->img.line_length,
			&texture->img.endian
			);
}

void	init_game(t_game *game)
{
	game->position_x = 0.0;
	game->position_y = 0.0;
	game->direction_x = 0.0;
	game->direction_y = 0.0;
	game->move_forward = FALSE;
	game->move_backward = FALSE;
	game->move_left = FALSE;
	game->move_right = FALSE;
	game->rotate_left = FALSE;
	game->rotate_right = FALSE;
	game->previous_time = 0.0;
	init_texture_image("textures/wall/front.xpm", &game->front_wall, game);
	init_texture_image("textures/wall/back.xpm", &game->back_wall, game);
	init_texture_image("textures/wall/left.xpm", &game->left_wall, game);
	init_texture_image("textures/wall/right.xpm", &game->right_wall, game);
	mlx_mouse_move(
		game->mlx.ptr, game->mlx.win_ptr, WINDOW_X_CENTER, WINDOW_Y_CENTER);
}
