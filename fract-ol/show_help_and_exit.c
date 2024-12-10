/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_help_and_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:30:34 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/09 17:14:06 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_help_and_exit(void)
{
	ft_printf("Usage: ./fractol <set_name> [options]\n\n");
	ft_printf("Available set names:\n");
	ft_printf("  mandelbrot           Display the Mandelbrot set\n");
	ft_printf("  julia                Display the Julia set\n");
	ft_printf("  mandelbrot+julia     Display both Mandelbrot ");
	ft_printf("and Julia sets\n");
	ft_printf("\nOptions:\n");
	ft_printf("  <x> <y>              Julia set constants ");
	ft_printf("(real and imaginary parts)\n");
	ft_printf("\nExamples:\n");
	ft_printf("  ./fractol mandelbrot\n");
	ft_printf("  ./fractol julia 0.285 0.01\n");
	exit(1);
}
