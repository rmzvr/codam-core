/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 13:10:39 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 12:03:41 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/malloc.h"
#include "libft/string.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	i = 0;
	result = (char *)ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		result[i] = f(i, str[i]);
		++i;
	}
	return (result);
}

/* #include <assert.h>

void	assert_str_eq(char *s1, char *s2)
{
	assert(strcmp(s1, s2) == 0);
}

char	ft_mapper(unsigned int index, char ch)
{
	return (ft_toupper(ch));
}

int	main()
{
	char	*str;
	char	*result;

	str = "hello WOrld I am testING!! (:";
	result = ft_strmapi(str, ft_mapper);
	assert_str_eq(result, "HELLO WORLD I AM TESTING!! (:");
} */
