/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:04:03 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/04 09:30:15 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	int				offset;
	unsigned int	*curr_pixel;

	offset = (y * img->ll + x * (img->bpp / 8));
	curr_pixel = (unsigned int *)(img->pixels_addr + offset);
	*curr_pixel = color;
}
