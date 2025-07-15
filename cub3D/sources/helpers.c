/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:03:35 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/15 12:49:44 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	int		x_offset;
	int		y_offset;
	char	*pixel_address;

	x_offset = x * (data->bytes_per_pixel / 8);
	y_offset = y * data->line_length;
	pixel_address = data->pixels_addr + x_offset + y_offset;
	*(unsigned int *)pixel_address = color;
}
