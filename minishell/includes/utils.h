/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:46:39 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/22 16:39:39 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <errno.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "data.h"
# include "libft.h"

//FREE
void	ft_free_double_char_pointer(char ***dp);
void	ft_free_double_int_pointer(int ***argv, size_t size);
void	protected_free(char **string);
void	free_tokens(t_token **tokens);
void	free_options(t_options **options);
void	free_ast(t_child node);
void	cleanup_tree(t_child *tree);

//FORMAT CHECKER
t_bool	ft_check_identifier_format(char *var_val);
t_bool	ft_check_num(const char *str);

//CHAR ARRAY UTILS
void	ft_char_array_swap(char **a, char **b);
size_t	ft_char_array_len(char **argv);
char	**copy_char_array(char **src, size_t src_len);

//VARIABLE UTILS
size_t	get_variable_len(const char *word);
char	*get_variable_name(const char *word, t_bool add_equal_sign);

//STRINGS
char	*protect_strjoin(char *s1, char *s2);
char	*ft_stringtrim(char *s1, char const *set);

//FDS
int		save_and_reset_dup(t_bool do_reset);
void	ft_close_fds(int count_pipes, int **pipes_fd);
void	close_all_heredoc_fds(t_child tree);

//ERROR HANDLER
void	handle_error_file(const char *filename);
void	exit_handle_error_file(char *str, char *error_msg);
void	exit_handle_error(char *error_msg);

int		free_and_return_code(char **value_to_free, int code);
char	*free_and_return_value(char **value_to_free, char *value_to_return);
int		free_tokens_and_return_code(t_token **tokens, int code);

char	*print_qerror_and_return_null(void);
char	*print_merror_and_return_null(void);
char	*print_and_return_null(char *message);

int		print_merror_and_return_code(int code);
int		print_serror_and_return_code(char *message, int code);
int		print_ferror_and_return_code(char *message, char *error, int code);

//UTILS
int		ft_any(char c, char const *set);
int		ft_count_any(char const *s1, char const *set, int to_left);

#endif