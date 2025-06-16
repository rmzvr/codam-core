/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:03:35 by rzvir             #+#    #+#             */
/*   Updated: 2025/06/16 13:13:16 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->pixels_addr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	get_cell_x_head_addr(int x)
{
	return (x * cellSize);
}

int	get_cell_x_tail_addr(int x)
{
	return (x * cellSize + cellSize - 1);
}

int	get_cell_y_head_addr(int y)
{
	return (y * cellSize);
}

int	get_cell_y_tail_addr(int y)
{
	return (y * cellSize + cellSize - 1);
}

int get_cell_index(int position)
{
	return (position / cellSize);
}
