/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:57:29 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/08 16:57:53 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

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

int	main(void)
{
    // 1. Basic string copy
    char src1[] = "Hello, world!";
    char dst1[20];
    ft_strlcpy(dst1, src1, sizeof(dst1));
    printf("1. Basic string copy\n src: %s\n dst: %s\n\n", src1, dst1);

    // 2. Source string larger than destination
    char src2[] = "This is alonger string.";
    char dst2[10];
    ft_strlcpy(dst2, src2, sizeof(dst2));  // Only part of src is copied
    printf("2. Source larger than destination\n src: %s\n dst: %s\n\n", src2, dst2);

    // 3. Destination buffer size is 0
    char src3[] = "Buffer size zero";
    char dst3[10];
    ft_strlcpy(dst3, src3, 0);  // No copy should happen, dst should remain unchanged
    printf("3. Destination buffer size is 0\n src: %s\n dst (unchanged): %s\n\n", src3, dst3);

    // 4. Source is an empty string
    char src4[] = "";
    char dst4[10];
    ft_strlcpy(dst4, src4, sizeof(dst4));  // dst should be empty
    printf("4. Source is an empty string\n src: \"%s\"\n dst: \"%s\"\n\n", src4, dst4);

    // 5. Destination buffer size is 1
    char src5[] = "Single character buffer";
    char dst5[1];
    ft_strlcpy(dst5, src5, sizeof(dst5));  // dst should contain only the null terminator
    printf("5. Destination buffer size is 1\n src: %s\n dst: \"%s\"\n\n", src5, dst5);

    // 6. Copying to a larger buffer
    char src6[] = "Test";
    char dst6[20];
    ft_strlcpy(dst6, src6, sizeof(dst6));  // dst should contain the whole source string
    printf("6. Copying to a larger buffer\n src: %s\n dst: %s\n\n", src6, dst6);

    // 7. Source and destination are the same buffer (undefined behavior in some cases)
    char src7[] = "Overlap test";
    ft_strlcpy(src7, src7, sizeof(src7));  // src and dst are the same, might be undefined behavior
    printf("7. Source and destination same buffer\n src: %s\n dst: %s\n\n", src7, src7);
	return (0);
}