/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:52:54 by rzvir             #+#    #+#             */
/*   Updated: 2025/07/22 12:59:51 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/string.h"

char	*ft_strjoin_s(char *s1, char *s2)
{
	char	*joined;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		joined = ft_strdup(s2);
	else if (s2 == NULL)
		joined = ft_strdup(s1);
	else
		joined = ft_strjoin(s1, s2);
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
	return (joined);
}
