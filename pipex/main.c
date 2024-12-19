/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:57:35 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/19 11:47:31 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "get_next_line/get_next_line.h"
#include <errno.h>

char **format_argv(char *arg)
{
	char	**splitted_arg;
	char	*command_name;
	char	**command_argv;

	char	*position_of_first_double_quote;
	char	*position_of_last_double_quote;

	char	*position_of_first_single_quote;
	char	*position_of_last_single_quote;

	char	*string_in_double_quotes;
	char	*string_in_single_quotes;

	char	*trimmed_string;

	splitted_arg = ft_split(arg, ' ');

	if (splitted_arg == NULL)
		exit(1);

	command_name = splitted_arg[0];

	if (splitted_arg[1] != NULL)
	{
		position_of_first_double_quote = ft_strchr(arg, '"');
		position_of_last_double_quote = ft_strrchr(arg, '"');

		position_of_first_single_quote = ft_strchr(arg, '\'');
		position_of_last_single_quote = ft_strrchr(arg, '\'');

		string_in_double_quotes = ft_substr(position_of_first_double_quote, 0, position_of_last_double_quote - position_of_first_double_quote + 1);

		string_in_single_quotes = ft_substr(position_of_first_single_quote, 0, position_of_last_single_quote - position_of_first_single_quote + 1);

		if (position_of_first_double_quote != NULL && position_of_first_single_quote != NULL)
		{
			//! '""'
			if (position_of_first_double_quote > position_of_first_single_quote)
			{
				if (position_of_first_single_quote != NULL)
				{
					trimmed_string = ft_strtrim(string_in_single_quotes, "'");
					char *arg[] = { command_name, trimmed_string, NULL };
					return (arg);
				}
			}
			//! "''"
			else if (position_of_first_double_quote < position_of_first_single_quote)
			{
				if (position_of_first_double_quote != NULL)
				{
					trimmed_string = ft_strtrim(string_in_double_quotes, "\"");
					char *arg[] = { command_name, ft_strtrim(string_in_double_quotes, "\""), NULL };
					return (arg);
				}
			}
		}
		else
		{
			//! ""
			if (position_of_first_double_quote != NULL)
			{
				trimmed_string = ft_strtrim(string_in_double_quotes, "\"");
				char *arg[] = { command_name, trimmed_string, NULL };
				return (arg);
			}
			//! ''
			else if (position_of_first_single_quote != NULL)
			{
				trimmed_string = ft_strtrim(string_in_single_quotes, "'");
				char *arg[] = { command_name, trimmed_string, NULL };
				return (arg);
			}
		}
	}
	return (splitted_arg);
}

int main(int argc, char *argv[], char *env[])
{
	int	fd[2];
	int	infile_fd;
	int	outfile_fd;
	char	*infile;
	char	*outfile;
	char	**command1;
	char	**command2;
	int status;

	if (argc < 5)
		exit(EXIT_FAILURE);

	infile = argv[1];
	outfile = argv[4];

	command1 = ft_split(argv[2], ' ');
	command2 = ft_split(argv[3], ' ');

	int		i;
	int		j;
	int		command1_path_counter;
	char	*command1_full_path;
	int		command2_path_counter;
	char	*command2_full_path;

	command1_full_path = "";
	command2_full_path = "";

	i = 0;
	j = 0;
	command1_path_counter = 0;
	command2_path_counter = 0;

	while (env[i] != NULL)
	{
		int	isPathVar = ft_strncmp(ft_split(env[i], '=')[0], "PATH", ft_strlen("PATH")) == 0;
		if (isPathVar)
		{
			char **paths = ft_split(ft_split(env[i], '=')[1], ':');
			while (paths[j] != NULL)
			{
				char *pathWithSlash = ft_strjoin(paths[j], "/");
				char *fullPathCommand1 = ft_strjoin(pathWithSlash, command1[0]);
				char *fullPathCommand2 = ft_strjoin(pathWithSlash, command2[0]);
				if (access(fullPathCommand1, F_OK | X_OK) == 0)
				{
					if (ft_strlen(command1_full_path) == 0)
						command1_full_path = fullPathCommand1;
					command1_path_counter++;
				}
				if (access(fullPathCommand2, F_OK | X_OK) == 0)
				{
					if (ft_strlen(command2_full_path) == 0)
						command2_full_path = fullPathCommand2;
					command2_path_counter++;
				}
				if (command1_path_counter >= 1 && command2_path_counter >= 1)
					break ;
				j++;
			}
		}
		i++;
	}

	command1 = format_argv(argv[2]);
	command2 = format_argv(argv[3]);

	if (pipe(fd) == -1)
	{
		perror("\nError: Could not create a pipe!\n");
		exit(EXIT_FAILURE);
	}

	int	child_run_program1_pid = fork();

	if (child_run_program1_pid == -1)
	{
		perror("\nError: Could not fork child_run_program1_pid!\n");
		exit(EXIT_FAILURE);
	}

	if (child_run_program1_pid == 0)
	{
		//! HANDLE IF COMMAND HAS FULL PATH
		if (ft_strchr(command1[0], '/') != NULL)
			command1_full_path = command1[0];
		infile_fd = open(infile, O_RDONLY);
		if (infile_fd == -1)
			exit(EXIT_FAILURE);
		dup2(infile_fd, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(infile_fd);
		close(fd[0]);
		close(fd[1]);
		execve(command1_full_path, command1, env);
		perror("command not found\n");
		exit(255);
	}

	int child_run_program2_pid = fork();

	if (child_run_program2_pid == -1)
	{
		printf("\nError: Could not fork child_run_program2_pid!\n");
		exit(-1);
	}

	if (child_run_program2_pid == 0)
	{
		//! HANDLE IF COMMAND HAS FULL PATH
		if (ft_strchr(command2[0], '/') != NULL)
			command2_full_path = command2[0];
		close(fd[1]);
		outfile_fd = open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0666);
		if (outfile_fd == -1)
			exit(EXIT_FAILURE);
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile_fd, STDOUT_FILENO);
		close(outfile_fd);
		close(fd[0]);
		execve(command2_full_path, command2, env);
		perror("command not found\n");
		exit(127);
	}

	close(fd[0]);
	close(fd[1]);

	waitpid(child_run_program1_pid, &status, 0);
	waitpid(child_run_program2_pid, &status, 0);

	exit(WEXITSTATUS(status));
}
