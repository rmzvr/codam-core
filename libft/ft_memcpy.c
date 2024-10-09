/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:44:59 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/09 17:02:48 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*char_dest;
	char	*char_src;

	i = 0;
	char_dest = (char *) dest;
	char_src = (char *) src;
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}

/* int	main(void)
{
	// 1. Zero-length copy
	char	src[] = "source";
	char	dst[] = "destination";
	ft_memcpy(dst, src, 0); // Copy 0 bytes
	printf("1. Zero-length copy\n%s\n\n", dst);

	// 2. Overlapping regions (src before dst)
	char data[] = "HelloWorld";
	memcpy(data + 2, data - 2, 5); // Copy overlapping memory
	printf("2. Overlapping regions (src before dst)\n%s\n\n", data);
	return (0);
} */
