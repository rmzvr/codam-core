/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:39:35 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/20 17:18:50 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

int		ft_nbrlen(int n);
int		ft_putunbr(unsigned int i);
int		ft_puthex(unsigned long l, int to_upper);

int		ft_printf(const char *format, ...);

int		ft_printf_c_spec(va_list args, int char_count);
int		ft_printf_s_spec(va_list args, int char_count);
int		ft_printf_percent_spec(int char_count);

int		ft_printf_di_spec(va_list args, int char_count);
int		ft_printf_u_spec(va_list args, int char_count);

int		ft_printf_p_spec(va_list args, int char_count);
int		ft_printf_x_spec(va_list args, int char_count);
int		ft_printf_ux_spec(va_list args, int char_count);

int		ft_handle_char_specs(char conv_spec, va_list args, int char_count);
int		ft_handle_num_specs(char conv_spec, va_list args, int char_count);
int		ft_handle_mem_specs(char conv_spec, va_list args, int char_count);

int		ft_handle_conv_specs(va_list	args, char conv_spec, int char_count);

#endif