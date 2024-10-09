/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:41:40 by rmzvr             #+#    #+#             */
/*   Updated: 2024/10/09 16:06:20 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

/* int	main(void)
{
	// 1. Test with a control character (ASCII value 0)
	char ch1 = '\0';
	printf("1. Control character (ASCII value 0)\n");
	printf("Character: '\\0'\n");
	printf("Original isascii: %d\n", isascii(ch1));
	printf("ft_isascii: %d\n\n", ft_isascii(ch1));

	// 2. Test with a printable character (ASCII value 32 - space)
	char ch2 = ' ';
	printf("2. Printable character (ASCII value 32)\n");
	printf("Character: '%c'\n", ch2);
	printf("Original isascii: %d\n", isascii(ch2));
	printf("ft_isascii: %d\n\n", ft_isascii(ch2));

	// 3. Test with a printable character (ASCII value 65 - 'A')
	char ch3 = 'A';
	printf("3. Printable character (ASCII value 65)\n");
	printf("Character: '%c'\n", ch3);
	printf("Original isascii: %d\n", isascii(ch3));
	printf("ft_isascii: %d\n\n", ft_isascii(ch3));

	// 4. Test with a printable character (ASCII value 122 - 'z')
	char ch4 = 'z';
	printf("4. Printable character (ASCII value 122)\n");
	printf("Character: '%c'\n", ch4);
	printf("Original isascii: %d\n", isascii(ch4));
	printf("ft_isascii: %d\n\n", ft_isascii(ch4));

	// 5. Test with a control character (ASCII value 127 - DEL)
	char ch5 = 127;
	printf("5. Control character (ASCII value 127)\n");
	printf("Character: '%c' (DEL)\n", ch5);
	printf("Original isascii: %d\n", isascii(ch5));
	printf("ft_isascii: %d\n\n", ft_isascii(ch5));

	// 6. Test with a non-ASCII character (ASCII value 128)
	char ch6 = (char)128;
	printf("6. Non-ASCII character (ASCII value 128)\n");
	printf("Character: '%c' (not a valid ASCII)\n", ch6);
	printf("Original isascii: %d\n", isascii(ch6));
	printf("ft_isascii: %d\n\n", ft_isascii(ch6));

	// 7. Test with a non-ASCII character (ASCII value 255)
	char ch7 = (char)255;
	printf("7. Non-ASCII character (ASCII value 255)\n");
	printf("Character: '%c' (not a valid ASCII)\n", ch7);
	printf("Original isascii: %d\n", isascii(ch7));
	printf("ft_isascii: %d\n\n", ft_isascii(ch7));
	return (0);
} */
