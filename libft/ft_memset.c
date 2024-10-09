/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:44:59 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/09 17:13:20 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *) s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

/* int	main(void)
{
	// 1. Basic memory setting
	char data1[10];
	ft_memset(data1, 'A', sizeof(data1));  // Set memory to 'A'
	printf("1. Basic memory setting\n");
	printf("Original memset: %s\n", (char *)memset(data1, 'A', sizeof(data1)));
	printf("ft_memset: %s\n\n", data1);

	// 2. Setting memory with a non-zero value
	char data2[10];
	ft_memset(data2, 0x5A, sizeof(data2));  // Set memory to 0x5A
	printf("2. Setting memory with a non-zero value\n");
	printf("Original memset: %s\n", (char *)memset(data2, 0x5A, sizeof(data2)));
	printf("ft_memset: %s\n\n", data2);

	// 3. Setting memory to zero
	char data3[10];
	ft_memset(data3, 0, sizeof(data3));  // Set memory to zero
	printf("3. Setting memory to zero\n");
	printf("Original memset: %s\n", (char *)memset(data3, 0, sizeof(data3)));
	printf("ft_memset: %s\n\n", data3);

	// 4. Setting memory with size smaller than destination
	char data4[10];
	ft_memset(data4, 'B', 5);  // Set only the first 5 bytes to 'B'
	printf("4. Setting memory with size smaller than destination\n");
	printf("Original memset: %s\n", (char *)memset(data4, 'B', 5));
	printf("ft_memset: %s\n\n", data4);

	// 5. Setting memory with size zero
	char data5[10];
	ft_memset(data5, 'C', 0);  // No memory should be set
	printf("5. Setting memory with size zero\n");
	printf("Original memset: %s\n", (char *)memset(data5, 'C', 0));
	printf("ft_memset: %s\n\n", data5);  // Should be uninitialized

	// 6. Large memory block
	char data6[100];
	ft_memset(data6, 'D', sizeof(data6));  // Fill with 'D'
	printf("6. Large memory block\n");
	printf("Original memset: %s\n", (char *)memset(data6, 'D', sizeof(data6)));
	printf("ft_memset: %s\n\n", data6);
	return (0);
} */
