/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:39:35 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/19 16:20:42 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_printf(const char *format, ...);
void	ft_printf_c(char c);
void	ft_printf_s(char *str);
void	ft_printf_p(void *addr);
void	ft_printf_d(int i);
void	ft_printf_u(unsigned int i);
void	ft_printf_x(unsigned int i);
void	ft_printf_upper_x(unsigned int i);

#endif