/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:06:00 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/22 13:26:20 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"
#include "drawer.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	set_movement_direction(
	int *direction,
	t_axis *stepping_axis
)
{
	*direction = 1;
	if (stepping_axis->delta < 0)
	{
		*direction = -1;
		stepping_axis->delta = stepping_axis->delta * *direction;
	}
}

static void	set_next_step(
	int direction,
	int *decision_parameter,
	t_axis *driving_axis,
	t_axis *stepping_axis
)
{
	if (*decision_parameter >= 0)
	{
		stepping_axis->start = stepping_axis->start + direction;
		*decision_parameter = *decision_parameter - 2 * driving_axis->delta;
	}
	*decision_parameter = *decision_parameter + 2 * stepping_axis->delta;
	driving_axis->start++;
}

static void	draw_line_along_axis(
	t_axis *driving_axis,
	t_axis *stepping_axis,
	int color,
	t_image *img
)
{
	int	direction;
	int	decision_parameter;

	if (driving_axis->start > driving_axis->end)
	{
		swap(&driving_axis->start, &driving_axis->end);
		swap(&stepping_axis->start, &stepping_axis->end);
	}
	driving_axis->delta = driving_axis->end - driving_axis->start;
	stepping_axis->delta = stepping_axis->end - stepping_axis->start;
	decision_parameter = 0;
	set_movement_direction(&direction, stepping_axis);
	if (driving_axis->delta != 0)
	{
		decision_parameter = 2 * stepping_axis->delta - driving_axis->delta;
		while (driving_axis->start < driving_axis->end)
		{
			put_pixel(
				img, stepping_axis->start, driving_axis->start, color);
			set_next_step(
				direction, &decision_parameter, driving_axis, stepping_axis);
		}
	}
}

void	draw_line(
	t_axis *x_axis,
	t_axis *y_axis,
	int color,
	t_image *img
)
{
	if (abs(x_axis->end - x_axis->start) > abs(y_axis->end - y_axis->start))
	{
		draw_line_along_axis(x_axis, y_axis, color, img);
	}
	else
	{
		draw_line_along_axis(y_axis, x_axis, color, img);
	}
}
