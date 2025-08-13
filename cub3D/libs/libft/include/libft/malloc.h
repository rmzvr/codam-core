/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   malloc.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 00:00:00 by bamarell      #+#    #+#                 */
/*   Updated: 2025/07/15 17:41:54 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <stddef.h>
# include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
		__attribute__((alloc_size (1, 2)));
void	*ft_realloc(void *ptr, size_t psize, size_t size)
		__attribute__((alloc_size (2, 3)));
void	ft_free2d(void **ptr);
#endif
