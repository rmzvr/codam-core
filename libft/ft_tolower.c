/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:42:10 by rmzvr             #+#    #+#             */
/*   Updated: 2024/10/09 16:55:41 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
	{
		return (c + 32);
	}
	return (c);
}

/* int	main(void)
{
	// 1. Test with an uppercase letter 'A'
	char ch1 = 'A';
	printf("1. Uppercase letter 'A'\n");
	printf("Original tolower: %c\n", tolower(ch1));
	printf("ft_tolower: %c\n\n", ft_tolower(ch1));

	// 2. Test with an uppercase letter 'Z'
	char ch2 = 'Z';
	printf("2. Uppercase letter 'Z'\n");
	printf("Original tolower: %c\n", tolower(ch2));
	printf("ft_tolower: %c\n\n", ft_tolower(ch2));

	// 3. Test with a lowercase letter 'a'
	char ch3 = 'a';
	printf("3. Lowercase letter 'a'\n");
	printf("Original tolower: %c\n", tolower(ch3));
	printf("ft_tolower: %c\n\n", ft_tolower(ch3));

	// 4. Test with a non-alphabetic character '1'
	char ch4 = '1';
	printf("4. Non-alphabetic character '1'\n");
	printf("Original tolower: %c\n", tolower(ch4));
	printf("ft_tolower: %c\n\n", ft_tolower(ch4));

	// 5. Test with a non-alphabetic character '@'
	char ch5 = '@';
	printf("5. Non-alphabetic character '@'\n");
	printf("Original tolower: %c\n", tolower(ch5));
	printf("ft_tolower: %c\n\n", ft_tolower(ch5));

	// 6. Test with an uppercase letter 'M'
	char ch6 = 'M';
	printf("6. Uppercase letter 'M'\n");
	printf("Original tolower: %c\n", tolower(ch6));
	printf("ft_tolower: %c\n\n", ft_tolower(ch6));

	// 7. Test with a space character ' '
	char ch7 = ' ';
	printf("7. Space character ' '\n");
	printf("Original tolower: %c\n", tolower(ch7));
	printf("ft_tolower: %c\n\n", ft_tolower(ch7));

	// 8. Test with an uppercase letter with ASCII value greater than 'Z'
	char ch8 = (char)128;  // Non-ASCII character
	printf("8. Non-ASCII character (ASCII value 128)\n");
	printf("Original tolower: %c\n", tolower(ch8));
	printf("ft_tolower: %c\n\n", ft_tolower(ch8));
	return (0);
} */
