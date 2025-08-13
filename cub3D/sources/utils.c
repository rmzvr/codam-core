/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rzvir <rzvir@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/16 13:03:35 by rzvir         #+#    #+#                 */
/*   Updated: 2025/07/22 15:08:45 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void	put_pixel(t_image *data, int x, int y, int color)
{
	int		x_offset;
	int		y_offset;
	char	*pixel_address;

	x_offset = x * (data->bytes_per_pixel / 8);
	y_offset = y * data->line_length;
	pixel_address = data->pixels_addr + x_offset + y_offset;
	*(unsigned int *)pixel_address = color;
}

static void	cleanup_mlx(t_mlx *mlx)
{
	if (mlx->img.ptr != NULL)
		mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	if (mlx->win_ptr != NULL)
		mlx_destroy_window(mlx->ptr, mlx->win_ptr);
	if (mlx->ptr != NULL)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
	}
}

static void	cleanup_textures(void *mlx, t_textures *textures)
{
	if (mlx == NULL)
		return ;
	if (textures->north.img.ptr != NULL)
		mlx_destroy_image(mlx, textures->north.img.ptr);
	if (textures->east.img.ptr != NULL)
		mlx_destroy_image(mlx, textures->east.img.ptr);
	if (textures->south.img.ptr != NULL)
		mlx_destroy_image(mlx, textures->south.img.ptr);
	if (textures->west.img.ptr != NULL)
		mlx_destroy_image(mlx, textures->west.img.ptr);
}

void	cleanup_game_state(t_game_state *state)
{
	cleanup_textures(state->mlx.ptr, &state->textures);
	cleanup_mlx(&state->mlx);
}
