static int	handle_keyboard(int keysym, t_game *game)
{
	// Rotation angle for left/right turns
	const double ROT_ANGLE = M_PI / 6;

	// Player position as the start of the ray (updated on every key press)
	game->vector_x_start = game->player_position.cell_x + (PLAYER_SIZE / 2);
	game->vector_y_start = game->player_position.cell_y + (PLAYER_SIZE / 2);

	// Calculate delta vector from direction (dir_x, dir_y) - no need for vector_x_end/y_end here
	game->delta_vector_x = game->dir_x;   // UPDATED: Use direction vector directly
	game->delta_vector_y = game->dir_y;

	// Normalize direction vector just in case (floating-point errors)
	double vector_magnitude = sqrt(game->delta_vector_x * game->delta_vector_x + game->delta_vector_y * game->delta_vector_y);
	if (vector_magnitude != 0)
	{
		game->delta_vector_x /= vector_magnitude;
		game->delta_vector_y /= vector_magnitude;
	}

	// Movement keys - update player position shifts
	if (keysym == XK_Escape)
	{
		cleanup(&game->mlx, 1);
	}
	else if (keysym == XK_w)
	{
		game->shiftY -= STEP_SIZE;
		game->player_position.cell_y -= STEP_SIZE;  // UPDATED: Move player position instead of vector ends
	}
	else if (keysym == XK_s)
	{
		game->shiftY += STEP_SIZE;
		game->player_position.cell_y += STEP_SIZE;
	}
	else if (keysym == XK_a)
	{
		game->shiftX -= STEP_SIZE;
		game->player_position.cell_x -= STEP_SIZE;
	}
	else if (keysym == XK_d)
	{
		game->shiftX += STEP_SIZE;
		game->player_position.cell_x += STEP_SIZE;
	}
	else if (keysym == XK_Left)
	{
		// Rotate direction vector left (counterclockwise)
		double old_dir_x = game->dir_x;
		game->dir_x = old_dir_x * cos(-ROT_ANGLE) - game->dir_y * sin(-ROT_ANGLE);
		game->dir_y = old_dir_x * sin(-ROT_ANGLE) + game->dir_y * cos(-ROT_ANGLE);

		// Normalize after rotation to prevent drift
		double len = sqrt(game->dir_x * game->dir_x + game->dir_y * game->dir_y);
		if (len != 0)
		{
			game->dir_x /= len;
			game->dir_y /= len;
		}
	}
	else if (keysym == XK_Right)
	{
		// Rotate direction vector right (clockwise)
		double old_dir_x = game->dir_x;
		game->dir_x = old_dir_x * cos(ROT_ANGLE) - game->dir_y * sin(ROT_ANGLE);
		game->dir_y = old_dir_x * sin(ROT_ANGLE) + game->dir_y * cos(ROT_ANGLE);

		// Normalize after rotation
		double len = sqrt(game->dir_x * game->dir_x + game->dir_y * game->dir_y);
		if (len != 0)
		{
			game->dir_x /= len;
			game->dir_y /= len;
		}
	}

	// Update delta vector from direction again after possible rotation or movement
	game->delta_vector_x = game->dir_x;
	game->delta_vector_y = game->dir_y;

	// Normalize direction vector (again, safety)
	vector_magnitude = sqrt(game->delta_vector_x * game->delta_vector_x + game->delta_vector_y * game->delta_vector_y);
	if (vector_magnitude != 0)
	{
		game->delta_vector_x /= vector_magnitude;
		game->delta_vector_y /= vector_magnitude;
	}

	// Calculate intersections with window borders to find ray length (tmax)
	double tx1 = (game->delta_vector_x != 0) ? (WINDOW_MIN_X - game->vector_x_start) / game->delta_vector_x : -INFINITY;
	double tx2 = (game->delta_vector_x != 0) ? (WINDOW_MAX_X - game->vector_x_start) / game->delta_vector_x : INFINITY;
	double ty1 = (game->delta_vector_y != 0) ? (WINDOW_MIN_Y - game->vector_y_start) / game->delta_vector_y : -INFINITY;
	double ty2 = (game->delta_vector_y != 0) ? (WINDOW_MAX_Y - game->vector_y_start) / game->delta_vector_y : INFINITY;

	if (tx1 > tx2) ft_swap_double(&tx1, &tx2);
	if (ty1 > ty2) ft_swap_double(&ty1, &ty2);

	double tmax = (tx2 < ty2) ? tx2 : ty2;

	if (tmax < 0)
	{
		printf("Ray points backwards or no exit ahead\n");
		// You might want to handle this case properly here
	}

	// Calculate end point of the ray at the border of the window
	game->vector_x_end = game->vector_x_start + game->delta_vector_x * tmax;
	game->vector_y_end = game->vector_y_start + game->delta_vector_y * tmax;

	printf("handle_keyboard -> tmax: %f\n", tmax);

	// Drawing calls (your existing functions)
	draw_map(map, game);
	draw_player(&game->mlx.img, game);
	draw_line(game, game->vector_x_start, game->vector_y_start, game->vector_x_end, game->vector_y_end, 0x000000);

	return (0);
}
