/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:12:09 by rmzvr             #+#    #+#             */
/*   Updated: 2025/06/12 17:52:56 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char map[MAP_HEIGHT][MAP_WIDTH] =
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
    {1,0,0,0,0,0,0,0,0,0,0,0,'N',0,0,0,0,0,0,0,0,0,0,0,1},
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

void	ft_swap_int(int *a, int *b)
{
	int	temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

void	ft_swap_double(double *a, double *b)
{
	double	temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->pixels_addr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	get_cell_x_head_addr(int x)
{
	return (x * TAIL_SIZE);
}

int	get_cell_x_tail_addr(int x)
{
	return (x * TAIL_SIZE + TAIL_SIZE - 1);
}

int	get_cell_y_head_addr(int y)
{
	return (y * TAIL_SIZE);
}

int	get_cell_y_tail_addr(int y)
{
	return (y * TAIL_SIZE + TAIL_SIZE - 1);
}

int get_cell_index(int position)
{
	return (position / TAIL_SIZE);
}

void	draw_elements(char map[MAP_HEIGHT][MAP_WIDTH], t_img *img, int cell_x, int cell_y, int x, int y)
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

void	draw_borders(t_img *img, int cell_x, int cell_y, int x, int y)
{
	if (
		cell_x == x
		|| cell_y == y
		|| cell_x == WINDOW_MAX_X
		|| cell_y == WINDOW_MAX_Y
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
	if (x0 > x1)
	{
		ft_swap_int(&x0, &x1);
		ft_swap_int(&y0, &y1);
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
	if (y0 > y1)
	{
		ft_swap_int(&x0, &x1);
		ft_swap_int(&y0, &y1);
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
    for (int i = 0; i < WINDOW_WIDTH * game->mlx.img.ll / 4; i++) {
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
	memset(game->mlx.img.pixels_addr, 0, WINDOW_WIDTH * WINDOW_HEIGHT * (game->mlx.img.bpp / 8));
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

	game->shiftX = 0;
	game->shiftY = 0;

	game->player_position_x_px = 0;
	game->player_position_y_px = 0;

	game->vector_x_start = 0;
	game->vector_y_start = 0;

	game->vector_x_end = 0;
	game->vector_y_end = 0;

	game->player_position_x_double = 0;
	game->player_position_y_double = 0;

	game->player_position_x_int_rounded = 0;
	game->player_position_y_int_rounded = 0;

	game->dir_x = 0;
	game->dir_y = 0;

	game->plane_x = 0.0;
	game->plane_y = 0.66;

	game->delta_vector_x = 0;
	game->delta_vector_y = 0;
}

void	draw_player(t_img *img, t_game *game)
{
	int	x;
	int	y;

	int	player_x_start;
	int	player_x_end;

	int	player_y_start;
	int	player_y_end;

	player_x_start = get_cell_x_head_addr(game->player_position_x_px) + PLAYER_SIZE + game->shiftX;
	player_x_end = player_x_start + PLAYER_SIZE;

	player_y_start = get_cell_y_head_addr(game->player_position_y_px) + PLAYER_SIZE + game->shiftY;
	player_y_end = player_y_start + PLAYER_SIZE;

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

void	draw_map(char map[MAP_HEIGHT][MAP_WIDTH], t_game *game)
{
	int	cell_x;
	int	cell_y;

	game->y = 0;
	while (game->y < MAP_HEIGHT)
	{
		game->x = 0;
		while (game->x < MAP_WIDTH)
		{
			cell_y = get_cell_y_head_addr(game->y);
			if (map[game->y][game->x] == 'N' || map[game->y][game->x] == 'S' || map[game->y][game->x] == 'W' || map[game->y][game->x] == 'E')
			{
				game->player_position_x_px = game->x;
				game->player_position_y_px = game->y;
			}
			while (cell_y <= get_cell_y_tail_addr(game->y))
			{
				cell_x = get_cell_x_head_addr(game->x);
				while (cell_x <= get_cell_x_tail_addr(game->x))
				{
					draw_elements(map, &game->mlx.img, cell_x, cell_y, game->x, game->y);
					draw_borders(&game->mlx.img, cell_x, cell_y, game->x, game->y);
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
	int		sibling_cell_y_index = get_cell_index(game->player_position.cell_y + STEP_SIZE);

	int		curr_cell_x_index = get_cell_index(game->player_position.cell_x);
	int		sibling_cell_x_index = get_cell_index(game->player_position.cell_x + STEP_SIZE);

	if (direction == TOP)
	{
		int	prev_cell_y_index = get_cell_index(game->player_position.cell_y - STEP_SIZE);
		if (map[prev_cell_y_index][curr_cell_x_index] == WALL
			|| map[prev_cell_y_index][sibling_cell_x_index] == WALL)
		{
			return (1);
		}
	}
	else if (direction == RIGHT)
	{
		int	next_cell_x_index = get_cell_index(game->player_position.cell_x + STEP_SIZE - 1 + PLAYER_SIZE);
		if (map[curr_cell_y_index][next_cell_x_index] == WALL
			|| map[sibling_cell_y_index][next_cell_x_index] == WALL)
		{
			return (1);
		}
	}
	else if (direction == BOTTOM)
	{
		int	next_cell_y_index = get_cell_index(game->player_position.cell_y + STEP_SIZE - 1 + PLAYER_SIZE);
		if (map[next_cell_y_index][curr_cell_x_index] == WALL
			|| map[next_cell_y_index][sibling_cell_x_index] == WALL)
		{
			return (1);
		}
	}
	else if (direction == LEFT)
	{
		int	prev_cell_x_index = get_cell_index(game->player_position.cell_x - STEP_SIZE);
		if (map[curr_cell_y_index][prev_cell_x_index] == WALL
			|| map[sibling_cell_y_index][prev_cell_x_index] == WALL)
		{
			return (1);
		}
	}
	return (0);
}

void	draw_dda(char map[MAP_HEIGHT][MAP_WIDTH], t_game *game)
{
	int		x = 0;
	double	posX = game->player_position_x_double, posY = game->player_position_y_double;  //x and y start position

	while (x < WINDOW_WIDTH)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)(WINDOW_WIDTH) - 1; //x-coordinate in camera space
		double rayDirX = game->dir_x + game->plane_x * cameraX;
		double rayDirY = game->dir_y + game->plane_y * cameraX;

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
		int lineHeight = (int)(WINDOW_HEIGHT / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + WINDOW_HEIGHT / 2;
		if (drawStart < 0)
		{
			drawStart = 0;
		}
		int drawEnd = lineHeight / 2 + WINDOW_HEIGHT / 2;
		if (drawEnd >= WINDOW_HEIGHT)
		{
			drawEnd = WINDOW_MAX_Y;
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

double	calc_vector_magnitude(double delta_x, double delta_y)
{
	double	magnitude;

	magnitude = sqrt(delta_x * delta_x + delta_y * delta_y);
	return (magnitude);
}

double	calc_delta_vector(int a, int b)
{
	double delta;

	delta = b - a;
	return (delta);
}

void	normalize_vector(double *delta_x, double *delta_y, double magnitude, t_game *game)
{
	if (magnitude != 0)
	{
		game->unit_delta_vector_x = *delta_x / magnitude;
		game->unit_delta_vector_y = *delta_y / magnitude;
	}
}

void	draw_ray(t_game *game)
{
	double	tx1;
	double	tx2;
	double	ty1;
	double	ty2;
	double	tmax;

	game->vector_x_start = game->player_position.cell_x + (PLAYER_SIZE / 2);
	game->vector_y_start = game->player_position.cell_y + (PLAYER_SIZE / 2);

	if (game->dir_x != 0)
		tx1 = (WINDOW_MIN_X - game->vector_x_start) / game->dir_x;
	else
		tx1 = -INFINITY;

	if (game->dir_x != 0)
		tx2 = (WINDOW_MAX_X - game->vector_x_start) / game->dir_x;
	else
		tx2 = INFINITY;

	if (game->dir_y != 0)
		ty1 = (WINDOW_MIN_Y - game->vector_y_start) / game->dir_y;
	else
		ty1 = -INFINITY;

	if (game->dir_y != 0)
		ty2 = (WINDOW_MAX_Y - game->vector_y_start) / game->dir_y;
	else
		ty2 = INFINITY;

	if (tx1 > tx2)
		ft_swap_double(&tx1, &tx2);
	if (ty1 > ty2)
		ft_swap_double(&ty1, &ty2);

	if (tx2 < ty2)
		tmax = tx2;
	else
		tmax = ty2;

	if (tmax < 0)
		printf("Ray points backwards or no exit ahead\n");

	game->vector_x_end = game->vector_x_start + game->dir_x * tmax;
	game->vector_y_end = game->vector_y_start + game->dir_y * tmax;
	draw_line(game, game->vector_x_start, game->vector_y_start, game->vector_x_end, game->vector_y_end, 0x000000);
}

static int	handle_keyboard(int keysym, t_game *game)
{
	// double cosA = cos(M_PI / 6);
	// double sinA = sin(M_PI / 6);
	const double ROT_ANGLE = M_PI / 6;
	game->vector_x_start = game->player_position.cell_x + (PLAYER_SIZE / 2);
	game->vector_y_start = game->player_position.cell_y + (PLAYER_SIZE / 2);

	// game->delta_vector_x = calc_delta_vector(game->vector_x_start, game->vector_x_end);
	// game->delta_vector_y = calc_delta_vector(game->vector_y_start, game->vector_y_end);

	double vector_magnitude = calc_vector_magnitude(game->dir_x, game->dir_y);
	normalize_vector(&game->dir_x, &game->dir_y, vector_magnitude, game);
	// printf("before delta_x: %f, delta_y: %f\n", game->delta_vector_x, game->delta_vector_y);
	// printf("after delta_x: %f, delta_y: %f\n", game->delta_vector_x, game->delta_vector_y);
	// if (length != 0)
	// {
	// 	dx /= length;
	// 	dy /= length;
	// }

	if (keysym == XK_Escape)
	{
		cleanup(&game->mlx, 1);
	}
	else if (keysym == XK_w)
	{
		game->shiftY -= STEP_SIZE;
		game->vector_y_start -= STEP_SIZE;
		game->vector_y_end -= STEP_SIZE;

		// int	x = game->player_position_x_double + game->dir_x * STEP_SIZE / 10;
		// int	y = game->player_position_y_double + game->dir_y * STEP_SIZE / 10;
		// if (map[y][x] != 0 && map[y][x] != 69)
		// 	return (0);
		// game->player_position_x_double += game->dir_x * STEP_SIZE / 10;
		// game->player_position_y_double += game->dir_y * STEP_SIZE / 10;
	}
	else if (keysym == XK_s)
	{
		game->shiftY += STEP_SIZE;
		game->vector_y_start += STEP_SIZE;
		game->vector_y_end += STEP_SIZE;

		// int	x = game->player_position_x_double - game->dir_x * STEP_SIZE / 10;
		// int	y = game->player_position_y_double - game->dir_y * STEP_SIZE / 10;
		// if (map[y][x] != 0 && map[y][x] != 69)
		// 	return (0);
		// game->player_position_x_double -= game->dir_x * STEP_SIZE / 10;
		// game->player_position_y_double -= game->dir_y * STEP_SIZE / 10;
	}
	else if (keysym == XK_a)
	{
		game->shiftX -= STEP_SIZE;
		game->vector_x_start -= STEP_SIZE;
		game->vector_x_end -= STEP_SIZE;

		// int	x = game->player_position_x_double + game->dir_y * STEP_SIZE / 10;
		// int	y = game->player_position_y_double - game->dir_x * STEP_SIZE / 10;
		// if (map[y][x] != 0 && map[y][x] != 69)
		// 	return (0);
		// game->player_position_x_double += game->dir_y * STEP_SIZE / 10;
		// game->player_position_y_double -= game->dir_x * STEP_SIZE / 10;
	}
	else if (keysym == XK_d)
	{
		game->shiftX += STEP_SIZE;
		game->vector_x_start += STEP_SIZE;
		game->vector_x_end += STEP_SIZE;

		// int	x = game->player_position_x_double - game->dir_y * STEP_SIZE / 10;
		// int	y = game->player_position_y_double + game->dir_x * STEP_SIZE / 10;
		// if (map[y][x] != 0 && map[y][x] != 69)
		// 	return (0);
		// game->player_position_x_double -= game->dir_y * STEP_SIZE / 10;
		// game->player_position_y_double += game->dir_x * STEP_SIZE / 10;
	}
	else if (keysym == XK_Left)
	{
		// double	xpp = game->unit_delta_vector_x * cosA + game->unit_delta_vector_y * sinA;
		// double	ypp = -game->unit_delta_vector_x * sinA + game->unit_delta_vector_y * cosA;
		// game->vector_x_end = game->vector_x_start + xpp;
		// game->vector_y_end = game->vector_y_start + ypp;

		double old_dir_x = game->dir_x;
		game->dir_x = old_dir_x * cos(-ROT_ANGLE) - game->dir_y * sin(-ROT_ANGLE);
		game->dir_y = old_dir_x * sin(-ROT_ANGLE) + game->dir_y * cos(-ROT_ANGLE);

		// double oldDirX = game->dir_x;
		// game->dir_x = game->dir_x * cos(-M_PI / 6) - game->dir_y * sin(-M_PI / 6);
		// game->dir_y = oldDirX * sin(-M_PI / 6) + game->dir_y * cos(-M_PI / 6);
		// double oldPlaneX = game->plane_x;
		// game->plane_x = game->plane_x * cos(-M_PI / 6) - game->plane_y * sin(-M_PI / 6);
		// game->plane_y = oldPlaneX * sin(-M_PI / 6) + game->plane_y * cos(-M_PI / 6);
	}
	else if (keysym == XK_Right)
	{
		// double	xpp = game->unit_delta_vector_x * cosA - game->unit_delta_vector_y * sinA;
		// double	ypp = game->unit_delta_vector_x * sinA + game->unit_delta_vector_y * cosA;
		// game->vector_x_end = game->vector_x_start + xpp;
		// game->vector_y_end = game->vector_y_start + ypp;

		double old_dir_x = game->dir_x;
		game->dir_x = old_dir_x * cos(ROT_ANGLE) - game->dir_y * sin(ROT_ANGLE);
		game->dir_y = old_dir_x * sin(ROT_ANGLE) + game->dir_y * cos(ROT_ANGLE);

		// double oldDirX = game->dir_x;
		// game->dir_x = game->dir_x * cos(M_PI / 6) - game->dir_y * sin(M_PI / 6);
		// game->dir_y = oldDirX * sin(M_PI / 6) + game->dir_y * cos(M_PI / 6);
		// double oldPlaneX = game->plane_x;
		// game->plane_x = game->plane_x * cos(M_PI / 6) - game->plane_y * sin(M_PI / 6);
		// game->plane_y = oldPlaneX * sin(M_PI / 6) + game->plane_y * cos(M_PI / 6);
	}

	vector_magnitude = calc_vector_magnitude(game->dir_x, game->dir_y);
	normalize_vector(&game->dir_x, &game->dir_y, vector_magnitude, game);

	// game->delta_vector_x = calc_delta_vector(game->vector_x_start, game->vector_x_end);
	// game->delta_vector_y = calc_delta_vector(game->vector_y_start, game->vector_y_end);

	// vector_magnitude = calc_vector_magnitude(game->delta_vector_x, game->delta_vector_y);
	// normalize_vector(&game->delta_vector_x, &game->delta_vector_y, vector_magnitude, game);

	// double	tx1;
	// if (game->unit_delta_vector_x != 0)
	// {
	// 	tx1 = (WINDOW_MIN_X - game->vector_x_start) / game->unit_delta_vector_x;
	// }
	// else
	// {
	// 	tx1 = -INFINITY;
	// }

	// double	tx2;
	// if (game->unit_delta_vector_x != 0)
	// {
	// 	tx2 = (WINDOW_MAX_X - game->vector_x_start) / game->unit_delta_vector_x;
	// }
	// else
	// {
	// 	tx2 = INFINITY;
	// }

	// double	ty1;
	// if (game->unit_delta_vector_y != 0)
	// {
	// 	ty1 = (WINDOW_MIN_Y - game->vector_y_start) / game->unit_delta_vector_y;
	// }
	// else
	// {
	// 	ty1 = -INFINITY;
	// }

	// double	ty2;
	// if (game->unit_delta_vector_y != 0)
	// {
	// 	ty2 = (WINDOW_MAX_Y - game->vector_y_start) / game->unit_delta_vector_y;
	// }
	// else
	// {
	// 	ty2 = INFINITY;
	// }

	// if (tx1 > tx2)
	// {
	// 	ft_swap_double(&tx1, &tx2);
	// }
	// if (ty1 > ty2)
	// {
	// 	ft_swap_double(&ty1, &ty2);
	// }

	// double	tmax;
	// if (tx2 < ty2)
	// {
	// 	tmax = tx2;
	// }
	// else
	// {
	// 	tmax = ty2;
	// }

	// if (tmax < 0)
	// {
	// 	printf("Ray points backwards or no exit ahead\n");
	// 	// return;
	// }
	// game->vector_x_end = game->vector_x_start + game->unit_delta_vector_x * tmax;
	// game->vector_y_end = game->vector_y_start + game->unit_delta_vector_y * tmax;
	// printf("handle_keyboard -> tmax: %f\n", tmax);
	draw_map(map, game);
	draw_player(&game->mlx.img, game);
	draw_ray(game);
	// draw_line(game, game->vector_x_start, game->vector_y_start, game->vector_x_end, game->vector_y_end, 0x000000);

	//? DDA
	// draw_background(game, 0x000000);
	// draw_dda(map, game);
	// mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr, game->mlx.img.ptr, 0, 0);
	return (0);
}

void	init_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E')
			{
				game->player_position_x_double = (double)(get_cell_x_head_addr(x) + PLAYER_SIZE) / TAIL_SIZE;
				game->player_position_y_double = (double)(get_cell_y_head_addr(y) + PLAYER_SIZE) / TAIL_SIZE;

				game->player_position_x_int_rounded = (int)game->player_position_x_double;
				game->player_position_y_int_rounded = (int)game->player_position_y_double;

				game->player_position_x_px = get_cell_x_head_addr(x) + PLAYER_SIZE;
				game->player_position_y_px = get_cell_x_head_addr(y) + PLAYER_SIZE;

				// printf("game->player_position_x_double: %f, game->player_position_y_double: %f\n", game->player_position_x_double, game->player_position_y_double);

				// printf("game->player_position_x_int_rounded: %d, game->player_position_y_int_rounded: %d\n", game->player_position_x_int_rounded, game->player_position_y_int_rounded);

				// printf("game->player_position_x_px: %d, game->player_position_y_px: %d\n", game->player_position_x_px, game->player_position_y_px);
			}
			x++;
		}
		y++;
	}
}

void	init_player_direction(t_game *game)
{
	if (map[game->player_position_y_int_rounded][game->player_position_x_int_rounded] == 'N')
		game->dir_y = -1;
	else if (map[game->player_position_y_int_rounded][game->player_position_x_int_rounded] == 'S')
		game->dir_y = 1;
	else if (map[game->player_position_y_int_rounded][game->player_position_x_int_rounded] == 'W')
		game->dir_x = -1;
	else if (map[game->player_position_y_int_rounded][game->player_position_x_int_rounded] == 'E')
		game->dir_x = 1;
}

int	main(void)
{
	t_game	game;

	init_project(&game.mlx);
	init_game(&game);
	init_player_position(&game);
	init_player_direction(&game);
	// draw_dda(map, &game);
	draw_map(map, &game);
	draw_player(&game.mlx.img, &game);
	draw_ray(&game);
	mlx_hook(game.mlx.win_ptr, 2, 1L << 0, handle_keyboard, &game);
	mlx_loop(game.mlx.ptr);
}