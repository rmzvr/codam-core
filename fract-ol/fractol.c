/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:57:39 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/10 11:09:16 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_valid_set_name(char *curr_set_name)
{
	if (!ft_strncmp(curr_set_name, SET_MB_JL, ft_strlen(SET_MB_JL))
		|| !ft_strncmp(curr_set_name, SET_MB, ft_strlen(SET_MB))
		|| !ft_strncmp(curr_set_name, SET_JL, ft_strlen(SET_JL)))
	{
		return (1);
	}
	return (0);
}

static void	validate_arguments(int argc, char **argv, t_mlx *mlx)
{
	if (ft_strncmp(mlx->curr_set_name, SET_JL, ft_strlen(SET_JL)) == 0)
	{
		if (argc == 4 && is_valid_double(argv[2]) && is_valid_double(argv[3]))
		{
			mlx->j_re = ft_atof(argv[2]);
			mlx->j_im = ft_atof(argv[3]);
		}
		else
		{
			cleanup(mlx, 0);
			show_help_and_exit();
		}
	}
	else if (argc > 2)
	{
		cleanup(mlx, 0);
		show_help_and_exit();
	}
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	mlx.curr_set_name = argv[1];
	if (argc < 2 || argc > 4 || !is_valid_set_name(mlx.curr_set_name))
	{
		show_help_and_exit();
	}
	init_project(&mlx);
	validate_arguments(argc, argv, &mlx);
	render_selected_fractal(WW / 2, WH / 2, &mlx);
	bind_control_hooks(&mlx);
	mlx_loop(mlx.ptr);
	cleanup(&mlx, 0);
	return (0);
}
