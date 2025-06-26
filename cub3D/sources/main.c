/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:12:09 by rmzvr             #+#    #+#             */
/*   Updated: 2025/06/26 18:15:27 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	game_loop(
	t_game *game
)
{
	double	current_time;
	double	delta_time;

	current_time = get_time();
	delta_time = (current_time - game->last_time);
	game->last_time = current_time;
	game->movement_speed = delta_time * MOVE_TILE_PER_SECOND;
	game->rotation_speed = delta_time * ROTATE_RADIAN_PER_SECOND;
	// printf("rotation_speed: %f\n", game->rotation_speed);
	// printf("FPS: %d\n", (int)(1.0 / delta_time));
	// printf("\e[1;1H\e[2J");
	handle_movement(game);
	render_frame_with_ray_casting(game);
	// draw_map(game);
	// draw_player(game);
	// init_draw_line(game);
	return (0);
}

int	main(void)
{
	t_game	game;

	init_project(&game.mlx);
	init_game(&game);
	init_player(&game);
	mlx_hook(game.mlx.win_ptr, 2, (1L<<0), handle_key_press, &game);
	mlx_hook(game.mlx.win_ptr, 3, (1L<<1), handle_key_release, &game);
	mlx_hook(game.mlx.win_ptr, 6, (1L<<6), handle_mouse_movement, &game);
	mlx_loop_hook(game.mlx.ptr, game_loop, &game);
	mlx_loop(game.mlx.ptr);
}