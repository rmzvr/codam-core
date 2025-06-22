/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:56:41 by rzvir             #+#    #+#             */
/*   Updated: 2025/04/21 23:14:37 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

int	add_char_to_buffer(char **str, char c)
{
	size_t	str_len;
	char	*tmp_str;

	str_len = ft_strlen(*str);
	tmp_str = malloc(str_len + 2);
	if (tmp_str == NULL)
	{
		return (print_merror_and_return_code(EMALLOC));
	}
	ft_strcpy(tmp_str, *str);
	tmp_str[str_len] = c;
	tmp_str[str_len + 1] = '\0';
	protected_free(str);
	*str = ft_strdup(tmp_str);
	if (*str == NULL)
	{
		protected_free(&tmp_str);
		return (print_merror_and_return_code(EMALLOC));
	}
	protected_free(&tmp_str);
	return (OK);
}

int	clean_buffer(
	char **buffer
)
{
	protected_free(buffer);
	*buffer = ft_strdup("");
	if (*buffer == NULL)
	{
		return (print_merror_and_return_code(EMALLOC));
	}
	return (OK);
}
