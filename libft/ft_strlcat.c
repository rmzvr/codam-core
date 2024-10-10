/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:57:29 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/10 12:31:57 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	limit;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
	{
		return (size + src_len);
	}
	limit = size - dst_len - 1;
	while (src[i] != '\0' && i < limit && 0 < limit)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/* int main()
{
	char dest1[10] = "a";
	char dest2[10] = "a";
	ft_strlcat(dest1, "lorem ipsum dolor sit amet", 6);
	strlcat(dest2, "lorem ipsum dolor sit amet", 6);
	printf("%s\n", dest1);
	printf("%s\n", dest2);
	return(0);
} */
