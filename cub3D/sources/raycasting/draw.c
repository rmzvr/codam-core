/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:08:24 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/17 17:31:43 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	draw_ceiling(
	int x,
	double wall_start,
	t_game *game
)
{
	if (wall_start > 0)
	{
		draw_line(game, x, 0, x, wall_start, 0x87CEEB);
	}
}

static void	draw_floor(
	int x,
	double wall_end,
	t_game *game
)
{
	if (wall_end < WINDOW_WIDTH)
	{
		draw_line(game, x, wall_end, x, WINDOW_WIDTH, 0x4B3621);
	}
}

void	draw_textured_wall(
	int x,
	t_dda_data *dda,
	t_game *game,
	char *texture_data,
	int tex_width,
	int tex_height,
	int bpp,
	int tex_line_len
)
{
	static int	counter;

	counter = 0;
	// printf("wall_start: %d, wall_end: %d\n", dda->wall_start, dda->wall_end);
	// printf("tex_width: %d, tex_height: %d\n", tex_width, tex_height);
	int y = dda->wall_start;
	int line_height = dda->wall_end - dda->wall_start;
	double wall_x;

	// calculate where the wall was hit
	// printf("wall_start: %d, wall_end: %d\n", dda->wall_start, dda->wall_end);
	if (dda->hit_side == VERTICAL)
		wall_x = game->pos_y + dda->distance_to_wall * dda->ray_direction_y;
	else
		wall_x = game->pos_x + dda->distance_to_wall * dda->ray_direction_x;
	printf("%d. wall_x: %f\n", counter, wall_x);
	wall_x -= floor(wall_x);

	int tex_x = (int)(wall_x * (double)tex_width);
	if ((dda->hit_side == VERTICAL && dda->ray_direction_x > 0) || (dda->hit_side == HORIZONTAL && dda->ray_direction_y < 0))
		tex_x = tex_width - tex_x - 1;
	counter++;

	while (y < dda->wall_end)
	{
		// Calculate texture y
		int d = y * 256 - WINDOW_HEIGHT * 128 + line_height * 128;
		int tex_y = ((d * tex_height) / line_height) / 256;

		// Get color from texture
		unsigned int color = *(unsigned int *)(texture_data + (tex_y * tex_line_len + tex_x * (bpp / 8)));

		// Draw it to screen
		my_mlx_pixel_put(&(game->mlx.img), x, y, color);
		y++;
	}
}


static void	draw_wall(
	int x,
	t_dda_data *dda_data,
	t_game *game,
	t_texture *texture_data
)
{
	draw_textured_wall(x, dda_data, game, texture_data->wall_pixels_addr, texture_data->wall_img_width, texture_data->wall_img_height, texture_data->bpp, texture_data->line_len);
	// draw_line(game, x, dda_data->wall_start, x, dda_data->wall_end, dda_data->wall_color);
}

void	draw_vertical_stripe(
	int x,
	t_ray_trace_data *ray_trace_data,
	t_dda_data *dda_data,
	t_game *game,
	t_texture *texture_data
)
{
	calc_distance_to_wall(dda_data, ray_trace_data);
	calc_wall_height(dda_data);
	calc_wall_color(dda_data);
	draw_ceiling(x, dda_data->wall_start, game);
	draw_wall(x, dda_data, game, texture_data);
	draw_floor(x, dda_data->wall_end, game);
}
