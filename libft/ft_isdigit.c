/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:41:40 by rmzvr             #+#    #+#             */
/*   Updated: 2024/10/09 16:04:24 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/* int	main(void)
{
	// 1. Test with a digit '0'
	char ch1 = '0';
	printf("1. Digit '0'\n");
	printf("Character: %c\n", ch1);
	printf("Original isdigit: %d\n", isdigit(ch1));
	printf("ft_isdigit: %d\n\n", ft_isdigit(ch1));

	// 2. Test with a digit '9'
	char ch2 = '9';
	printf("2. Digit '9'\n");
	printf("Character: %c\n", ch2);
	printf("Original isdigit: %d\n", isdigit(ch2));
	printf("ft_isdigit: %d\n\n", ft_isdigit(ch2));

	// 3. Test with a non-digit character (alphabet)
	char ch3 = 'A';
	printf("3. Non-digit character (alphabet)\n");
	printf("Character: %c\n", ch3);
	printf("Original isdigit: %d\n", isdigit(ch3));
	printf("ft_isdigit: %d\n\n", ft_isdigit(ch3));

	// 4. Test with a non-digit character (symbol)
	char ch4 = '#';
	printf("4. Non-digit character (symbol)\n");
	printf("Character: %c\n", ch4);
	printf("Original isdigit: %d\n", isdigit(ch4));
	printf("ft_isdigit: %d\n\n", ft_isdigit(ch4));

	// 5. Test with a whitespace character
	char ch5 = ' ';
	printf("5. Whitespace character\n");
	printf("Character: '%c'\n", ch5);
	printf("Original isdigit: %d\n", isdigit(ch5));
	printf("ft_isdigit: %d\n\n", ft_isdigit(ch5));

	// 6. Test with the null character
	char ch6 = '\0';
	printf("6. Null character\n");
	printf("Character: '\\0'\n");
	printf("Original isdigit: %d\n", isdigit(ch6));
	printf("ft_isdigit: %d\n\n", ft_isdigit(ch6));

	// 7. Test with a boundary case (character before '0')
	char ch7 = '/';
	printf("7. Boundary case (before '0')\n");
	printf("Character: %c\n", ch7);
	printf("Original isdigit: %d\n", isdigit(ch7));
	printf("ft_isdigit: %d\n\n", ft_isdigit(ch7));

	// 8. Test with a boundary case (character after '9')
	char ch8 = ':';
	printf("8. Boundary case (after '9')\n");
	printf("Character: %c\n", ch8);
	printf("Original isdigit: %d\n", isdigit(ch8));
	printf("ft_isdigit: %d\n\n", ft_isdigit(ch8));
	return (0);
} */
