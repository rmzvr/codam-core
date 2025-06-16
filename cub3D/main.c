/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:12:09 by rmzvr             #+#    #+#             */
/*   Updated: 2025/06/16 17:20:43 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(void)
{
	t_game	game;

	init_project(&game.mlx);
	init_game(&game);
	init_player_position(&game);
	init_player_direction(&game);
	render_frame_with_ray_casting(&game);
	// draw_map(&game);
	// draw_player(&game.mlx.img, &game);
	// init_draw_line(&game);
	mlx_hook(game.mlx.win_ptr, 2, 1L << 0, handle_keyboard, &game);
	mlx_loop(game.mlx.ptr);
}