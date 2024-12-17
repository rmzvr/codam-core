/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:57:35 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/17 18:10:52 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "get_next_line/get_next_line.h"

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
	// printf("Current environment variables:\n");
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

	if (command1_path_counter >= 1 && command2_path_counter >= 1)
	{
		// printf("VALID COMMANDS\n");
		// exit(EXIT_SUCCESS);
	}
	else
	{
		printf("command not found\n");
		exit(EXIT_FAILURE);
	}

	infile = argv[1];
	outfile = argv[4];

	if (pipe(fd) == -1)
	{
		printf("\nError: Could not create a pipe!\n");
		exit(EXIT_FAILURE);
	}

/* 	//! PROCESS FOR CHECK PROGRAMS PATH
	int child_check_path_pid = fork();

	if (child_check_path_pid == -1)
	{
		printf("\nError: Could not fork child_check_path_pid!\n");
		exit(-1);
	}

	if (child_check_path_pid == 0)
	{
		char	*command_type = ft_strjoin("type ", argv[2]);
		int		command_status_fd = open("command_status", O_CREAT | O_TRUNC | O_WRONLY, 0666);
		dup2(command_status_fd, STDERR_FILENO);
		dup2(command_status_fd, STDOUT_FILENO);
		close(command_status_fd);
		close(fd[0]);
		close(fd[1]);
		char *args[] = {"/bin/bash", "-c", command_type, NULL};
		execvpe("/bin/bash", args, env);
	}
	//! */

	// printf("%s\n", command1_full_path);
	// printf("%s\n", command2_full_path);

	//! PROCESS FOR PROGRAM 1

	int	child_run_program1_pid = fork();

	if (child_run_program1_pid == -1)
	{
		printf("\nError: Could not fork child_run_program1_pid!\n");
		exit(-1);
	}

	if (child_run_program1_pid == 0)
	{
		infile_fd = open(infile, O_RDONLY);
		if (infile_fd == -1)
		{
			exit(EXIT_FAILURE);
		}
		dup2(infile_fd, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(infile_fd);
		close(fd[0]);
		close(fd[1]);
		execve(command1_full_path, command1, env);
		exit(EXIT_FAILURE);
	}

	int child_run_program2_pid = fork();

	if (child_run_program2_pid == -1)
	{
		printf("\nError: Could not fork child_run_program2_pid!\n");
		exit(-1);
	}

	if (child_run_program2_pid == 0)
	{
		outfile_fd = open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0666);
		if (outfile_fd == -1)
		{
			exit(EXIT_FAILURE);
		}
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile_fd, STDOUT_FILENO);
		close(outfile_fd);
		close(fd[0]);
		close(fd[1]);
		execve(command2_full_path, command2, env);
	}

	// waitpid(child_run_program2_pid, &status, 0);
	// if (access("command_status", F_OK) == -1)
	// {
	// 	printf("NOT EXIST\n");
	// }
	// else
	// {
	// 	int		command_status_fd = open("command_status", O_RDWR);
	// 	char *str = get_next_line(command_status_fd);
	// 	close(command_status_fd);
	// 	if (ft_strncmp(ft_split(str, ' ')[1], "is", ft_strlen("is")) == 0)
	// 	{
	// 		const char	*path = ft_strtrim(ft_split(str, ' ')[2], "\n");
	// 		outfile_fd = open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0666);
	// 		dup2(fd[0], STDIN_FILENO);
	// 		dup2(outfile_fd, STDOUT_FILENO);
	// 		close(outfile_fd);
	// 		close(fd[0]);
	// 		close(fd[1]);
	// 		// printf("%s\n", cmd[2]);
	// 		execve(path, command2, env);
	// 		// printf("FAIL EXECVE\n");
	// 		// exit(EXIT_FAILURE);
	// 	}
	// 	else
	// 	{
	// 		// printf("EXIT\n");
	// 		unlink("command_status");
	// 		exit(EXIT_FAILURE);
	// 	}
	// }

	close(fd[0]);
	close(fd[1]);

	waitpid(child_run_program1_pid, &status, 0);
	waitpid(child_run_program2_pid, &status, 0);

	exit(WEXITSTATUS(status));
}
