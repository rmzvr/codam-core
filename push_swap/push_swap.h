/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:13:18 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/02 14:33:13 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

void	rotate(char *operation, t_list **stack_a, t_list **stack_b);
void	rotate_rev(char *operation, t_list **stack_a, t_list **stack_b);
void	swap(char *operation, t_list **stack_a, t_list **stack_b);
void	push(char *operation, t_list **stack_a, t_list **stack_b);
void	pr(void *c);
void	dl(void *c);
void	show_error_and_exit();
void	validate_arguments(char **argv);
void	init_stack(t_list **stack, char **argv);

#endif