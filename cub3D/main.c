/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:12:09 by rmzvr             #+#    #+#             */
/*   Updated: 2025/06/03 18:28:09 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>
#include <X11/keysym.h>

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

#define mapWidth 25
#define mapHeight 25
#define cellSize 30
#define playerSize 10
#define stepSize cellSize / 6

typedef enum	e_element {
	FLOOR,
	WALL,
}	t_element;

typedef enum	e_direction {
	TOP,
	RIGHT,
	BOTTOM,
	LEFT,
}	t_direction;

typedef struct s_player_position
{
	int	cell_x;
	int	cell_y;
}	t_player_position;

typedef struct s_img
{
	void	*ptr;
	char	*pixels_addr;
	int		bpp;
	int		ll;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*win_ptr;
	t_img	img;
}	t_mlx;

typedef struct s_game
{
	int					x;
	int					y;
	int					mapWidthPx;
	int					mapHeightPx;
	int					shiftX;
	int					shiftY;
	int					init_cell_pos_x;
	int					init_cell_pos_y;
	double				bx;
	double				by;
	double				vector_x_start;
	double				vector_y_start;
	double				vector_x_end;
	double				vector_y_end;
	t_player_position	player_position;
	t_mlx	mlx;
}	t_game;

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

void	draw_line_horizontal(int x0, int y0, int x1, int y1, t_game *game)
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
			my_mlx_pixel_put(&game->mlx.img, x, y, 0x000000);
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

void	draw_line_vertical(int x0, int y0, int x1, int y1, t_game *game)
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
			my_mlx_pixel_put(&game->mlx.img, x, y, 0x000000);
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

void	draw_line(t_game *game, int x0, int y0, int x1, int y1)
{
	if (abs(x1 - x0) > abs(y1 - y0))
	{
		draw_line_horizontal(x0, y0, x1, y1, game);
	}
	else
	{
		draw_line_vertical(x0, y0, x1, y1, game);
	}
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
	
	char	map[mapHeight][mapWidth] =
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

static int	handle_keyboard(int keysym, t_game *game)
{
	char	map[mapHeight][mapWidth] =
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

	if (keysym == XK_Escape)
	{
		cleanup(&game->mlx, 1);
	}
	else if (keysym == XK_w)
	{
		if (check_wall(TOP, game))
			return (0);
		game->shiftY -= stepSize;
	}
	else if (keysym == XK_s)
	{
		if (check_wall(BOTTOM, game))
			return (0);
		game->shiftY += stepSize;
	}
	else if (keysym == XK_a)
	{
		if (check_wall(LEFT, game))
			return (0);
		game->shiftX -= stepSize;
	}
	else if (keysym == XK_d)
	{
		if (check_wall(RIGHT, game))
			return (0);
		game->shiftX += stepSize;
	}
	else if (keysym == XK_Left)
	{
		game->vector_x_start = game->player_position.cell_x + (playerSize / 2);
		game->vector_y_start = game->player_position.cell_y + (playerSize / 2);
		double	xp = game->vector_x_end - game->vector_x_start;
		double	yp = game->vector_y_end - game->vector_y_start;
		double	xpp = xp * cos(M_PI / 4) + yp * sin(M_PI / 4);
		double	ypp = -xp * sin(M_PI / 4) + yp * cos(M_PI / 4);
		game->vector_x_end = xpp + game->vector_x_start;
		game->vector_y_end = ypp + game->vector_y_start;
		printf("vector_x_start: %f, vector_y_start: %f\n", game->vector_x_start, game->vector_y_start);
		printf("vector_x_end: %f, vector_y_end: %f\n", game->vector_x_end, game->vector_y_end);
	}
	else if (keysym == XK_Right)
	{
		game->vector_x_start = game->player_position.cell_x + (playerSize / 2);
		game->vector_y_start = game->player_position.cell_y + (playerSize / 2);
		double	xp = game->vector_x_end - game->vector_x_start;
		double	yp = game->vector_y_end - game->vector_y_start;
		double	xpp = xp * cos(M_PI / 4) - yp * sin(M_PI / 4);
		double	ypp = xp * sin(M_PI / 4) + yp * cos(M_PI / 4);
		game->vector_x_end = xpp + game->vector_x_start;
		game->vector_y_end = ypp + game->vector_y_start;
		ft_printf("player - x: %d, y: %d\n", game->player_position.cell_x, game->player_position.cell_y);
		printf("vector_x_start: %f, vector_y_start: %f\n", game->vector_x_start, game->vector_y_start);
		printf("vector_x_end: %f, vector_y_end: %f\n", game->vector_x_end, game->vector_y_end);
	}
	draw_map(map, game);
	draw_player(&game->mlx.img, game);
	ft_printf("player - x: %d, y: %d\n", game->player_position.cell_x, game->player_position.cell_y);
	draw_line(game, game->vector_x_start, game->vector_y_start, game->vector_x_end, game->vector_y_end);
	return (0);
}

void	init_draw_line(char map[mapHeight][mapWidth], t_game *game)
{
	game->vector_x_start = game->player_position.cell_x + (playerSize / 2);
	game->vector_y_start = game->player_position.cell_y + (playerSize / 2);
	if (map[game->init_cell_pos_y][game->init_cell_pos_x] == 'N')
	{
		game->vector_x_end = game->vector_x_start + 0;
		game->vector_y_end = game->vector_y_start + -cellSize;
	}
	else if (map[game->init_cell_pos_y][game->init_cell_pos_x] == 'S')
	{
		game->vector_x_end = game->vector_x_start + 0;
		game->vector_y_end = game->vector_y_start + cellSize;
	}
	else if (map[game->init_cell_pos_y][game->init_cell_pos_x] == 'W')
	{
		game->vector_x_end = game->vector_x_start + -cellSize;
		game->vector_y_end = game->vector_y_start + 0;
	}
	else if (map[game->init_cell_pos_y][game->init_cell_pos_x] == 'E')
	{
		game->vector_x_end = game->vector_x_start + cellSize;
		game->vector_y_end = game->vector_y_start + 0;
	}
	draw_line(game, game->vector_x_start, game->vector_y_start, game->vector_x_end, game->vector_y_end);
}

int	main(void)
{
	t_game	game;
	char	map[mapHeight][mapWidth] =
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

	init_project(&game.mlx);
	init_game(&game);
	draw_map(map, &game);
	draw_player(&game.mlx.img, &game);
	init_draw_line(map, &game);
	mlx_hook(game.mlx.win_ptr, 2, (1L << 0), handle_keyboard, &game);
	mlx_loop(game.mlx.ptr);
}
