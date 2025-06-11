/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:12:09 by rmzvr             #+#    #+#             */
/*   Updated: 2025/06/10 16:28:00 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char map[mapHeight][mapWidth] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,0,1},
    {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1},
    {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,'E',0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->pixels_addr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	get_cell_x_head_addr(int x)
{
	return (x * cellSize);
}

int	get_cell_x_tail_addr(int x)
{
	return (x * cellSize + cellSize - 1);
}

int	get_cell_y_head_addr(int y)
{
	return (y * cellSize);
}

int	get_cell_y_tail_addr(int y)
{
	return (y * cellSize + cellSize - 1);
}

int get_cell_index(int position)
{
	return (position / cellSize);
}

void	draw_elements(char map[mapHeight][mapWidth], t_img *img, int cell_x, int cell_y, int x, int y)
{
	if (map[y][x] == WALL)
	{
		my_mlx_pixel_put(img, cell_x, cell_y, 0x008000);
	}
	else
	{
		my_mlx_pixel_put(img, cell_x, cell_y, 0x00BFFF);
	}
}

void	draw_borders(int mapWidthPx, int mapHeightPx, t_img *img, int cell_x, int cell_y, int x, int y)
{
	if (
		cell_x == x
		|| cell_y == y
		|| cell_x == mapWidthPx - 1
		|| cell_y == mapHeightPx - 1
		|| cell_x == get_cell_x_head_addr(x)
		|| cell_x == get_cell_x_tail_addr(x)
		|| cell_y == get_cell_y_head_addr(y)
		|| cell_y == get_cell_y_tail_addr(y)
	)
	{
		my_mlx_pixel_put(img, cell_x, cell_y, 0xAAAAAA);
	}
}

void	draw_line_horizontal(int x0, int y0, int x1, int y1, t_game *game, int color)
{
	int	temp;

	if (x0 > x1)
	{
		temp = x0;
		x0 = x1;
		x1 = temp;

		temp = y0;
		y0 = y1;
		y1 = temp;
	}

	int	dx = x1 - x0;
	int	dy = y1 - y0;
	int	dir = 1;
	if (dy < 0)
	{
		dir = -1;
		dy = dy * dir;
	}
	
	if (dx != 0)
	{
		int	x = x0;
		int	y = y0;
		int	D = (2 * dy) - dx;

		while (x < x1)
		{
			my_mlx_pixel_put(&game->mlx.img, x, y, color);
			if (D >= 0)
			{
				y = y + dir;
				D = D - (2 * dx);
			}
			D = D + 2 * dy;
			x++;
		}
	}
}

void	draw_line_vertical(int x0, int y0, int x1, int y1, t_game *game, int color)
{
	int	temp;

	if (y0 > y1)
	{
		temp = x0;
		x0 = x1;
		x1 = temp;

		temp = y0;
		y0 = y1;
		y1 = temp;
	}

	int	dx = x1 - x0;
	int	dy = y1 - y0;
	int	dir = 1;
	if (dx < 0)
	{
		dir = -1;
		dx = dx * dir;
	}
	if (dy != 0)
	{
		int	x = x0;
		int	y = y0;
		int	D = (2 * dx) - dy;

		while (y < y1)
		{
			my_mlx_pixel_put(&game->mlx.img, x, y, color);
			if (D >= 0)
			{
				x = x + dir;
				D = D - (2 * dy);
			}
			D = D + 2 * dx;
			y++;
		}
	}
}

void    draw_background(t_game *game, int color)
{
    // Faster way to clear the entire image with a solid color
    // This assumes 32-bit color (4 bytes per pixel)
    for (int i = 0; i < screenSize * game->mlx.img.ll / 4; i++) {
        ((unsigned int *)game->mlx.img.pixels_addr)[i] = color;
    }
    // Or for plain black, assuming bpp is 32:
    // memset(game->img.addr, 0, WINDOW_WIDTH * WINDOW_HEIGHT * (game->img.bpp / 8));
}

void	draw_line(t_game *game, int x0, int y0, int x1, int y1, int color)
{
	if (abs(x1 - x0) > abs(y1 - y0))
	{
		draw_line_horizontal(x0, y0, x1, y1, game, color);
	}
	else
	{
		draw_line_vertical(x0, y0, x1, y1, game, color);
	}
}

void	clear_image(t_game *game)
{
	memset(game->mlx.img.pixels_addr, 0, screenSize * screenSize * (game->mlx.img.bpp / 8));
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

static void	init_mlx_window_and_image(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		exit(1);
	mlx->win_ptr = mlx_new_window(mlx->ptr, 750, 750, "cub3D");
	if (mlx->win_ptr == NULL)
		cleanup(mlx, 1);
	mlx->img.ptr = mlx_new_image(mlx->ptr, 750, 750);
	if (mlx->img.ptr == NULL)
		cleanup(mlx, 1);
	mlx->img.pixels_addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp,
			&mlx->img.ll, &mlx->img.endian);
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

void	init_game(t_game *game)
{
	game->x = 0;
	game->y = 0;
	game->mapWidthPx = mapWidth * cellSize;
	game->mapHeightPx = mapHeight * cellSize;
	game->shiftX = 0;
	game->shiftY = 0;
	game->init_cell_pos_x = 0;
	game->init_cell_pos_y = 0;
	game->vector_x_start = 0;
	game->vector_y_start = 0;
	game->vector_x_end = 0;
	game->vector_y_end = 0;
	game->pos_x = 0;
	game->pos_y = 0;
	game->dir_x = 0;
	game->dir_y = 0;
	game->plane_x = 0.0;
	game->plane_y = 0.66;
}

void	draw_player(t_img *img, t_game *game)
{
	int	x;
	int	y;

	int	player_x_start;
	int	player_x_end;

	int	player_y_start;
	int	player_y_end;

	player_x_start = get_cell_x_head_addr(game->init_cell_pos_x) + playerSize + game->shiftX;
	player_x_end = player_x_start + playerSize;

	player_y_start = get_cell_y_head_addr(game->init_cell_pos_y) + playerSize + game->shiftY;
	player_y_end = player_y_start + playerSize;

	game->player_position.cell_x = player_x_start;
	game->player_position.cell_y = player_y_start;

	y = player_y_start;
	while (y < player_y_end)
	{
		x = player_x_start;
		while (x < player_x_end)
		{
			my_mlx_pixel_put(img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	draw_map(char map[mapHeight][mapWidth], t_game *game)
{
	int	cell_x;
	int	cell_y;

	game->y = 0;
	while (game->y < mapHeight)
	{
		game->x = 0;
		while (game->x < mapWidth)
		{
			cell_y = get_cell_y_head_addr(game->y);
			if (map[game->y][game->x] == 'N' || map[game->y][game->x] == 'S' || map[game->y][game->x] == 'W' || map[game->y][game->x] == 'E')
			{
				game->init_cell_pos_x = game->x;
				game->init_cell_pos_y = game->y;
			}
			while (cell_y <= get_cell_y_tail_addr(game->y))
			{
				cell_x = get_cell_x_head_addr(game->x);
				while (cell_x <= get_cell_x_tail_addr(game->x))
				{
					draw_elements(map, &game->mlx.img, cell_x, cell_y, game->x, game->y);
					draw_borders(game->mapWidthPx, game->mapHeightPx, &game->mlx.img, cell_x, cell_y, game->x, game->y);
					cell_x++;
				}
				cell_y++;
			}
			game->x++;
		}
		game->y++;
	}
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr, game->mlx.img.ptr, 0, 0);
}

int	check_wall(t_direction direction, t_game *game)
{
	int		curr_cell_y_index = get_cell_index(game->player_position.cell_y);
	int		sibling_cell_y_index = get_cell_index(game->player_position.cell_y + stepSize);

	int		curr_cell_x_index = get_cell_index(game->player_position.cell_x);
	int		sibling_cell_x_index = get_cell_index(game->player_position.cell_x + stepSize);

	if (direction == TOP)
	{
		int	prev_cell_y_index = get_cell_index(game->player_position.cell_y - stepSize);
		if (map[prev_cell_y_index][curr_cell_x_index] == WALL
			|| map[prev_cell_y_index][sibling_cell_x_index] == WALL)
		{
			return (1);
		}
	}
	else if (direction == RIGHT)
	{
		int	next_cell_x_index = get_cell_index(game->player_position.cell_x + stepSize - 1 + playerSize);
		if (map[curr_cell_y_index][next_cell_x_index] == WALL
			|| map[sibling_cell_y_index][next_cell_x_index] == WALL)
		{
			return (1);
		}
	}
	else if (direction == BOTTOM)
	{
		int	next_cell_y_index = get_cell_index(game->player_position.cell_y + stepSize - 1 + playerSize);
		if (map[next_cell_y_index][curr_cell_x_index] == WALL
			|| map[next_cell_y_index][sibling_cell_x_index] == WALL)
		{
			return (1);
		}
	}
	else if (direction == LEFT)
	{
		int	prev_cell_x_index = get_cell_index(game->player_position.cell_x - stepSize);
		if (map[curr_cell_y_index][prev_cell_x_index] == WALL
			|| map[sibling_cell_y_index][prev_cell_x_index] == WALL)
		{
			return (1);
		}
	}
	return (0);
}

void	draw_dda(char map[mapHeight][mapWidth], t_game *game)
{
	int		x = 0;
	double	posX = game->pos_x, posY = game->pos_y;  //x and y start position
	double	dirX = game->dir_x, dirY = game->dir_y; //initial direction vector

	while (x < screenSize)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)(screenSize) - 1; //x-coordinate in camera space
		double rayDirX = dirX + game->plane_x * cameraX;
		double rayDirY = dirY + game->plane_y * cameraX;

		// printf("rayDirX: %f, rayDirY: %f,\n", rayDirX, rayDirY);

		//which box of the map we're in
		int mapX = posX;
		int mapY = posY;

		//length of ray from current position to next x or y-side
		double sideDistX = 0.0;
		double sideDistY = 0.0;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = (rayDirX == 0) ? INFINITY : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? INFINITY : fabs(1 / rayDirY);

		// printf("deltaDistX: %f, deltaDistY: %f,\n", deltaDistX, deltaDistY);

		double perpWallDist = 0.0;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX = 0;
		int stepY = 0;

		int hit = 0; //was there a wall hit?
		int side = 0; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1 - posY) * deltaDistY;
		}

		// printf("sideDistX: %f, sideDistY: %f,\n", sideDistX, sideDistY);

		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else if (sideDistX > sideDistY)
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (map[mapY][mapX] > 0)
			{
				hit = 1;
			}
		}


		//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if (side == 0)
		{
			perpWallDist = (sideDistX - deltaDistX);
		}
		else
		{
			perpWallDist = (sideDistY - deltaDistY);
		}

		// printf("perpWallDist: %f\n", perpWallDist);


		//Calculate height of line to draw on screen
		int lineHeight = (int)(screenSize / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + screenSize / 2;
		if (drawStart < 0)
		{
			drawStart = 0;
		}
		int drawEnd = lineHeight / 2 + screenSize / 2;
		if (drawEnd >= screenSize)
		{
			drawEnd = screenSize - 1;
		}
		int color = 0x000000;

		if (map[mapY][mapX] > 0)
		{
			color = 0xFF0000;
		}

		// give x and y sides different brightness
		if (side == 1) {
			color = color / 2;
		}

		//draw the pixels of the stripe as a vertical line
		draw_line(game, x, drawStart, x, drawEnd, color);
		x++;
	}
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr, game->mlx.img.ptr, 0, 0);
}

static int	handle_keyboard(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		cleanup(&game->mlx, 1);
	}
	else if (keysym == XK_w)
	{
		// int		curr_cell_y_index = get_cell_index(game->player_position.cell_y);
		// int		sibling_cell_y_index = get_cell_index(game->player_position.cell_y + stepSize);

		// int		curr_cell_x_index = get_cell_index(game->player_position.cell_x);
		// int		sibling_cell_x_index = get_cell_index(game->player_position.cell_x + stepSize);


		// int	prev_cell_y_index = get_cell_index(game->player_position.cell_y - stepSize);
		// if (map[prev_cell_y_index][curr_cell_x_index] == WALL
		// 	|| map[prev_cell_y_index][sibling_cell_x_index] == WALL)
		// {
		// 	return (1);
		// }
		printf("before pos_x: %d, pos_y: %d\n", (int)game->pos_x, (int)game->pos_y);
		// printf("next pos_x: %f\n", game->dir_x * stepSize / 10);
		// printf("next pos_y: %f\n", game->dir_y * stepSize / 10);
		game->pos_x += game->dir_x * stepSize / 10;
		game->pos_y += game->dir_y * stepSize / 10;
		printf("after pos_x: %d, pos_y: %d\n", (int)game->pos_x, (int)game->pos_y);
		printf("tail %d\n", map[(int)(game->pos_y - game->dir_y * stepSize / 10)][(int)(game->pos_x - game->dir_x * stepSize / 10) + 1]);
	}
	else if (keysym == XK_s)
	{
		printf("before pos_x: %d, pos_y: %d\n", (int)game->pos_x - 1, (int)game->pos_y - 1);
		game->pos_x -= game->dir_x * stepSize / 10;
		game->pos_y -= game->dir_y * stepSize / 10;
		printf("pos_x: %d, pos_y: %d\n", (int)(game->pos_x - game->dir_x * stepSize / 10), (int)(game->pos_y - game->dir_y * stepSize / 10));
		printf("tail %d\n", map[(int)(game->pos_y - game->dir_y * stepSize / 10)][(int)(game->pos_x - game->dir_x * stepSize / 10)]);
	}
	else if (keysym == XK_a)
	{
		game->pos_x += game->dir_y * stepSize / 10;
		game->pos_y -= game->dir_x * stepSize / 10;
	}
	else if (keysym == XK_d)
	{
		game->pos_x -= game->dir_y * stepSize / 10;
		game->pos_y += game->dir_x * stepSize / 10;
	}
	else if (keysym == XK_Left)
	{
		double oldDirX = game->dir_x;
		game->dir_x = game->dir_x * cos(-M_PI / 6) - game->dir_y * sin(-M_PI / 6);
		game->dir_y = oldDirX * sin(-M_PI / 6) + game->dir_y * cos(-M_PI / 6);
		double oldPlaneX = game->plane_x;
		game->plane_x = game->plane_x * cos(-M_PI / 6) - game->plane_y * sin(-M_PI / 6);
		game->plane_y = oldPlaneX * sin(-M_PI / 6) + game->plane_y * cos(-M_PI / 6);
	}
	else if (keysym == XK_Right)
	{
		double oldDirX = game->dir_x;
		game->dir_x = game->dir_x * cos(M_PI / 6) - game->dir_y * sin(M_PI / 6);
		game->dir_y = oldDirX * sin(M_PI / 6) + game->dir_y * cos(M_PI / 6);
		double oldPlaneX = game->plane_x;
		game->plane_x = game->plane_x * cos(M_PI / 6) - game->plane_y * sin(M_PI / 6);
		game->plane_y = oldPlaneX * sin(M_PI / 6) + game->plane_y * cos(M_PI / 6);
	}
	// clear_image(game);
	draw_background(game, 0x000000);
	draw_dda(map, game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr, game->mlx.img.ptr, 0, 0);
	return (0);
}

void	init_draw_line(char map[mapHeight][mapWidth], t_game *game)
{
	double	dx = 0;
	double	dy = 0;
	game->vector_x_start = game->player_position.cell_x + (playerSize / 2);
	game->vector_y_start = game->player_position.cell_y + (playerSize / 2);
	if (map[game->init_cell_pos_y][game->init_cell_pos_x] == 'N')
		dy = -1;
	else if (map[game->init_cell_pos_y][game->init_cell_pos_x] == 'S')
		dy = 1;
	else if (map[game->init_cell_pos_y][game->init_cell_pos_x] == 'W')
		dx = -1;
	else if (map[game->init_cell_pos_y][game->init_cell_pos_x] == 'E')
		dx = 1;

	double	xmin = 0;
	double	xmax = mapWidth * cellSize - 1;

	double	ymin = 0;
	double	ymax = mapHeight * cellSize - 1;

	double	tx1;
	if (dx != 0)
	{
		tx1 = (xmin - game->vector_x_start) / dx;
	}
	else
	{
		tx1 = -INFINITY;
	}

	double	tx2;
	if (dx != 0)
	{
		tx2 = (xmax - game->vector_x_start) / dx;
	}
	else
	{
		tx2 = INFINITY;
	}

	double	ty1;
	if (dy != 0)
	{
		ty1 = (ymin - game->vector_y_start) / dy;
	}
	else
	{
		ty1 = -INFINITY;
	}

	double	ty2;
	if (dy != 0)
	{
		ty2 = (ymax - game->vector_y_start) / dy;
	}
	else
	{
		ty2 = INFINITY;
	}

	if (tx1 > tx2)
	{
		double	temp = tx1;
		tx1 = tx2;
		tx2 = temp;
	}
	if (ty1 > ty2)
	{
		double	temp = ty1;
		ty1 = ty2;
		ty2 = temp;
	}

	double	tmax;
	if (tx2 < ty2)
	{
		tmax = tx2;
	}
	else
	{
		tmax = ty2;
	}

	if (tmax < 0)
	{
		printf("Ray points backwards or no exit ahead\n");
	}

	game->vector_x_end = game->vector_x_start + dx * tmax;
	game->vector_y_end = game->vector_y_start + dy * tmax;
	draw_line(game, game->vector_x_start, game->vector_y_start, game->vector_x_end, game->vector_y_end, 0x000000);
}

void	init_player_position(char map[mapHeight][mapWidth], t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < mapHeight)
	{
		x = 0;
		while (x < mapWidth)
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E')
			{
				game->pos_x = (double)(get_cell_x_head_addr(x) + playerSize) / cellSize;
				game->pos_y = (double)(get_cell_y_head_addr(y) + playerSize) / cellSize;
			}
			x++;
		}
		y++;
	}
}

void	init_player_direction(char map[mapHeight][mapWidth], t_game *game)
{
	game->dir_x = 0;
	game->dir_y = 0;
	if (map[(int)game->pos_y][(int)game->pos_x] == 'N')
		game->dir_y = -1;
	else if (map[(int)game->pos_y][(int)game->pos_x] == 'S')
		game->dir_y = 1;
	else if (map[(int)game->pos_y][(int)game->pos_x] == 'W')
		game->dir_x = -1;
	else if (map[(int)game->pos_y][(int)game->pos_x] == 'E')
		game->dir_x = 1;
}

int	main(void)
{
	t_game	game;

	init_project(&game.mlx);
	init_game(&game);
	init_player_position(map, &game);
	init_player_direction(map, &game);
	draw_dda(map, &game);
	draw_map(map, &game);
	// draw_player(&game.mlx.img, &game);
	// init_draw_line(map, &game);
	mlx_hook(game.mlx.win_ptr, 2, 1L << 0, handle_keyboard, &game);
	mlx_loop(game.mlx.ptr);
}