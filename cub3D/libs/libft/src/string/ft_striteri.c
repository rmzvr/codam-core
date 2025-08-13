/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamarell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:15:03 by bamarell          #+#    #+#             */
/*   Updated: 2023/10/03 13:16:44 by bamarell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		f(i, &str[i]);
		++i;
	}
}

/* #include "libft.h"

static void	ft_print_debug(unsigned int index, char *c)
{
	(void)index;
	ft_putchar_fd(*c, 1);
}

int	main()
{
	ft_striteri("Hello", ft_print_debug);
	return (0);
} */
