/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 00:00:00 by bamarell      #+#    #+#                 */
/*   Updated: 2024/02/02 00:00:00 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H
# include <stddef.h>

char		*ft_ltoa_base(long nb, char *base, int sign);
char		*ft_utoa_base(unsigned int nb, char *base);
char		*ft_ultoa_base(unsigned long nb, char *base);
int			ft_abs(int nb);
long		ft_labs(long nb);
double		ft_fabs(double nb);
int			ft_min(int a, int b);
int			ft_max(int a, int b);
double		ft_fmin(double a, double b);
float		ft_fminf(float a, float b);
double		fw_pow(double base, double exponent);
float		fw_powf(float base, float exponent);
long double	fw_powl(long double base, long double exponent);
#endif
