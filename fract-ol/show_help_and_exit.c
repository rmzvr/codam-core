/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_help_and_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:30:34 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/08 13:01:25 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_help_and_exit(void)
{
	printf("Usage: ./fractol <set_name> [options]\n\n");
	printf("Available set names:\n");
	printf("  mandelbrot           Display the Mandelbrot set\n");
	printf("  julia                Display the Julia set\n");
	printf("  mandelbrot+julia     Display both Mandelbrot and Julia sets\n");
	printf("\nOptions:\n");
	printf("  <x> <y>              Julia set constants (real and imaginary\n");
	printf("                       parts)\n");
	printf("  --width=<pixels>     Window width (default: 800)\n");
	printf("  --height=<pixels>    Window height (default: 800)\n");
	printf("  --iterations=<n>     Max number of iterations (default: 100)\n");
	printf("  --zoom=<factor>      Initial zoom level (default: 1.5)\n");
	printf("  --palette=<option>   Choose color palette (options: smooth,\n");
	printf("                       psychedelic)\n");
	printf("\nExamples:\n");
	printf("  ./fractol mandelbrot\n");
	printf("  ./fractol julia 0.285 0.01\n");
	printf("  ./fractol mandelbrot+julia --width=1024 --height=768\n");
	printf("  ./fractol mandelbrot --palette=smooth\n");
	printf("  ./fractol julia 0.285 0.01 --palette=psychedelic\n");
	exit(1);
}
