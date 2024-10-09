/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:44:59 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/09 17:08:33 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*char_dest;
	char	*char_src;

	char_dest = (char *) dest;
	char_src = (char *) src;
	if (char_dest < char_src)
	{
		i = 0;
		while (i < n)
		{
			char_dest[i] = char_src[i];
			i++;
		}
	}
	else
	{
		i = n - 1;
		while (i >= 0 && n > i)
		{
			char_dest[i] = char_src[i];
			i--;
		}
	}
	return (dest);
}

/* int	main(void)
{
	// 1. Basic memmove test (no overlap)
	char s1[] = "Hello, World!";
	char d1[20];
	ft_memmove(d1, s1, strlen(s1) + 1);  // Include null terminator
	printf("1. Basic memmove (no overlap)\n");
	printf("Source: \"%s\"\n", s1);
	printf("Original memmove: %s\n", (char *)memmove(d1, s1, strlen(s1) + 1));
	printf("ft_memmove: %s\n\n", d1);

	// 2. Overlapping memory regions (copy forward)
	char overlap1[] = "Hello, World!";
	printf("2. Overlapping memory regions (copy forward)\n");
	ft_memmove(overlap1 + 7, overlap1, 6);  // Copy "Hello " to "World!"
	printf("Original memmove: %s\n", (char *)memmove(overlap1 + 7, overlap1, 6));
	printf("ft_memmove: %s\n\n", overlap1);

	// 3. Overlapping memory regions (copy backward)
	char overlap2[] = "Hello, World!";
	printf("3. Overlapping memory regions (copy backward)\n");
	ft_memmove(overlap2, overlap2 + 7, 6);  // Copy "World!" to the beginning
	printf("Original memmove: %s\n", (char *)memmove(overlap2, overlap2 + 7, 6));
	printf("ft_memmove: %s\n\n", overlap2);

	// 4. Zero length copy
	char src2[] = "Test";
	char dest2[20];
	ft_memmove(dest2, src2, 0);  // No copy should happen
	printf("4. Zero length copy\n");
	printf("Source: \"%s\"\n", src2);
	printf("Original memmove: %s\n", (char *)memmove(dest2, src2, 0));
	printf("ft_memmove: %s\n\n", dest2);  // Should still be uninitialized

	// 5. Copying to the same buffer
	char buf[] = "Buffer test";
	printf("5. Copying to the same buffer\n");
	ft_memmove(buf, buf, strlen(buf) + 1);  // Should do nothing
	printf("Original memmove: %s\n", (char *)memmove(buf, buf, strlen(buf) + 1));
	printf("ft_memmove: %s\n\n", buf);

	// 6. Large buffer
	char src3[1001];
	for (int i = 0; i < 1000; i++) {
		src3[i] = 'A';
	}
	src3[1000] = '\0';  // Null terminate
	char dest3[1001];
	ft_memmove(dest3, src3, sizeof(src3));  // Move large buffer
	printf("6. Large buffer\n");
	printf("Original memmove: %s\n", (char *)memmove(dest3, src3, sizeof(src3)));
	printf("ft_memmove: %s\n\n", dest3);
	return (0);
} */
