/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:37:28 by rmzvr             #+#    #+#             */
/*   Updated: 2025/04/21 23:38:17 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include "parser/heredoc.h"
#include "ft_boolean.h"

static int	free_temp_file_data(
	t_temp_file_data *temp_file_data,
	t_bool print_error_msg
)
{
	if (temp_file_data->filename != NULL)
	{
		protected_free(&temp_file_data->filename);
	}
	if (temp_file_data->char_index != NULL)
	{
		protected_free(&temp_file_data->char_index);
	}
	if (temp_file_data->fullpath != NULL)
	{
		protected_free(&temp_file_data->fullpath);
	}
	if (print_error_msg)
	{
		return (print_merror_and_return_code(EMALLOC));
	}
	return (OK);
}

static int	get_temp_file_data_filename(
	t_temp_file_data *temp_file_data
)
{
	temp_file_data->char_index = ft_itoa(
			temp_file_data->int_index);
	if (temp_file_data->char_index == NULL)
	{
		return (free_temp_file_data(temp_file_data, FALSE), EMALLOC);
	}
	if (temp_file_data->filename != NULL)
	{
		protected_free(&temp_file_data->filename);
	}
	temp_file_data->filename = ft_strjoin(
			temp_file_data->prefix, temp_file_data->char_index);
	if (temp_file_data->filename == NULL)
	{
		return (free_temp_file_data(temp_file_data, FALSE), EMALLOC);
	}
	return (OK);
}

static int	initialize_temp_file_data(
	t_temp_file_data *temp_file_data
)
{
	temp_file_data->modes = S_IRUSR | S_IWUSR;
	temp_file_data->flags = O_WRONLY | O_CREAT | O_EXCL | O_APPEND;
	temp_file_data->int_index = 0;
	temp_file_data->path = "/tmp/";
	temp_file_data->prefix = "sh-thd-";
	temp_file_data->char_index = NULL;
	temp_file_data->filename = NULL;
	temp_file_data->fullpath = NULL;
	if (get_temp_file_data_filename(temp_file_data) == EMALLOC)
		return (EMALLOC);
	temp_file_data->fullpath = ft_strjoin(
			temp_file_data->path, temp_file_data->filename);
	if (temp_file_data->fullpath == NULL)
	{
		return (free_temp_file_data(temp_file_data, FALSE), EMALLOC);
	}
	return (OK);
}

int	file_manipulation(
	t_executor_data *executor_data
)
{
	if (executor_data->write_fd == -1)
		return (print_ferror_and_return_code(
				"Open write-only fd", strerror(errno), FAIL));
	executor_data->bytes_read = write(executor_data->write_fd,
			executor_data->buffer, strlen(executor_data->buffer));
	if (executor_data->bytes_read == -1)
		return (print_ferror_and_return_code(
				"Write to file", strerror(errno), FAIL));
	executor_data->read_fd = open(executor_data->filepath, O_RDONLY);
	if (executor_data->read_fd == -1)
		return (print_ferror_and_return_code(
				"Open read-only fd", strerror(errno), FAIL));
	if (close(executor_data->write_fd) == -1)
		return (print_ferror_and_return_code(
				"Close write-only fd", strerror(errno), FAIL));
	if (unlink(executor_data->filepath) == -1)
		return (print_ferror_and_return_code(
				"Unlink file", strerror(errno), FAIL));
	return (OK);
}

int	create_temp_heredoc_file(int *fd, char **filepath)
{
	t_temp_file_data	temp_file_data;

	if (initialize_temp_file_data(&temp_file_data) == EMALLOC)
		return (EMALLOC);
	*fd = open(temp_file_data.fullpath,
			temp_file_data.flags, temp_file_data.modes);
	while (*fd < 0)
	{
		temp_file_data.int_index += 1;
		protected_free(&temp_file_data.char_index);
		if (get_temp_file_data_filename(&temp_file_data) == EMALLOC)
			return (EMALLOC);
		protected_free(&temp_file_data.fullpath);
		temp_file_data.fullpath = ft_strjoin(
				temp_file_data.path, temp_file_data.filename);
		if (temp_file_data.fullpath == NULL)
			return (free_temp_file_data(&temp_file_data, FALSE), EMALLOC);
		*fd = open(temp_file_data.fullpath,
				temp_file_data.flags, temp_file_data.modes);
	}
	*filepath = ft_strdup(temp_file_data.fullpath);
	return (free_temp_file_data(&temp_file_data, FALSE));
}
