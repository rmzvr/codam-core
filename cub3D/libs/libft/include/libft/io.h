/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   io.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 00:00:00 by bamarell      #+#    #+#                 */
/*   Updated: 2024/02/02 00:00:00 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H
# include "libft/io/ft_printf.h"
# include "libft/io/get_next_line.h"

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putpad(int pad, int len);
int		ft_putchar(int c);
#endif
