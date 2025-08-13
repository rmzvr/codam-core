/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stdlib.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 00:00:00 by bamarell      #+#    #+#                 */
/*   Updated: 2024/02/02 00:00:00 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDLIB_H
# define STDLIB_H

int			ft_atoi(const char *str);
long		ft_atol(const char *str);
long long	ft_atoll(const char *str);
long		ft_strtol(const char *str, char **endptr, int base);
char		*ft_itoa(int n);
char		*ft_ltoa_base(long nb, char *base, int sign);
char		*ft_ultoa_base(unsigned long nb, char *base);
char		*ft_utoa_base(unsigned int nb, char *base);
#endif
