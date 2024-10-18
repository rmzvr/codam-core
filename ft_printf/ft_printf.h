/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:39:35 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/18 20:59:20 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"

void	ft_printf_c(char c);
void	ft_printf_s(char *str);
void	ft_printf_p(void *addr);
void	ft_printf_d(int i);
void	ft_printf_u(unsigned int i);
void	ft_printf_x(unsigned int i);
void	ft_printf_upper_x(unsigned int i);

#endif