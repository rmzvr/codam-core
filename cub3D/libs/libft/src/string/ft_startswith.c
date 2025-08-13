/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_startswith.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/22 11:53:35 by bamarell      #+#    #+#                 */
/*   Updated: 2023/11/22 11:53:35 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

int	ft_startswith(const char *str, const char *prefix)
{
	return (ft_strncmp(str, prefix, ft_strlen(prefix)) == 0);
}
