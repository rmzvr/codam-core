/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:41:40 by rmzvr             #+#    #+#             */
/*   Updated: 2024/10/09 16:55:34 by rzvir            ###   ########.fr       */
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

static int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}

int	ft_isalpha(int c)
{
	if (ft_islower(c) || ft_isupper(c))
	{
		return (1);
	}
	return (0);
}

/* int	main(void)
{
	// 1. Test with lowercase alphabetic characters
	char ch1 = 'a';
	printf("1. Lowercase alphabetic character\n");
	printf("Character: %c\n", ch1);
	printf("Original isalpha: %d\n", isalpha(ch1));
	printf("ft_isalpha: %d\n\n", ft_isalpha(ch1));

	// 2. Test with uppercase alphabetic characters
	char ch2 = 'Z';
	printf("2. Uppercase alphabetic character\n");
	printf("Character: %c\n", ch2);
	printf("Original isalpha: %d\n", isalpha(ch2));
	printf("ft_isalpha: %d\n\n", ft_isalpha(ch2));

	// 3. Test with a non-alphabetic character (digit)
	char ch3 = '5';
	printf("3. Non-alphabetic character (digit)\n");
	printf("Character: %c\n", ch3);
	printf("Original isalpha: %d\n", isalpha(ch3));
	printf("ft_isalpha: %d\n\n", ft_isalpha(ch3));

	// 4. Test with a non-alphabetic character (symbol)
	char ch4 = '#';
	printf("4. Non-alphabetic character (symbol)\n");
	printf("Character: %c\n", ch4);
	printf("Original isalpha: %d\n", isalpha(ch4));
	printf("ft_isalpha: %d\n\n", ft_isalpha(ch4));

	// 5. Test with a whitespace character
	char ch5 = ' ';
	printf("5. Whitespace character\n");
	printf("Character: '%c'\n", ch5);
	printf("Original isalpha: %d\n", isalpha(ch5));
	printf("ft_isalpha: %d\n\n", ft_isalpha(ch5));

	// 6. Test with the null character
	char ch6 = '\0';
	printf("6. Null character\n");
	printf("Character: '\\0'\n");
	printf("Original isalpha: %d\n", isalpha(ch6));
	printf("ft_isalpha: %d\n\n", ft_isalpha(ch6));

	// 7. Test with a boundary case (character before 'A')
	char ch7 = '@';
	printf("7. Boundary case (before 'A')\n");
	printf("Character: %c\n", ch7);
	printf("Original isalpha: %d\n", isalpha(ch7));
	printf("ft_isalpha: %d\n\n", ft_isalpha(ch7));

	// 8. Test with a boundary case (character after 'z')
	char ch8 = '{';
	printf("8. Boundary case (after 'z')\n");
	printf("Character: %c\n", ch8);
	printf("Original isalpha: %d\n", isalpha(ch8));
	printf("ft_isalpha: %d\n\n", ft_isalpha(ch8));
	return (0);
} */
