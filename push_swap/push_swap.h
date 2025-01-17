/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:13:18 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/17 17:08:45 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_content
{
	int	value;
	int	index;
}	t_content;

void		sa(t_list **stack_a);
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		rra(t_list **stack_a);
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);

void		delete_content(void *content);

void		show_error_and_exit(void);
void		validate_arguments(char **arguments);
void		init_stack(t_list **stack, char **arguments);

void		sort_five(t_list **stack_a, t_list **stack_b);
void		sort_radix(t_list **stack_a, t_list **stack_b);
void		sort_stack(t_list **stack_a, t_list **stack_b);

int			get_index(t_list *stack);
int			get_content(t_list *stack);

void		ft_lst_rotate(t_list **lst);
void		ft_lst_rotate_rev(t_list **lst);
t_list		*ft_lst_prev_last(t_list *lst);

int			find_position(t_list *stack, int value);
t_list		*find_smallest(t_list *stack);
t_list		*find_biggest(t_list *stack, long last_biggest);

#endif