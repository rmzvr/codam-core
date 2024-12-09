/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:57:39 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/09 12:32:31 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "string.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc < 2)
		show_help_and_exit();
	else
	{
		mlx.curr_set_name = argv[1];
		if (is_valid_set_name(mlx.curr_set_name))
		{
			init_project(&mlx);
			handle_required_arguments(argc, argv, &mlx);
			handle_optional_arguments(argc, argv, &mlx);
		}
		else
			show_help_and_exit();
		render_selected_fractal(mlx.ww / 2, mlx.wh / 2, &mlx);
		bind_control_hooks(&mlx);
		mlx_loop(mlx.ptr);
		cleanup(&mlx, 0);
	}
	return (0);
}
