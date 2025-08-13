/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cfs.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 00:00:00 by bamarell      #+#    #+#                 */
/*   Updated: 2024/02/02 00:00:00 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTYPE_H
# define CTYPE_H
# include <stddef.h>

int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isalnum(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
int	ft_isspace(int c);
int	ft_islower(int c);
int	ft_isupper(int c);
int	ft_toupper(int c);
int	ft_tolower(int c);
#endif
