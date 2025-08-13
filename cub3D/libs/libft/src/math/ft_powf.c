/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_powf.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 00:00:00 by bamarell      #+#    #+#                 */
/*   Updated: 2024/02/02 00:00:00 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

float	ft_powf(float base, float exponent)
{
	if (exponent == 0)
		return (1);
	if (exponent == 1)
		return (base);
	return (base * ft_powf(base, exponent - 1));
}
