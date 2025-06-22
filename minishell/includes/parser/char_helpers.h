/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_helpers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:08:41 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 23:43:36 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_HELPERS_H
# define CHAR_HELPERS_H

int	is_delimiter(char c);
int	is_valid_char(char c);
int	is_redirection(char c);
int	is_metacharacter(char c);
int	is_null_terminator(char c);

#endif