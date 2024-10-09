/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:57:29 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/09 17:02:07 by rzvir            ###   ########.fr       */
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
    char first[] = "This is a potent1a11y 1ong str1ng";
    char last[] = "a potentially long string";
    int r;

    r = ft_strlcat(first,last,34);

    puts(first);
    printf("Value returned: %d\n",r);
    if( r > 34 )
        puts("String truncated");
    else
        puts("String was fully copied");

    return(0);
} */
