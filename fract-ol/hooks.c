/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:09:17 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/09 13:01:04 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	handle_close(t_mlx *mlx)
{
	cleanup(mlx, 1);
	return (1);
}

static int	handle_keyboard(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
		cleanup(mlx, 1);
	else if (keysym == XK_Up)
		shift_vertical_view(&mlx->curr_set, "up");
	else if (keysym == XK_Down)
		shift_vertical_view(&mlx->curr_set, "down");
	else if (keysym == XK_Left)
		shift_horizontal_view(&mlx->curr_set, "left");
	else if (keysym == XK_Right)
		shift_horizontal_view(&mlx->curr_set, "right");
	render_selected_fractal(mlx->ww / 2, mlx->wh / 2, mlx);
	return (0);
}

static int	handle_mouse(int button, int x, int y, t_mlx *mlx)
{
	double	scale_factor;

	if (button == 1
		&& !ft_strncmp(mlx->curr_set_name, SET_MB_JL, ft_strlen(SET_MB_JL)))
	{
		render_mandelbrot_julia_fractal(mlx, x, y);
	}
	if (button == 4 || button == 5)
	{
		scale_factor = 1.0 / mlx->scale_factor;
		if (button == 5)
		{
			scale_factor = mlx->scale_factor;
		}
		scale_view(x, y, scale_factor, mlx);
		render_selected_fractal(x, y, mlx);
	}
	return (1);
}

static int	handle_mouse_move(int x, int y, t_mlx *mlx)
{
	if (!ft_strncmp(mlx->curr_set_name, SET_MB_JL, ft_strlen(SET_MB_JL)))
	{
		render_mandelbrot_julia_fractal(mlx, x, y);
	}
	return (1);
}

void	bind_control_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, 17, (1L << 3), handle_close, mlx);
	mlx_hook(mlx->win_ptr, 05, (1L << 2), handle_mouse, mlx);
	mlx_hook(mlx->win_ptr, 06, (1L << 8), handle_mouse_move, mlx);
	mlx_hook(mlx->win_ptr, 03, (1L << 1), handle_keyboard, mlx);
}
