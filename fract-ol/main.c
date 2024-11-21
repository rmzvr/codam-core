#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <math.h>

typedef struct	s_img {
	void	*ptr;
	char	*pixels_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct	s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef struct	s_shift
{
	int	top;
	int	left;
	int	right;
	int	bottom;
}	t_shift;

typedef struct	s_mlx {
	void		*ptr;
	void		*win_ptr;
	t_img		img1;
	t_img		img2;
	int			iterations;
	t_complex	z;
	t_complex	c;
	int			window_width;
	int			window_height;
	int			x;
	int			y;
	double		zoom;
	t_shift		shift;
	int			current_buffer;
}	t_mlx;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int				offset;
	unsigned int	*curr_pixel;

	offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	curr_pixel = (unsigned int *)(img->pixels_addr + offset);
	*curr_pixel = color;
}

int	encode_rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red << 16 | green << 8 | blue);
}

int	handle_close(t_mlx *mlx)
{
	// mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	mlx_destroy_window(mlx->ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	exit(1);
	return (1);
}

int	handle_zoom(int x, int y, t_mlx *mlx)
{
	(void) mlx;
	printf("x: %d", x);
	printf("y: %d", y);
	return (1);
}

double	scale_x(int i, int width)
{
	double d_i;
	double d_width;

	d_i = (double) i;
	d_width = (double) width;
	return (1.0 - -2.0) * (i - 0.0) / (d_width - 0.0) + -2.0;
}

double	scale_y(int i, int height)
{
	double d_i;
	double d_height;

	d_i = (double) i;
	d_height = (double) height;
	return (1.5 - -1.5) * (i - 0.0) / (d_height - 0.0) + -1.5;
}

void	render_fractal(t_mlx *mlx, double zoom, t_shift shift, t_img *img)
{
	(void) shift;
	(void) zoom;
	mlx->x = 0;
	mlx->y = 0;
	mlx->iterations = 0;
	mlx->z.real = 0;
	mlx->z.imaginary = 0;
	mlx->c.real = (scale_x(mlx->x, mlx->window_width));
	mlx->c.imaginary = (scale_y(mlx->y, mlx->window_height));
	while (mlx->y < mlx->window_height)
	{
		mlx->x = 0;
		while (mlx->x < mlx->window_width)
		{
			mlx->iterations = 0;
			while (mlx->iterations < 1000)
			{
				if (mlx->z.real < -2 || mlx->z.real > 1 || mlx->z.imaginary < -1.5 || mlx->z.imaginary > 1.5)
				{
					my_mlx_pixel_put(img, mlx->x, mlx->y, (unsigned int)0x000000 + (unsigned int)mlx->iterations + 40);
					mlx->z.real = 0;
					mlx->z.imaginary = 0;
					break;
				}
				else
				{
					my_mlx_pixel_put(img, mlx->x, mlx->y, 0xFFFFFF);
				}
				double temp_real = (mlx->z.real * mlx->z.real) - (mlx->z.imaginary * mlx->z.imaginary);
				mlx->z.imaginary = 2 * mlx->z.real * mlx->z.imaginary;
				mlx->z.real = temp_real;

				mlx->z.real += mlx->c.real;
				mlx->z.imaginary += mlx->c.imaginary;
				mlx->iterations++;
				double res = sqrt((mlx->z.real * mlx->z.real) + (mlx->z.imaginary * mlx->z.imaginary));
				if (res > 4)
				{
						my_mlx_pixel_put(img, mlx->x, mlx->y, (unsigned int)0x000000 + (unsigned int)mlx->iterations + 40);
					mlx->z.real = 0;
					mlx->z.imaginary = 0;
					break;
				}
				else
				{
					my_mlx_pixel_put(img, mlx->x, mlx->y, 0xFFFFFF);
				}
				mlx->iterations++;
			}
			mlx->x++;
			mlx->c.real = (scale_x(mlx->x + shift.right, mlx->window_width)) * zoom;
		}
		mlx->y++;
		mlx->c.imaginary = (scale_y(mlx->y + shift.bottom, mlx->window_height)) * zoom;
	}
}
void	render_double_buffering(t_mlx *mlx)
{
	t_img	*curr_img;

	if (mlx->current_buffer == 0)
	{
		curr_img = &mlx->img1;
	}
	else
	{
		curr_img = &mlx->img2;
	}

	printf("curr_img %p\n", curr_img->ptr);

	render_fractal(mlx, mlx->zoom, mlx->shift, curr_img);

	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, curr_img->ptr, 0, 0);

	mlx->current_buffer = 1 - mlx->current_buffer;
}

int	handle_input(int keysym, t_mlx *mlx)
{
	// if (keysym == XK_Escape)
	// {
	// 	mlx_destroy_image(mlx->ptr, mlx->img2.ptr);
	// 	mlx->img2.ptr = mlx_new_image(mlx->ptr, mlx->window_width, mlx->window_height);
	// 	my_mlx_pixel_put(&mlx->img2, mlx->window_width / 2 - 100, mlx->window_height / 2 - 100, 0xFFFFFF);
	// 	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img2.ptr, 0, 0);
	// 	// mlx_destroy_window(mlx->ptr, mlx->win_ptr);
	// 	// mlx_destroy_display(mlx->ptr);
	// 	// free(mlx->ptr);
	// 	// exit(1);

	if (keysym == XK_Up)
	{
		printf("XK_Up\n");
		mlx->shift.bottom -= 200 * mlx->zoom;
		printf("bottom = %d\n", mlx->shift.bottom);
		render_double_buffering(mlx);
	}
	else if (keysym == XK_Down)
	{
		printf("XK_Down\n");
		mlx->shift.bottom += 200 * mlx->zoom;
		printf("bottom = %d\n", mlx->shift.bottom);
		render_double_buffering(mlx);
	}
	else if (keysym == XK_Left)
	{
		printf("XK_Left\n");
		mlx->shift.right -= 200 * mlx->zoom;
		printf("right = %d\n", mlx->shift.right);
		render_double_buffering(mlx);
	}
	else if (keysym == XK_Right)
	{
		printf("XK_Right\n");
		mlx->shift.right += 200 * mlx->zoom;
		printf("right = %d\n", mlx->shift.right);
		render_double_buffering(mlx);
	}
	return (0);
}

int mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	(void) x;
	(void) y;
	printf("button %d\n", button);

	if (button == 4)
	{
		printf("XK_equal\n");
		if (mlx->zoom < 0.11)
			mlx->zoom -= 0.01;
		else
			mlx->zoom -= 0.1;
		printf("zoom = %f\n", mlx->zoom);
		render_double_buffering(mlx);
	}
	else if (button == 5)
	{
		printf("XK_minus\n");
		mlx->zoom += 0.1;
		render_double_buffering(mlx);
	}
	return (1);
}

int	main(void)
{
	t_mlx	mlx;

	mlx.shift.top = 0;
	mlx.shift.left = 0;
	mlx.shift.right = 0;
	mlx.shift.bottom = 0;
	mlx.zoom = 1.0;
	mlx.x = 0;
	mlx.y = 0;
	mlx.window_width = 800;
	mlx.window_height = 800;
	mlx.ptr = mlx_init();
	if (mlx.ptr == NULL)
		return (1);
	mlx.win_ptr = mlx_new_window(mlx.ptr, mlx.window_width, mlx.window_height, "Hello world!");
	if (mlx.win_ptr == NULL)
	{
		mlx_destroy_display(mlx.ptr);
		free(mlx.ptr);
		return (1);
	}

	// img1
	mlx.img1.ptr = mlx_new_image(mlx.ptr, mlx.window_width, mlx.window_height);
	if (mlx.img1.ptr == NULL)
	{
		mlx_destroy_window(mlx.ptr, mlx.win_ptr);
		mlx_destroy_display(mlx.ptr);
		free(mlx.ptr);
		exit(1);
	}
	mlx.img1.pixels_addr = mlx_get_data_addr(mlx.img1.ptr, &mlx.img1.bits_per_pixel, &mlx.img1.line_length, &mlx.img1.endian);
	if (mlx.img1.pixels_addr == NULL)
	{
		mlx_destroy_image(mlx.ptr, mlx.img1.ptr);
		mlx_destroy_window(mlx.ptr, mlx.win_ptr);
		mlx_destroy_display(mlx.ptr);
		free(mlx.ptr);
		exit(1);
	}

	// img2
		mlx.img2.ptr = mlx_new_image(mlx.ptr, mlx.window_width, mlx.window_height);
	if (mlx.img2.ptr == NULL)
	{
		mlx_destroy_window(mlx.ptr, mlx.win_ptr);
		mlx_destroy_display(mlx.ptr);
		free(mlx.ptr);
		exit(1);
	}
	mlx.img2.pixels_addr = mlx_get_data_addr(mlx.img2.ptr, &mlx.img2.bits_per_pixel, &mlx.img2.line_length, &mlx.img2.endian);
	if (mlx.img2.pixels_addr == NULL)
	{
		mlx_destroy_image(mlx.ptr, mlx.img2.ptr);
		mlx_destroy_window(mlx.ptr, mlx.win_ptr);
		mlx_destroy_display(mlx.ptr);
		free(mlx.ptr);
		exit(1);
	}
	
	mlx.current_buffer = 0;

	render_double_buffering(&mlx);

	// mlx_put_image_to_window(mlx.ptr, mlx.win_ptr, mlx.img.ptr, 0, 0);
	// printf("before img2\n");
	// mlx.img2.ptr = mlx_new_image(mlx.ptr, mlx.window_width, mlx.window_height);
	// if (mlx.img2.ptr == NULL)
	// {
	// 	mlx_destroy_window(mlx.ptr, mlx.win_ptr);
	// 	mlx_destroy_display(mlx.ptr);
	// 	free(mlx.ptr);
	// 	exit(1);
	// }
	// mlx.img2.pixels_addr = mlx_get_data_addr(mlx.img2.ptr, &mlx.img2.bits_per_pixel, &mlx.img2.line_length, &mlx.img2.endian);
	// if (mlx.img2.pixels_addr == NULL)XK_Right
	// {
	// 	mlx_destroy_image(mlx.ptr, mlx.img2.ptr);
	// 	mlx_destroy_window(mlx.ptr, mlx.win_ptr);
	// 	mlx_destroy_display(mlx.ptr);
	// 	free(mlx.ptr);
	// 	exit(1);
	// }
	// my_mlx_pixel_put(&mlx.img2, mlx.window_width / 2, mlx.window_height / 2, 0xFFFFFF);
	// mlx_put_image_to_window(mlx.ptr, mlx.win_ptr, mlx.img2.ptr, 0, 0);
	mlx_key_hook(mlx.win_ptr, handle_input, &mlx);
	mlx_mouse_hook(mlx.win_ptr, mouse_hook, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0L, handle_close, &mlx);
	mlx_loop(mlx.ptr);
	// mlx_destroy_image(mlx.ptr, mlx.img.ptr);
	mlx_destroy_window(mlx.ptr, mlx.win_ptr);
	mlx_destroy_display(mlx.ptr);
	free(mlx.ptr);
	return (0);
}
