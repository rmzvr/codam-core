/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:25:21 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/25 11:54:29 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "utils.h"
#include "colors.h"

static void	free_before_exit(
	t_data *data
)
{
	if (data->tree.type.command != NULL || data->tree.type.pipeline != NULL)
	{
		free_ast(data->tree);
		data->tree.type.command = NULL;
	}
	if (data->envp != NULL && *(data->envp) != NULL)
	{
		ft_free_double_char_pointer(&data->envp);
		data->envp = NULL;
	}
	if (data->argv != NULL && *data->argv != NULL)
	{
		ft_free_double_char_pointer(&data->argv);
		data->argv = NULL;
	}
	if (data->home != NULL)
	{
		protected_free(&data->home);
		data->home = NULL;
	}
	if (data->user_hostname != NULL)
	{
		protected_free(&data->user_hostname);
		data->user_hostname = NULL;
	}
}

size_t	get_number_len(long long num)
{
	size_t	len;

	len = 0;
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static void	check_exit_code(
	t_data *data
)
{
	unsigned char	exit_code;
	long long		converted_number;

	converted_number = ft_atoll(data->argv[1]);
	if (get_number_len(converted_number) == ft_strlen(data->argv[1]))
	{
		exit_code = converted_number % 256;
		free_before_exit(data);
		ft_dprintf(STDOUT_FILENO, "exit\n");
		exit(exit_code);
	}
	else
	{
		ft_dprintf(STDOUT_FILENO, "exit\n");
		exit_handle_error_file(data->argv[1], "numeric argument required");
		free_before_exit(data);
		exit(2);
	}
}

int	ft_exit(
	t_data *data,
	t_bool display
)
{
	if (data->argv == NULL
		|| *(data->argv) == NULL || *(data->argv + 1) == NULL)
	{
		if (display)
			ft_dprintf(STDOUT_FILENO, "exit\n");
		return (free_before_exit(data), exit(data->last_exit_code), 0);
	}
	if (ft_check_num(data->argv[1]) == FALSE)
	{
		ft_dprintf(STDOUT_FILENO, "exit\n");
		exit_handle_error_file(data->argv[1], "numeric argument required");
		return (free_before_exit(data), exit(2), 0);
	}
	if (ft_char_array_len(data->argv) > 2)
	{
		errno = E2BIG;
		exit_handle_error("too many arguments");
		return (1);
	}
	check_exit_code(data);
	return (0);
}
