/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:33:29 by rmzvr             #+#    #+#             */
/*   Updated: 2024/10/10 11:14:48 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/* int	main(void)
{
	// 1. Test with a normal string
	char str1[] = "Hello, world!";
	printf("1. Normal string: \"%s\"\n", str1);
	printf("Original strlen: %zu\n", strlen(str1));
	printf("ft_strlen: %zu\n\n", ft_strlen(str1));

	// 2. Test with an empty string
	char str2[] = "";
	printf("2. Empty string\n");
	printf("Original strlen: %zu\n", strlen(str2));
	printf("ft_strlen: %zu\n\n", ft_strlen(str2));

	// 3. Test with a string containing spaces
	char str3[] = "   ";
	printf("3. String with spaces: \"%s\"\n", str3);
	printf("Original strlen: %zu\n", strlen(str3));
	printf("ft_strlen: %zu\n\n", ft_strlen(str3));

	// 4. Test with a string containing special characters
	char str4[] = "!@#$%^&*()";
	printf("4. String with special characters: \"%s\"\n", str4);
	printf("Original strlen: %zu\n", strlen(str4));
	printf("ft_strlen: %zu\n\n", ft_strlen(str4));

	// 5. Test with a string that includes a newline
	char str5[] = "Hello\nWorld";
	printf("5. String with newline: \"%s\"\n", str5);
	printf("Original strlen: %zu\n", strlen(str5));
	printf("ft_strlen: %zu\n\n", ft_strlen(str5));

	// 6. Test with a long string
	char str6[] = "This is a long string to test the ft_strlen function.";
	printf("6. Long string\n");
	printf("Original strlen: %zu\n", strlen(str6));
	printf("ft_strlen: %zu\n\n", ft_strlen(str6));

	// 7. Test with a string containing null characters
	char str7[] = "Hello\0World";
	printf("7. String with null character: \"%s\"\n", str7);
	printf("Original strlen: %zu\n", strlen(str7));
	printf("ft_strlen: %zu\n\n", ft_strlen(str7));

	// 8. Test with a very long string (1000 characters)
	char str8[1001];
	for (int i = 0; i < 1000; i++) {
		str8[i] = 'A';
	}
	str8[1000] = '\0';  // Null terminate
	printf("8. Very long string\n");
	printf("Original strlen: %zu\n", strlen(str8));
	printf("ft_strlen: %zu\n\n", ft_strlen(str8));
	return (0);
} */
