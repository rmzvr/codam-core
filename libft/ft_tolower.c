/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:42:10 by rmzvr             #+#    #+#             */
/*   Updated: 2024/10/07 21:52:02 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

static int	ft_isupperalpha(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (1);
	}
	return (0);
}

int	ft_tolower(int c)
{
	if (ft_isupperalpha(c))
	{
		return (c + 32);
	}
	return (c);
}

int	main(void)
{
	printf("ft_tolower: %c\n", ft_tolower('B'));
	printf("tolower: %c\n", tolower('B'));
	return (0);
}