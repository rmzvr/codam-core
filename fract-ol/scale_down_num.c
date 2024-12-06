/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_down_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:05:33 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/04 09:31:35 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	scale_down_num(double num, double min_new, double max_new, double max)
{
	return ((max_new - min_new) * num / max + min_new);
}
