/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_down_range.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:05:33 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/03 12:14:59 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	scale_down_range(double unscaledNum, double minAllowed, double maxAllowed, double min, double max)
{
	return (maxAllowed - minAllowed) * (unscaledNum - min) / (max - min) + minAllowed;
}
