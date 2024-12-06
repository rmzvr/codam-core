/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:57:39 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/06 16:54:18 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"
#include "string.h"

void	display_usage(void)
{
	printf("Usage: ./fractol <set_name> [options]\n");
	printf("Available set names:\n");
	printf("  mandelbrot           Display the Mandelbrot set\n");
	printf("  julia                Display the Julia set\n");
	printf("  mandelbrot+julia     Display both Mandelbrot and Julia sets\n");
	printf("\nOptions:\n");
	printf("  <x> <y>              Julia set constants (real and imaginary parts)\n");
	printf("  --width=<pixels>     Set window width (default: 800)\n");
	printf("  --height=<pixels>    Set window height (default: 800)\n");
	printf("  --iterations=<n>     Set maximum number of iterations (default: 100)\n");
	printf("  --zoom=<factor>      Set initial zoom level (default: 1.5)\n");
	printf("  --palette=<option>   Choose color palette (options: smooth, psychedelic)\n");
	printf("\nExamples:\n");
	printf("  ./fractol mandelbrot\n");
	printf("  ./fractol julia 0.285 0.01\n");
	printf("  ./fractol mandelbrot+julia --width=1024 --height=768\n");
	printf("  ./fractol mandelbrot --palette=smooth\n");
	printf("  ./fractol julia 0.285 0.01 --palette=psychedelic\n");
	exit(EXIT_FAILURE);
}

void	handle_optional_arguments(t_mlx *mlx, char *curr_arg)
{
	char	*arg_name;
	char	*arg_value;

	arg_name = ft_split(curr_arg, '=')[0];
	if (ft_strlen(curr_arg) == ft_strlen(arg_name))
	{
		display_usage();
		exit(1);
	}
	arg_value = ft_split(curr_arg, '=')[1];
	if (ft_strncmp(arg_name, "--width", ft_strlen(arg_name)) == 0)
		mlx->ww = ft_atoi(arg_value);
	else if (ft_strncmp(arg_name, "--height", ft_strlen(arg_name)) == 0)
		mlx->wh = ft_atoi(arg_value);
	else if (ft_strncmp(arg_name, "--iterations", ft_strlen(arg_name)) == 0)
		mlx->max_iterations = ft_atoi(arg_value);
	else if (ft_strncmp(arg_name, "--zoom", ft_strlen(arg_name)) == 0)
		mlx->scale_factor = atof(arg_value);
	else if (ft_strncmp(arg_name, "--palette", ft_strlen(arg_name)) == 0)
		mlx->palette = arg_value;
	else
	{
		display_usage();
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc < 2)
		display_usage();
	else
	{
		mlx.curr_set_name = argv[1];
		init_data_struct(&mlx);
		if (ft_strncmp(mlx.curr_set_name, "mandelbrot", ft_strlen(mlx.curr_set_name)) == 0 && argc >= 2)
		{
			if (argc > 2)
			{
				int	i;

				i = 2;
				while (i <= argc - 1)
				{
					handle_optional_arguments(&mlx, argv[i]);
					i++;
				}
			}
			init_mlx_window_and_image(&mlx, mlx.curr_set_name);
			init_set(&mlx, mlx.curr_set_name);
			render_mandelbrot_fractal(&mlx);
		}
		else if (ft_strncmp(mlx.curr_set_name, "julia", ft_strlen(mlx.curr_set_name)) == 0 && argc >= 4)
		{
			if (argc > 4)
			{
				int	i;
				i = 4;
				while (i <= argc - 1)
				{
					handle_optional_arguments(&mlx, argv[i]);
					i++;
				}
			}
			//! DO ATOF
			init_mlx_window_and_image(&mlx, mlx.curr_set_name);
			init_set(&mlx, mlx.curr_set_name);
			mlx.j_re = atof(argv[2]);
			mlx.j_im = atof(argv[3]);
			render_julia_fractal(&mlx, mlx.j_re, mlx.j_im);
		}
		else if (ft_strncmp(mlx.curr_set_name, "mandelbrot+julia", ft_strlen(mlx.curr_set_name)) == 0 && argc >= 2)
		{
			if (argc > 2)
			{
				int	i;
				i = 2;
				while (i <= argc - 1)
				{
					handle_optional_arguments(&mlx, argv[i]);
					i++;
				}
			}
			init_mlx_window_and_image(&mlx, mlx.curr_set_name);
			init_set(&mlx, "mandelbrot+julia");
			render_mandelbrot_fractal(&mlx);
			render_mandelbrot_julia_set(&mlx, mlx.ww / 2, mlx.wh / 2);
		}
		else
		{
			display_usage();
			exit(1);
		}
		bind_control_hooks(&mlx);
		mlx_loop(mlx.ptr);
		cleanup(&mlx, 0);
	}
	return (0);
}
