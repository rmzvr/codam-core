#include "mlx.h"
#include "libft.h"

#define mapWidth 24
#define mapHeight 24

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x = 0;
	int		cellX = x;
	int		y = 0;
	int		cellY = y;
	int		cellSize = 30;
	int		worldMap[mapHeight][mapWidth] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 720, 720, "cub3D");
	img.img = mlx_new_image(mlx, 720, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	while (y < mapHeight)
	{
		x = 0;
		while (x < mapWidth)
		{
			if (worldMap[y][x] == 1)
			{
				// ft_printf("cellX: %d, cellY: %d, cell_value: %d\n", cellX, cellY, worldMap[y][x]);
				// ft_printf("right boundaries: %d\n", cellX + cellSize - 1);
				cellY = y * cellSize;
				while (cellY < y * cellSize + cellSize)
				{
					cellX = x * cellSize;
					while (cellX < x * cellSize + cellSize)
					{
						// ft_printf("cellX inside while: %d, cellY inside while: %d\n", cellX, cellY);
						my_mlx_pixel_put(&img, cellX, cellY, 0x00FF0000);
						// my_mlx_pixel_put(&img, cellX, cellY + cellSize - 1, 0x00FF0000);
						// my_mlx_pixel_put(&img, cellX + cellSize - 1, cellY, 0x00FF0000);
						// my_mlx_pixel_put(&img, cellX + cellSize - 1, cellY + cellSize - 1, 0x00FF0000);
						cellX++;
					}
					cellY++;
				}
			}
			x++;
		}
		y++;
	}
	// my_mlx_pixel_put(&img, 720 / 2, 720 / 2, 0x00FF0000);
	// my_mlx_pixel_put(&img, 720 / 3, 720 / 3, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}