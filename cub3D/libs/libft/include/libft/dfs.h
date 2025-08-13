/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dfs.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 00:00:00 by bamarell      #+#    #+#                 */
/*   Updated: 2025/07/15 14:32:14 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DFS_H
# define DFS_H
# include <stddef.h>
# include <stdbool.h>

# include "libft/math/vec2.h"
# include "libft/lst.h"

struct s_dfs
{
	int		**visited;
	size_t	width;
	size_t	height;
	t_list	*stack;
};

typedef struct s_dfs	t_dfs;

typedef bool			t_dfs_predicate(void *ptr, t_vec2 position);

t_dfs	*dfs_init(size_t width, size_t height);
bool	dfs_visit(t_dfs *dfs, t_vec2 pos, t_dfs_predicate test, void *ptr);
void	dfs_destroy(t_dfs *dfs);
#endif
