/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:41:40 by rmzvr             #+#    #+#             */
/*   Updated: 2024/10/09 16:06:16 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}

/* int	main(void)
{
	// 1. Test with a printable character (ASCII value 32 - space)
	char ch1 = ' ';
	printf("1. Printable character (ASCII value 32)\n");
	printf("Character: '%c'\n", ch1);
	printf("Original isprint: %d\n", isprint(ch1));
	printf("ft_isprint: %d\n\n", ft_isprint(ch1));

	// 2. Test with a printable character (ASCII value 65 - 'A')
	char ch2 = 'A';
	printf("2. Printable character (ASCII value 65)\n");
	printf("Character: '%c'\n", ch2);
	printf("Original isprint: %d\n", isprint(ch2));
	printf("ft_isprint: %d\n\n", ft_isprint(ch2));

	// 3. Test with a printable character (ASCII value 122 - 'z')
	char ch3 = 'z';
	printf("3. Printable character (ASCII value 122)\n");
	printf("Character: '%c'\n", ch3);
	printf("Original isprint: %d\n", isprint(ch3));
	printf("ft_isprint: %d\n\n", ft_isprint(ch3));

	// 4. Test with a non-printable character (ASCII value 0)
	char ch4 = '\0';
	printf("4. Non-printable character (ASCII value 0)\n");
	printf("Character: '\\0'\n");
	printf("Original isprint: %d\n", isprint(ch4));
	printf("ft_isprint: %d\n\n", ft_isprint(ch4));

	// 5. Test with a non-printable character (ASCII value 31)
	char ch5 = 31;  // Control character
	printf("5. Non-printable character (ASCII value 31)\n");
	printf("Character: '%c' (Control)\n", ch5);
	printf("Original isprint: %d\n", isprint(ch5));
	printf("ft_isprint: %d\n\n", ft_isprint(ch5));

	// 6. Test with a non-printable character (ASCII value 127 - DEL)
	char ch6 = 127;  // Control character (DEL)
	printf("6. Non-printable character (ASCII value 127)\n");
	printf("Character: '%c' (DEL)\n", ch6);
	printf("Original isprint: %d\n", isprint(ch6));
	printf("ft_isprint: %d\n\n", ft_isprint(ch6));

	// 7. Test with a printable character (ASCII value 126 - tilde)
	char ch7 = '~';
	printf("7. Printable character (ASCII value 126)\n");
	printf("Character: '%c'\n", ch7);
	printf("Original isprint: %d\n", isprint(ch7));
	printf("ft_isprint: %d\n\n", ft_isprint(ch7));

	// 8. Test with a non-printable character (ASCII value 128 - outside ASCII)
	char ch8 = (char)128;  // Non-ASCII character
	printf("8. Non-printable character (ASCII value 128)\n");
	printf("Character: '%c' (not a valid ASCII)\n", ch8);
	printf("Original isprint: %d\n", isprint(ch8));
	printf("ft_isprint: %d\n\n", ft_isprint(ch8));
	return (0);
} */
