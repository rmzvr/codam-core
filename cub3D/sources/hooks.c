/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:43:45 by rmzvr             #+#    #+#             */
/*   Updated: 2025/07/24 14:02:31 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"
#include "drawer.h"
#include "minimap.h"
#include "movement.h"
#include <mlx_int.h>
#include <sys/time.h>

static int	handle_key_press(
	int keycode,
	t_game_state *state
)
{
	if (keycode == XK_Escape)
		((t_xvar *) state->mlx.ptr)->end_loop = 1;
	if (keycode == XK_w)
		state->move.forward = TRUE;
	if (keycode == XK_s)
		state->move.backward = TRUE;
	if (keycode == XK_a)
		state->move.left = TRUE;
	if (keycode == XK_d)
		state->move.right = TRUE;
	if (keycode == XK_Left)
		state->rotate.left = TRUE;
	if (keycode == XK_Right)
		state->rotate.right = TRUE;
	if (keycode == XK_Tab)
		state->mlx.is_focused = FALSE;
	return (0);
}

static int	handle_key_release(
	int keycode,
	t_game_state *state
)
{
	if (keycode == XK_w)
		state->move.forward = FALSE;
	if (keycode == XK_s)
		state->move.backward = FALSE;
	if (keycode == XK_a)
		state->move.left = FALSE;
	if (keycode == XK_d)
		state->move.right = FALSE;
	if (keycode == XK_Left)
		state->rotate.left = FALSE;
	if (keycode == XK_Right)
		state->rotate.right = FALSE;
	return (0);
}

static void	set_time_since_last_frame(
	double *time_since_last_frame
)
{
	struct timeval	tv;
	static double	previous_time;
	double			current_time;

	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec + tv.tv_usec / 1000000.0;
	*time_since_last_frame = current_time - previous_time;
	previous_time = current_time;
}

static int	frame_loop(
	t_game_state *state
)
{
	set_time_since_last_frame(&state->time_since_last_frame);
	handle_movement(
		state->time_since_last_frame,
		&state->player,
		&state->move,
		&state->mlx
		);
	handle_rotation(
		state->time_since_last_frame,
		&state->player,
		&state->rotate,
		&state->mlx
		);
	render_frame(state);
	return (0);
}

void	initialize_hooks(
	t_game_state *state
)
{
	state->mlx.is_focused = true;
	mlx_hook(state->mlx.win_ptr, KeyPress, KeyPressMask,
		handle_key_press, state);
	mlx_hook(state->mlx.win_ptr, KeyRelease, KeyReleaseMask,
		handle_key_release, state);
	initialize_focus_hooks(state);
	mlx_loop_hook(state->mlx.ptr, frame_loop, state);
}
