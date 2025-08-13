/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pow.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/28 13:05:23 by bamarell      #+#    #+#                 */
/*   Updated: 2023/11/28 13:05:47 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow(double base, double exponent)
{
	if (exponent == 0)
		return (1);
	if (exponent == 1)
		return (base);
	return (base * ft_pow(base, exponent - 1));
}
