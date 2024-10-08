/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:44:59 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/08 14:54:42 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	int	i;
	char *str;

	i = 0;
	str = (char *) s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

int	main(void)
{
    // 1. Zero-length set
    char data1[] = "original";
    ft_memset(data1, 'X', 0);  // Set 0 bytes
    printf("1. Zero-length set\n %s\n\n", data1);

    // 2. Setting large blocks of memory
    char large_data[1000000];
    ft_memset(large_data, 0, 1000000);  // Set large block to 0
    printf("2. Setting large blocks of memory\n First byte: %d, Last byte: %d\n\n", large_data[0], large_data[999999]);

    // 3. Setting memory with a non-zero value
    char data2[10];
    ft_memset(data2, 0x5A, 10);  // Set memory to 0x5A (ASCII 'Z')
    printf("3. Setting memory with a non-zero value\n %s\n\n", data2);

    // 4. Null pointer (This will crash, so it is commented out)
    // ft_memset(NULL, 'A', 5);  // Undefined behavior

    // 5. Small buffer
    char data3[4];
    ft_memset(data3, 'X', 4);  // Buffer too small example
    printf("5. Small buffer\n %s\n\n", data3);

    // 6. Setting overlapping memory regions
    char data4[] = "OverlapTest";
    ft_memset(data4 + 3, 'X', 5);  // Overlapping memory
    printf("6. Setting overlapping memory regions\n %s\n\n", data4);

    // 7. Partial setting of data
    char data5[] = "PartialSet";
    memset(data5 + 3, 'X', 4);  // Set part of the memory
    printf("7. Partial setting of data\n %s\n\n", data5);

    // 8. Setting memory to a non-printable character
    char data6[10];
    ft_memset(data6, 0xFF, 10);  // Set all bytes to 0xFF
    printf("8. Setting memory to a non-printable character\n First byte: 0x%X, Last byte: 0x%X\n\n", (unsigned char)data6[0], (unsigned char)data6[9]);

    // 9. Unaligned memory address
    char data7[10];
    ft_memset(data7 + 1, 'X', 5);  // Unaligned memory set
    printf("9. Unaligned memory address\n %s\n\n", data7);
	return (0);
}