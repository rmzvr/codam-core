/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_powl.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 00:00:00 by bamarell      #+#    #+#                 */
/*   Updated: 2024/02/02 00:00:00 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

long double	ft_powl(long double base, long double exponent)
{
	if (exponent == 0)
		return (1);
	if (exponent == 1)
		return (base);
	return (base * ft_powl(base, exponent - 1));
}
