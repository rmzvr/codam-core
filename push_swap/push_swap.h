/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:13:18 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/18 15:11:38 by rzvir            ###   ########.fr       */
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

void	sa(t_list **stack_a);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rra(t_list **stack_a);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

void	delete_node_content(void *content);
void	free_split(char **split);

void	show_error_and_exit(void);
void	validate_arguments(char **arguments, int argc);
void	init_stack(t_list **stack, char **arguments);
void	cleanup(t_list **stack_a, t_list **stack_b, char **argv, int argc);

void	sort_five(t_list **stack_a, t_list **stack_b);
void	sort_radix(t_list **stack_a, t_list **stack_b);
void	sort_stack(t_list **stack_a, t_list **stack_b);

int		get_index(t_list *stack);
int		get_content(t_list *stack);

void	rotate_list(t_list **lst);
void	reverse_rotate_list(t_list **lst);
t_list	*get_second_last_node(t_list *lst);

int		find_position(t_list *stack, int value);
t_list	*find_smallest(t_list *stack);
t_list	*find_biggest(t_list *stack, long last_biggest);

#endif