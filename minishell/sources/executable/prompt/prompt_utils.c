/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:03:28 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/24 20:33:19 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt/prompt.h"

static long	get_userid_from_tty(void)
{
	const char		*tty;
	struct stat		st;
	long			uid;

	tty = ttyname(STDIN_FILENO);
	if (tty == NULL)
	{
		perror("ttyname");
		return (-1);
	}
	if (stat(tty, &st) == -1)
	{
		perror("stat");
		return (-1);
	}
	uid = st.st_uid;
	return (uid);
}

static int	get_username_from_uid(
	long uid,
	char **username
)
{
	char	*line;
	int		fd;
	int		result;

	fd = get_file_descriptor("/etc/passwd");
	if (fd == -1)
		return (FAIL);
	line = NULL;
	result = assign_line(&line, fd);
	if (result == EMALLOC)
		return (EMALLOC);
	while (line != NULL)
	{
		if (compare_uid(&line, uid) == TRUE)
		{
			result = assign_username(&line, fd, username);
			if (result == EMALLOC)
				return (EMALLOC);
		}
		result = assign_line(&line, fd);
		if (result == EMALLOC)
			return (EMALLOC);
	}
	close(fd);
	return (FAIL);
}

static int	get_hostname(
	char **hostname
)
{
	int		fd;
	char	buffer[PATH_MAX];
	char	*set;
	int		bytes_read;

	(void)hostname;
	set = "\n";
	fd = open("/etc/hostname", O_RDONLY);
	if (fd == -1)
	{
		handle_error_file("/etc/hostname");
		return (FAIL);
	}
	bytes_read = read(fd, buffer, PATH_MAX);
	buffer[bytes_read] = '\0';
	(*hostname) = ft_strtrim(buffer, set);
	if (hostname == NULL)
	{
		close(fd);
		return (EMALLOC);
	}
	close(fd);
	return (OK);
}

static void	hostname_failure_exit(
	char **username,
	char **hostname,
	t_data *data
)
{
	data->last_exit_code = 2;
	if (username != NULL && (*username) != NULL)
	{
		protected_free(username);
	}
	if (hostname != NULL && (*hostname) != NULL)
	{
		protected_free(hostname);
	}
	ft_putendl_fd(MEMERR, STDERR_FILENO);
	ft_exit(data, FALSE);
}

char	*get_user_hostname(
	t_data *data
)
{
	char	*user_hostname;
	char	*username;
	char	*hostname;
	int		result;
	long	uid;

	username = NULL;
	uid = get_userid_from_tty();
	result = get_username_from_uid(uid, &username);
	if (result == EMALLOC)
		hostname_failure_exit(NULL, NULL, data);
	if (username == NULL && verify_username(&username, data) == EMALLOC)
		hostname_failure_exit(NULL, NULL, data);
	hostname = NULL;
	result = get_hostname(&hostname);
	if (result == EMALLOC)
		hostname_failure_exit(&username, NULL, data);
	user_hostname = protect_strjoin(username, "@");
	if (user_hostname == NULL)
		hostname_failure_exit(NULL, &hostname, data);
	user_hostname = protect_strjoin(user_hostname, hostname);
	if (user_hostname == NULL)
		hostname_failure_exit(NULL, &hostname, data);
	protected_free(&hostname);
	return (user_hostname);
}
