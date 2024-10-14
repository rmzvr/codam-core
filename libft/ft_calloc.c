/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:13:39 by rzvir             #+#    #+#             */
/*   Updated: 2024/10/12 18:16:15 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	full_length;
	char	*arr;

	if (nmemb == 0 || size == 0)
	{
		return (malloc(1));
	}
	full_length = nmemb * size;
	arr = (char *)malloc((full_length) * sizeof(char));
	if (arr == NULL)
	{
		return (NULL);
	}
	ft_bzero(arr, full_length);
	return ((void *)arr);
}
