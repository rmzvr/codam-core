/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:28:26 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/09 17:12:24 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*last_p;
	unsigned char	*s1_p;
	unsigned char	*s2_p;

	s1_p = (unsigned char *) s1;
	s2_p = (unsigned char *) s2;
	last_p = s1_p + n;
	while (s1_p != last_p)
	{
		if (*s1_p != *s2_p)
		{
			return (*s1_p - *s2_p);
		}
		s1_p++;
		s2_p++;
	}
	return (0);
}

/* int	main(void)
{
	// 1. Basic comparison of equal memory blocks
	char block1[] = "Hello, World!";
	char block2[] = "Hello, World!";
	int result1 = memcmp(block1, block2, sizeof(block1));
	int result1_ft = ft_memcmp(block1, block2, sizeof(block1));
	printf("1. Basic comparison of equal memory blocks\n");
	printf("Original memcmp result: %d\n", result1);  // Expected: 0 (equal)
	printf("ft_memcmp result: %d\n\n", result1_ft);

	// 2. Comparison of unequal memory blocks (different content)
	char block3[] = "Hello, World!";
	char block4[] = "Hello, World?";
	int result2 = memcmp(block3, block4, sizeof(block3));
	int result2_ft = ft_memcmp(block3, block4, sizeof(block3));
	printf("2. Comparison of unequal memory blocks (different content)\n");
	printf("Original memcmp result: %d\n", result2);
	printf("ft_memcmp result: %d\n\n", result2_ft);

	// 3. Comparison of unequal memory blocks (length)
	char block5[] = "Hello";
	char block6[] = "Hello, World!";
	int result3 = memcmp(block5, block6, sizeof(block5));
	int result3_ft = ft_memcmp(block5, block6, sizeof(block5));
	printf("3. Comparison of unequal memory blocks (length)\n");
	printf("Original memcmp result: %d\n", result3);
	printf("ft_memcmp result: %d\n\n", result3_ft);

	// 4. Comparing empty blocks
	char block7[] = "";
	char block8[] = "";
	int result4 = memcmp(block7, block8, sizeof(block7));
	int result4_ft = ft_memcmp(block7, block8, sizeof(block7));
	printf("4. Comparing empty blocks\n");
	printf("Original memcmp result: %d\n", result4);
	printf("ft_memcmp result: %d\n\n", result4_ft);

	// 5. Comparison of blocks with zero bytes
	char block9[] = "Hello\0World!";
	char block10[] = "Hello\0Everyone!";
	int result5 = memcmp(block9, block10, sizeof(block9));
	int result5_ft = ft_memcmp(block9, block10, sizeof(block9));
	printf("5. Comparison of blocks with zero bytes\n");
	printf("Original memcmp result: %d\n", result5);
	printf("ft_memcmp result: %d\n\n", result5_ft);

	// 6. Compare overlapping blocks (not applicable for memcmp)
	char block11[] = "TestString";
	int result6 = memcmp(block11, block11 + 4, 5);
	int result6_ft = ft_memcmp(block11, block11 + 4, 5);
	printf("6. Compare overlapping blocks\n");
	printf("Original memcmp result: %d\n", result6);
	printf("ft_memcmp result: %d\n\n", result6_ft);

	// 7. Compare with a length of 0 (should be equal)
	int result7 = memcmp(block1, block2, 0);
	int result7_ft = ft_memcmp(block1, block2, 0);
	printf("7. Compare with a length of 0\n");
	printf("Original memcmp result: %d\n", result7);
	printf("ft_memcmp result: %d\n\n", result7_ft);
	return (0);
} */