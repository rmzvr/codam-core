/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:42:10 by rmzvr             #+#    #+#             */
/*   Updated: 2024/10/07 21:49:19 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

static int	ft_isloweralpha(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	return (0);
}

int	ft_toupper(int c)
{
	if (ft_isloweralpha(c))
	{
		return (c - 32);
	}
	return (c);
}

int	main(void)
{
	printf("ft_toupper: %c\n", ft_toupper('A'));
	printf("toupper: %c\n", toupper('A'));
	return (0);
}