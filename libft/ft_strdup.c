/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:07:56 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/09 16:57:52 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*copy;
	int		s_len;

	i = 0;
	s_len = ft_strlen(s);
	copy = (char *)malloc((s_len + 1) * sizeof(char));
	if (copy == NULL)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/* int	main(void)
{
	// 1. Test with a normal string
	char str1[] = "Hello, world!";
	char *dup1 = ft_strdup(str1);
	printf("1. Normal string: \"%s\"\n", str1);
	printf("Original strdup: %s\n", strdup(str1));
	printf("ft_strdup: %s\n\n", dup1);
	free(dup1);  // Free allocated memory

	// 2. Test with an empty string
	char str2[] = "";
	char *dup2 = ft_strdup(str2);
	printf("2. Empty string\n");
	printf("Original strdup: %s\n", strdup(str2));
	printf("ft_strdup: %s\n\n", dup2);
	free(dup2);  // Free allocated memory

	// 3. Test with a string containing spaces
	char str3[] = "   ";
	char *dup3 = ft_strdup(str3);
	printf("3. String with spaces: \"%s\"\n", str3);
	printf("Original strdup: %s\n", strdup(str3));
	printf("ft_strdup: %s\n\n", dup3);
	free(dup3);  // Free allocated memory

	// 4. Test with a string containing special characters
	char str4[] = "!@#$%^&*()";
	char *dup4 = ft_strdup(str4);
	printf("4. String with special characters: \"%s\"\n", str4);
	printf("Original strdup: %s\n", strdup(str4));
	printf("ft_strdup: %s\n\n", dup4);
	free(dup4);  // Free allocated memory

	// 5. Test with a string that includes a newline
	char str5[] = "Hello\nWorld";
	char *dup5 = ft_strdup(str5);
	printf("5. String with newline: \"%s\"\n", str5);
	printf("Original strdup: %s\n", strdup(str5));
	printf("ft_strdup: %s\n\n", dup5);
	free(dup5);  // Free allocated memory

	// 6. Test with a long string
	char str6[] = "This is a long string to test the ft_strdup function.";
	char *dup6 = ft_strdup(str6);
	printf("6. Long string\n");
	printf("Original strdup: %s\n", strdup(str6));
	printf("ft_strdup: %s\n\n", dup6);
	free(dup6);  // Free allocated memory

	// 7. Test with a string containing null characters
	char str7[] = "Hello\0World";
	char *dup7 = ft_strdup(str7);
	printf("7. String with null character: \"%s\"\n", str7);
	printf("Original strdup: %s\n", strdup(str7));
	printf("ft_strdup: %s\n\n", dup7);
	free(dup7);  // Free allocated memory

	// 8. Test with a very long string (1000 characters)
	char str8[1001];
	for (int i = 0; i < 1000; i++) {
		str8[i] = 'A';
	}
	str8[1000] = '\0';  // Null terminate
	char *dup8 = ft_strdup(str8);
	printf("8. Very long string\n");
	printf("Original strdup: %s\n", strdup(str8));
	printf("ft_strdup: %s\n\n", dup8);
	free(dup8);  // Free allocated memory
	return (0);
} */
