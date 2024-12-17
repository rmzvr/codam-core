/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:57:35 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/17 15:04:02 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "get_next_line/get_next_line.h"

int main(int argc, char *argv[], char *env[])
{
	int cpid;
	int	fd[2];
	int	infile_fd;
	int	outfile_fd;
	char	*infile;
	char	*outfile;
	char	**command1;
	char	**command2;

	if (argc < 5)
		exit(EXIT_FAILURE);

	infile = argv[1];
	outfile = argv[4];
	command1 = ft_split(argv[2], ' ');
	command2 = ft_split(argv[3], ' ');

	if (pipe(fd) == -1)
	{
		printf("\nError: Could not create a pipe!\n");
		exit(EXIT_FAILURE);
	}
	cpid = fork();

	if (cpid == -1)
	{
		printf("\nError: Could not fork!\n");
		exit(-1);
	}

	if (cpid == 0)
	{
		// if (access(infile, F_OK) == -1)
		// {
		// 	exit(EXIT_FAILURE);
		// }
		infile_fd = open(infile, O_RDONLY);
		dup2(infile_fd, STDIN_FILENO);
		close(infile_fd);
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execvpe(command1[0], command1, env);
		exit(EXIT_FAILURE);
	}
	else
	{
		int c2pid = fork();
		int status;
		if (c2pid == 0)
		{
			// char	*command_type = ft_strjoin("type ", command2[0]);
			char	*is_command;
			int		command_status_fd = open("command_status", O_CREAT | O_TRUNC | O_WRONLY, 0666);
			dup2(command_status_fd, STDERR_FILENO);
			dup2(command_status_fd, STDOUT_FILENO);
			close(command_status_fd);
			close(fd[0]);
			close(fd[1]);
			char *args[] = {"/bin/bash", "-c", "type wc", NULL};
			execvpe("/bin/bash", args, env);
		}
		else
		{
			wait(NULL);
			waitpid(c2pid, &status, 0);
			if (access("command_status", F_OK) == -1)
			{
				printf("NOT EXIST\n");
			}
			else
			{
				int		command_status_fd = open("command_status", O_RDWR);
				char *str = get_next_line(command_status_fd);
				if (ft_strncmp(ft_split(str, ' ')[1], "is", ft_strlen("is")) == 0)
				{
					char *cmd[] = { "/usb/bin/wc", "-w", NULL};
					outfile_fd = open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0666);
					dup2(fd[0], STDIN_FILENO);
					dup2(outfile_fd, STDOUT_FILENO);
					close(outfile_fd);
					close(fd[0]);
					close(fd[1]);
					// printf("%s\n", cmd[2]);
					execve("/usb/bin/wc", cmd, env);
					// printf("%s\n", ft_split(str, ' ')[2]);
					exit(EXIT_FAILURE);
				}
				else
				{
					unlink("command_status");
				}
			}
		}
	}
}
