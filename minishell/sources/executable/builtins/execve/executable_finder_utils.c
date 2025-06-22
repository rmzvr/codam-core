/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executable_finder_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:43:24 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/25 11:54:10 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd/exec_cmd.h"

void	free_after_get_executable_pathname(
	char ***path_values,
	char **cmd
)
{
	ft_free_double_char_pointer(path_values);
	protected_free(cmd);
}

static int	ft_tokens_lstsize(
	t_options *lst
)
{
	int			size;
	t_options	*curr;

	size = 0;
	curr = lst;
	while (curr != NULL)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}

static char	**tokens_to_argv(
	t_options *opt
)
{
	char		**argv;
	size_t		i;
	size_t		opt_size;
	t_options	*curr;

	opt_size = ft_tokens_lstsize(opt);
	argv = (char **)malloc((opt_size + 1) * sizeof(char *));
	if (argv == NULL)
		return (ft_putendl_fd(MEMERR, STDERR_FILENO), NULL);
	i = 0;
	curr = opt;
	while (curr != NULL)
	{
		argv[i] = ft_strdup((char *)curr->content);
		if (argv[i] == NULL)
		{
			ft_putendl_fd(MEMERR, STDERR_FILENO);
			ft_free_double_char_pointer(&argv);
			return (NULL);
		}
		i++;
		curr = curr->next;
	}
	argv[i] = NULL;
	return (argv);
}

int	is_pathname_correct(
	t_data *data,
	char *pathname
)
{
	int	return_code;

	return_code = 0;
	if (access(pathname, X_OK) == -1)
	{
		return_code = show_executable_error_msg(data);
	}
	return (return_code);
}

int	handle_command_arguments(
	t_options *arguments,
	t_data *data,
	int *builtin_num,
	char **pathname
)
{
	int	return_code;

	if (arguments == NULL)
		return (0);
	return_code = 0;
	data->argv = tokens_to_argv(arguments);
	(*builtin_num) = ft_get_builtin_num(arguments->content);
	if (data->argv == NULL)
		return (EMALLOC);
	if (*data->argv == NULL || **data->argv == '\0')
	{
		ft_dprintf(STDERR_FILENO, "%s: command not found\n", data->argv[0]);
		return (ft_free_double_char_pointer(&data->argv), 126);
	}
	(*pathname) = NULL;
	if ((*builtin_num) == NO_BUILTIN)
	{
		return_code = convert_argv_to_pathname(data, pathname);
		if (return_code != 0)
			return (return_code);
		return_code = is_pathname_correct(data, (*pathname));
		if (return_code != 0)
			free_after_get_executable_pathname(&data->argv, &(*pathname));
	}
	return (return_code);
}
