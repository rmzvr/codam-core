/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:41:40 by rmzvr             #+#    #+#             */
/*   Updated: 2024/10/09 16:11:06 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
	{
		return (1);
	}
	return (0);
}

/* int	main(void)
{
	// 1. Test with a lowercase alphabetic character
	char ch1 = 'a';
	printf("1. Lowercase alphabetic character\n");
	printf("Character: %c\n", ch1);
	printf("Original isalnum: %d\n", isalnum(ch1));
	printf("ft_isalnum: %d\n\n", ft_isalnum(ch1));

	// 2. Test with an uppercase alphabetic character
	char ch2 = 'Z';
	printf("2. Uppercase alphabetic character\n");
	printf("Character: %c\n", ch2);
	printf("Original isalnum: %d\n", isalnum(ch2));
	printf("ft_isalnum: %d\n\n", ft_isalnum(ch2));

	// 3. Test with a digit
	char ch3 = '5';
	printf("3. Digit character\n");
	printf("Character: %c\n", ch3);
	printf("Original isalnum: %d\n", isalnum(ch3));
	printf("ft_isalnum: %d\n\n", ft_isalnum(ch3));

	// 4. Test with a non-alphanumeric character (symbol)
	char ch4 = '#';
	printf("4. Non-alphanumeric character (symbol)\n");
	printf("Character: %c\n", ch4);
	printf("Original isalnum: %d\n", isalnum(ch4));
	printf("ft_isalnum: %d\n\n", ft_isalnum(ch4));

	// 5. Test with a whitespace character
	char ch5 = ' ';
	printf("5. Whitespace character\n");
	printf("Character: '%c'\n", ch5);
	printf("Original isalnum: %d\n", isalnum(ch5));
	printf("ft_isalnum: %d\n\n", ft_isalnum(ch5));

	// 6. Test with the null character
	char ch6 = '\0';
	printf("6. Null character\n");
	printf("Character: '\\0'\n");
	printf("Original isalnum: %d\n", isalnum(ch6));
	printf("ft_isalnum: %d\n\n", ft_isalnum(ch6));

	// 7. Test with a boundary case (character before '0')
	char ch7 = '/';
	printf("7. Boundary case (before '0')\n");
	printf("Character: %c\n", ch7);
	printf("Original isalnum: %d\n", isalnum(ch7));
	printf("ft_isalnum: %d\n\n", ft_isalnum(ch7));

	// 8. Test with a boundary case (character after '9')
	char ch8 = ':';
	printf("8. Boundary case (after '9')\n");
	printf("Character: %c\n", ch8);
	printf("Original isalnum: %d\n", isalnum(ch8));
	printf("ft_isalnum: %d\n\n", ft_isalnum(ch8));
	return (0);
} */
