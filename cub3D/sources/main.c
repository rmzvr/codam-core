/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:12:09 by rmzvr             #+#    #+#             */
/*   Updated: 2025/07/15 11:49:15 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	game_loop(
	t_game *game
)
{
	set_time_since_last_frame(&game->time_since_last_frame);
	handle_movement(game);
	render_frame(game);
	draw_map(game);
	return (0);
}

int	main(void)
{
	t_game	game;

	init_project(&game.mlx);
	init_game(&game);
	init_player(&game);
	mlx_hook(game.mlx.win_ptr, 2, (1L << 0), handle_key_press, &game);
	mlx_hook(game.mlx.win_ptr, 3, (1L << 1), handle_key_release, &game);
	mlx_loop_hook(game.mlx.ptr, game_loop, &game);
	mlx_loop(game.mlx.ptr);
}
