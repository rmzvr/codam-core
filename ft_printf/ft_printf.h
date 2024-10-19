/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:39:35 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/19 17:56:10 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "./libft/libft.h"

int		ft_printf(const char *format, ...);
void	ft_printf_c(char c);
void	ft_printf_s(char *str);
void	ft_printf_p(void *addr);
void	ft_printf_d(int i);
void	ft_printf_u(unsigned int i);
void	ft_printf_x(unsigned int i);
void	ft_printf_upper_x(unsigned int i);

#endif