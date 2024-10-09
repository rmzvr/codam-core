/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:57:29 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/09 17:11:54 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
	{
		return (src_len);
	}
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/* int	main(void)
{
	// 1. Basic string copy
	char src1[] = "Hello, world!";
	char dst1[20];
	size_t result1 = ft_strlcpy(dst1, src1, sizeof(dst1));
	printf("1. Basic string copy\n");
	printf("Source: \"%s\"\n", src1);
	printf("Original strlcpy: %s\n", (char *)strlcpy(dst1, src1, sizeof(dst1)));
	printf("ft_strlcpy: %s\n", dst1);
	printf("Returned value: %zu\n\n", result1);

	// 2. Source string larger than destination
	char src2[] = "This is a longer string.";
	char dst2[10];
	size_t result2 = ft_strlcpy(dst2, src2, sizeof(dst2));
	printf("2. Source larger than destination\n");
	printf("Source: \"%s\"\n", src2);
	printf("Original strlcpy: %s\n", (char *)strlcpy(dst2, src2, sizeof(dst2)));
	printf("ft_strlcpy: %s\n", dst2);
	printf("Returned value: %zu\n\n", result2);

	// 3. Destination buffer size is 0
	char src3[] = "Buffer size zero";
	char dst3[10];
	size_t result3 = ft_strlcpy(dst3, src3, 0);
	printf("3. Destination buffer size is 0\n");
	printf("Source: \"%s\"\n", src3);
	printf("Original strlcpy: %s\n", (char *)strlcpy(dst3, src3, 0));
	printf("ft_strlcpy: \"%s\"\n", dst3);  // Should be unchanged
	printf("Returned value: %zu\n\n", result3);

	// 4. Source is an empty string
	char src4[] = "";
	char dst4[10];
	size_t result4 = ft_strlcpy(dst4, src4, sizeof(dst4));
	printf("4. Source is an empty string\n");
	printf("Source: \"%s\"\n", src4);
	printf("Original strlcpy: %s\n", (char *)strlcpy(dst4, src4, sizeof(dst4)));
	printf("ft_strlcpy: \"%s\"\n", dst4);
	printf("Returned value: %zu\n\n", result4);

	// 5. Destination buffer size is 1
	char src5[] = "Single character buffer";
	char dst5[1];
	size_t result5 = ft_strlcpy(dst5, src5, sizeof(dst5));
	printf("5. Destination buffer size is 1\n");
	printf("Source: \"%s\"\n", src5);
	printf("Original strlcpy: %s\n", (char *)strlcpy(dst5, src5, sizeof(dst5)));
	printf("ft_strlcpy: \"%s\"\n", dst5);  // Should be empty
	printf("Returned value: %zu\n\n", result5);

	// 6. Copying to a larger buffer
	char src6[] = "Test";
	char dst6[20];
	size_t result6 = ft_strlcpy(dst6, src6, sizeof(dst6));
	printf("6. Copying to a larger buffer\n");
	printf("Source: \"%s\"\n", src6);
	printf("Original strlcpy: %s\n", (char *)strlcpy(dst6, src6, sizeof(dst6)));
	printf("ft_strlcpy: %s\n", dst6);
	printf("Returned value: %zu\n\n", result6);

	// 7. Source and destination are the same buffer
	char src7[] = "Overlap test";
	size_t result7 = ft_strlcpy(src7, src7, sizeof(src7));
	printf("7. Source and destination same buffer\n");
	printf("Source: \"%s\"\n", src7);
	printf("Original strlcpy: %s\n", (char *)strlcpy(src7, src7, sizeof(src7)));
	printf("ft_strlcpy: %s\n", src7);
	printf("Returned value: %zu\n\n", result7);
	return (0);
} */
