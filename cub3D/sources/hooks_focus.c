/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks_focus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/24 11:14:04 by bamarell      #+#    #+#                 */
/*   Updated: 2025/07/24 11:14:05 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_int.h>

#include "state.h"

static int	handle_focus_in(t_game_state *state)
{
	state->mlx.is_focused = true;
	return (0);
}

static int	handle_focus_out(t_game_state *state)
{
	state->mlx.is_focused = false;
	return (0);
}

static int	handle_button_press(int button, int x, int y, t_game_state *state)
{
	(void)button;
	(void)x;
	(void)y;
	state->mlx.is_focused = true;
	return (0);
}

static int	handle_destroy_notify(t_game_state *state)
{
	((t_xvar *)state->mlx.ptr)->end_loop = true;
	return (0);
}

void	initialize_focus_hooks(t_game_state *state)
{
	mlx_hook(state->mlx.win_ptr,
		FocusIn, FocusChangeMask, handle_focus_in, state);
	mlx_hook(state->mlx.win_ptr,
		FocusOut, FocusChangeMask, handle_focus_out, state);
	mlx_hook(state->mlx.win_ptr,
		ButtonPress, ButtonPressMask, handle_button_press, state);
	mlx_hook(state->mlx.win_ptr,
		DestroyNotify, StructureNotifyMask, handle_destroy_notify, state);
}
