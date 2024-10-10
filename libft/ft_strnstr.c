/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:59:45 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/10 11:16:56 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	i = 0;
	j = 0;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	while (big[i] != '\0' && i < len && len > 0)
	{
		if (big[i] == little[j])
		{
			if (j == little_len - 1)
				return ((char *)&(big[i - j]));
			j++;
		}
		else
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	return (NULL);
}

/* char	*strnstr(const char *s, const char *find, size_t slen)
{
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}

int	main(void)
{
	// 1. Basic substring search
	char haystack1[] = "Hello, World!";
	char needle1[] = "World";
	char *result1 = strnstr(haystack1, needle1, sizeof(haystack1));
	char *result1_ft = ft_strnstr(haystack1, needle1, sizeof(haystack1));
	printf("1. Basic substring search\n");
	printf("Original strnstr result: %s\n", result1);  // Expected: "World!"
	printf("ft_strnstr result: %s\n\n", result1_ft);

	// 2. Substring not found
	char haystack2[] = "Hello, World!";
	char needle2[] = "Earth";
	char *result2 = strnstr(haystack2, needle2, sizeof(haystack2));
	char *result2_ft = ft_strnstr(haystack2, needle2, sizeof(haystack2));
	printf("2. Substring not found\n");
	printf("Original strnstr result: %s\n", result2);  // Expected: NULL
	printf("ft_strnstr result: %s\n\n", result2_ft);

	// 3. Needle is empty
	char haystack3[] = "Hello, World!";
	char needle3[] = "";
	char *result3 = strnstr(haystack3, needle3, sizeof(haystack3));
	char *result3_ft = ft_strnstr(haystack3, needle3, sizeof(haystack3));
	printf("3. Needle is empty\n");
	printf("Original strnstr result: %s\n", result3);
	printf("ft_strnstr result: %s\n\n", result3_ft);

	// 4. Haystack is empty
	char haystack4[] = "";
	char needle4[] = "World";
	char *result4 = strnstr(haystack4, needle4, sizeof(haystack4));
	char *result4_ft = ft_strnstr(haystack4, needle4, sizeof(haystack4));
	printf("4. Haystack is empty\n");
	printf("Original strnstr result: %s\n", result4);  // Expected: NULL
	printf("ft_strnstr result: %s\n\n", result4_ft);

	// 5. Haystack length less than needle length
	char haystack5[] = "Hi!";
	char needle5[] = "Hello";
	char *result5 = strnstr(haystack5, needle5, sizeof(haystack5));
	char *result5_ft = ft_strnstr(haystack5, needle5, sizeof(haystack5));
	printf("5. Haystack length less than needle length\n");
	printf("Original strnstr result: %s\n", result5);  // Expected: NULL
	printf("ft_strnstr result: %s\n\n", result5_ft);

	// 6. Needle found at the beginning of haystack
	char haystack6[] = "Hello, World!";
	char needle6[] = "Hello";
	char *result6 = strnstr(haystack6, needle6, sizeof(haystack6));
	char *result6_ft = ft_strnstr(haystack6, needle6, sizeof(haystack6));
	printf("6. Needle found at the beginning of haystack\n");
	printf("Original strnstr result: %s\n", result6);
	printf("ft_strnstr result: %s\n\n", result6_ft);

	// 7. Needle found at the end of haystack
	char haystack7[] = "Hello, World!";
	char needle7[] = "World!";
	char *result7 = strnstr(haystack7, needle7, sizeof(haystack7));
	char *result7_ft = ft_strnstr(haystack7, needle7, sizeof(haystack7));
	printf("7. Needle found at the end of haystack\n");
	printf("Original strnstr result: %s\n", result7);  // Expected: "World!"
	printf("ft_strnstr result: %s\n\n", result7_ft);

	// 8. Needle longer than specified length
	char haystack8[] = "Short haystack";
	char needle8[] = "long needle";
	char *result8 = strnstr(haystack8, needle8, 5);
	char *result8_ft = ft_strnstr(haystack8, needle8, 5);
	printf("8. Needle longer than specified length\n");
	printf("Original strnstr result: %s\n", result8);  // Expected: NULL
	printf("ft_strnstr result: %s\n\n", result8_ft);
	return (0);
} */