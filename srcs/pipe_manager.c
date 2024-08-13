/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 08:15:37 by eonoh             #+#    #+#             */
/*   Updated: 2024/08/13 14:24:43 by eonoh            ###   ########.fr       */
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
	command_vec = ft_split(argv[2], ' ');
	filefd = open(argv[1], O_RDONLY);
	if (filefd < 0)
		error("file open\n");
	dup2(filefd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	close(filefd);
	execve(command, command_vec, env);
	error("execve\n");
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
	if (filefd < 0)
		error("file open\n");
	dup2(pipefd[0], STDIN_FILENO);
	dup2(filefd, STDOUT_FILENO);
	close(pipefd[0]);
	close(filefd);
	execve(command, command_vec, env);
	error("execve\n");
}

void	pipe_io()
{
	
}
