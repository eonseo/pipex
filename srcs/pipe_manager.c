/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 08:15:37 by eonoh             #+#    #+#             */
/*   Updated: 2024/08/17 23:49:18 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child_process(int *pipefd, char *argv[], char *const env[])
{
	int		filefd;
	char	*command;
	char	**command_vec;

	close(pipefd[0]);
	command = find_path(argv[2], env[0]);
	if (command == NULL)
		error(argv[2], 3);
	command_vec = ft_split(argv[2], ' ');
	filefd = open(argv[1], O_RDONLY);
	if (filefd < 0)
		error(argv[1], 2);
	dup2(filefd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	close(filefd);
	execve(command, command_vec, env);
	error(NULL, 4);
}

void	second_child_process(int *pipefd, char *argv[], char *const env[])
{
	int		filefd;
	char	*command;
	char	**command_vec;

	close(pipefd[1]);
	command = find_path(argv[3], env[0]);
	command_vec = ft_split(argv[3], ' ');
	filefd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (command == NULL)
		error(argv[3], 3);
	if (filefd < 0)
		error(argv[4], 2);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(filefd, STDOUT_FILENO);
	close(pipefd[0]);
	close(filefd);
	execve(command, command_vec, env);
	error(NULL, 4);
}

void	parents_process(int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
	wait(NULL);
	wait(NULL);
}
