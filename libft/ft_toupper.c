/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:42:10 by rmzvr             #+#    #+#             */
/*   Updated: 2024/10/09 16:55:03 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	return (0);
}

int	ft_toupper(int c)
{
	if (ft_islower(c))
	{
		return (c - 32);
	}
	return (c);
}

/* int	main(void)
{
	// 1. Test with a lowercase letter 'a'
	char ch1 = 'a';
	printf("1. Lowercase letter 'a'\n");
	printf("Original toupper: %c\n", toupper(ch1));
	printf("ft_toupper: %c\n\n", ft_toupper(ch1));

	// 2. Test with a lowercase letter 'z'
	char ch2 = 'z';
	printf("2. Lowercase letter 'z'\n");
	printf("Original toupper: %c\n", toupper(ch2));
	printf("ft_toupper: %c\n\n", ft_toupper(ch2));

	// 3. Test with an uppercase letter 'A'
	char ch3 = 'A';
	printf("3. Uppercase letter 'A'\n");
	printf("Original toupper: %c\n", toupper(ch3));
	printf("ft_toupper: %c\n\n", ft_toupper(ch3));

	// 4. Test with a non-alphabetic character '1'
	char ch4 = '1';
	printf("4. Non-alphabetic character '1'\n");
	printf("Original toupper: %c\n", toupper(ch4));
	printf("ft_toupper: %c\n\n", ft_toupper(ch4));

	// 5. Test with a non-alphabetic character '@'
	char ch5 = '@';
	printf("5. Non-alphabetic character '@'\n");
	printf("Original toupper: %c\n", toupper(ch5));
	printf("ft_toupper: %c\n\n", ft_toupper(ch5));

	// 6. Test with a lowercase letter 'm'
	char ch6 = 'm';
	printf("6. Lowercase letter 'm'\n");
	printf("Original toupper: %c\n", toupper(ch6));
	printf("ft_toupper: %c\n\n", ft_toupper(ch6));

	// 7. Test with a space character ' '
	char ch7 = ' ';
	printf("7. Space character ' '\n");
	printf("Original toupper: %c\n", toupper(ch7));
	printf("ft_toupper: %c\n\n", ft_toupper(ch7));

	// 8. Test with a lowercase letter with ASCII value greater than 'z'
	char ch8 = (char)128;  // Non-ASCII character
	printf("8. Non-ASCII character (ASCII value 128)\n");
	printf("Original toupper: %c\n", toupper(ch8));
	printf("ft_toupper: %c\n\n", ft_toupper(ch8));

	return (0);
} */
