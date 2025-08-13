/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 12:36:12 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/10 12:16:36 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/* #include <assert.h>

int	main()
{
	char	i;

	i = '0';
	while (i <= '9')
	{
		assert(ft_isdigit(i) == 1);
		++i;
	}
	assert(ft_isdigit('a') == 0);
} */
