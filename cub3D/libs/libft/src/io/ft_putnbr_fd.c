/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamarell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:47:58 by bamarell          #+#    #+#             */
/*   Updated: 2023/10/03 13:48:05 by bamarell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io.h"
#include "libft/math.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
		ft_putchar_fd('-', fd);
	if (nb > 9 || nb < -9)
		ft_putnbr_fd(ft_abs(nb / 10), fd);
	ft_putchar_fd(ft_abs(nb % 10) + '0', fd);
}

/*int	main()
{
	ft_putnbr_fd(-123, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(123, 1);
}*/
