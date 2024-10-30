/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:39:35 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/30 11:33:42 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_put_unum(unsigned long n, char *base, size_t base_len);
int	ft_handle_conv_specs(va_list args, char conv_spec, int str_len);
int	ft_handle_char_specs(va_list args, char conv_spec, int str_len);
int	ft_handle_num_specs(va_list args, char conv_spec, int str_len);
int	ft_handle_mem_specs(va_list args, char conv_spec, int str_len);

#endif