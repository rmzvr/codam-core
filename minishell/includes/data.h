/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:58:51 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/25 11:58:52 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "ft_boolean.h"
# include "parser/syntax_tree.h"

# define MEMERR "malloc: cannot allocate memory"
# define EMALLOC -2

typedef enum e_exit_code
{
	OK,
	FAIL,
	CONTINUE,
	BREAK,
}	t_exit_code;

typedef struct s_data
{
	unsigned char	last_exit_code;
	int				count_lines;
	char			**envp;
	char			**argv;
	t_bool			isatty;
	t_bool			leaks;
	t_child			tree;
	t_token			*tokens;
	char			*home;
	char			*user_hostname;
}	t_data;

#endif